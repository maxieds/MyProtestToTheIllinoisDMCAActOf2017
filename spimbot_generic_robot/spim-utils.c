/* The SPIMbot software is derived from James Larus's SPIM.  Modifications 
	to SPIM are covered by the following license:

 Copyright © 2004, University of Illinois.  All rights reserved.

 Developed by:  Craig Zilles
                Department of Computer Science
					 University of Illinois at Urbana-Champaign
					 http://www-faculty.cs.uiuc.edu/~zilles/spimbot

 Permission is hereby granted, free of charge, to any person obtaining
 a copy of this software and associated documentation files (the
 "Software"), to deal with the Software without restriction, including
 without limitation the rights to use, copy, modify, merge, publish,
 distribute, sublicense, and/or sell copies of the Software, and to
 permit persons to whom the Software is furnished to do so, subject to
 the following conditions:

 Redistributions of source code must retain the above copyright
 notice, this list of conditions and the following disclaimers.

 Redistributions in binary form must reproduce the above copyright
 notice, this list of conditions and the following disclaimers in the
 documentation and/or other materials provided with the distribution.

 Neither the name of the University of Illinois nor the names of its
 contributors may be used to endorse or promote products derived from
 this Software without specific prior written permission.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 NONINFRINGEMENT.  IN NO EVENT SHALL THE CONTRIBUTORS OR COPYRIGHT
 HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR
 IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS WITH THE
 SOFTWARE. */

/* SPIM S20 MIPS simulator.
   Misc. routines for SPIM.

   Copyright (C) 1990-2003 by James Larus (larus@cs.wisc.edu).
   ALL RIGHTS RESERVED.
   Changes for DOS and Windows versions by David A. Carley (dac@cs.wisc.edu)

   SPIM is distributed under the following conditions:

     You may make copies of SPIM for your own use and modify those copies.

     All copies of SPIM must retain my name and copyright notice.

     You may not sell SPIM or distributed SPIM in conjunction with a
     commerical product or service without the expressed written consent of
     James Larus.

   THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
   IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
   WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
   PURPOSE. */


/* $Header: /usr/local/cvsroot/spimbot/spim-utils.c,v 1.6 2004/11/23 04:15:38 craig Exp $
*/


#include <stdio.h>
#include <ctype.h>
#include <string.h>
#ifdef __STDC__
#include <stdarg.h>
#else
#include <varargs.h>
#endif

#include "spim.h"
#include "reg.h"
#include "inst.h"
#include "spim-utils.h"
#include "data.h"
#include "mem.h"
#include "scanner.h"
#include "parser.h"
#include "y.tab.h"
#include "run.h"
#include "sym-tbl.h"


/* Internal functions: */

#ifdef __STDC__
static mem_addr copy_int_to_stack (reg_image_t & r_image, int n);
static mem_addr copy_str_to_stack (reg_image_t & r_image, char *s);
static void delete_all_breakpoints (void);
#else
static mem_addr copy_int_to_stack ();
static mem_addr copy_str_to_stack ();
static void delete_all_breakpoints ();
#endif

int num_contexts = 0;
int current_image = 0;
void set_current_image(int i) { current_image = i; }

// int exception_occurred;

// mem_addr program_starting_address = 0;

int initial_text_size = TEXT_SIZE;
int initial_data_size = DATA_SIZE;
mem_addr initial_data_limit = DATA_LIMIT;
int initial_stack_size = STACK_SIZE;
mem_addr initial_stack_limit = STACK_LIMIT;
int initial_k_text_size = K_TEXT_SIZE;
int initial_k_data_size = K_DATA_SIZE;
mem_addr initial_k_data_limit = K_DATA_LIMIT;



/* Initialize or reinitialize the state of the machine. */

#ifdef __STDC__
void
initialize_world (int context, char* trap_file)
#else
void
initialize_world (context, trap_file)
	  int context;
	  reg_image_t &r_image;
     char* trap_file;
#endif
{
  reg_image_t &r_image = reg_images[context];
  r_image.context = context;

  /* Allocate the floating point registers */
  if (r_image.FGR == NULL)
    r_image.FPR = (double *) xmalloc (16 * sizeof (double));
  /* Allocate the memory */
  make_memory (context, initial_text_size,
	       //initial_data_size, initial_data_limit,
	       4000000, 4000000,
               initial_stack_size, initial_stack_limit,
	       initial_k_text_size,
	       initial_k_data_size, initial_k_data_limit);
  initialize_registers (r_image);
  // r_image.program_starting_address = 0;
  initialize_symbol_table ();
  k_text_begins_at_point (context, K_TEXT_BOT);
  k_data_begins_at_point (context, K_DATA_BOT);
  data_begins_at_point (context, DATA_BOT);
  text_begins_at_point (context, TEXT_BOT);
  reg_images[context].auto_alignment = 1;

#ifdef DJGPP
  trap_file = (char*)searchpath(trap_file);
#endif

  if (trap_file != NULL)
    {
      int old_bare = bare_machine;
      int old_accept = accept_pseudo_insts;

      bare_machine = 0;		/* Trap handler uses extended machine */
      accept_pseudo_insts = 1;
      if (read_assembly_file (context, trap_file))
		  fatal_error ("Cannot read trap handler: %s\n", trap_file);
      bare_machine = old_bare;
      accept_pseudo_insts = old_accept;
      write_output (message_out, "Loaded: %s\n", trap_file);

      if (!bare_machine) {
		  make_label_global ("main"); /* In case .globl main forgotten */
		  record_label ("main", 0, 0);
      }
    }
  initialize_scanner (stdin);
  delete_all_breakpoints ();
}


#ifdef __STDC__
void
write_startup_message (void)
#else
void
write_startup_message ()
#endif
{
  write_output (message_out, "SPIMbot Copyright 2004 by Craig Zilles (zilles@cs.uiuc.edu)\n");
  write_output (message_out, "University of Illinois at Urbana-Champaign\n");
  write_output (message_out, "SPIM %s\n", SPIM_VERSION);
  write_output (message_out,
		"Copyright 1990-2003 by James R. Larus (larus@cs.wisc.edu).\n");
  write_output (message_out, "All Rights Reserved.\n");
#if defined(DJGPP) || defined(WIN32)
  write_output (message_out, "DOS and Windows ports by David A. Carley (dac@cs.wisc.edu).\n");
  write_output (message_out, "Copyright 1997 by Morgan Kaufmann Publishers, Inc.\n");
#endif
  write_output (message_out, "See the file README for a full copyright notice.\n");
}



#ifdef __STDC__
void
initialize_registers (reg_image_t &r_image)
#else
void
initialize_registers (r_image)
	  reg_image_t &r_image;
#endif
{
  memclr (r_image.FPR, 16 * sizeof (double));
  r_image.FGR = (float *) r_image.FPR;
  r_image.FWR = (int *) r_image.FPR;
  memclr (r_image.R, 32 * sizeof (reg_word));
  r_image.R[29] = STACK_TOP - BYTES_PER_WORD - 4096; /* Initialize $sp */
  r_image.HI = r_image.LO = 0;
  r_image.PC = TEXT_BOT;
  Cause(r_image) = 0;
  EPC(r_image) = 0;
  Status_Reg(r_image) = 0;
  BadVAddr(r_image) = 0;
  Context(r_image) = 0;
  PRId(r_image) = 0;
}


/* Read file NAME, which should contain assembly code. Return zero if
   successful and non-zero otherwise. */

#ifdef __STDC__
int
read_assembly_file (int context, char *name)
#else
int
read_assembly_file (name)
     char *name;
#endif
{
  FILE *file = fopen (name, "rt");

  source_file = 1;
  if (file == NULL)
    {
      error ("Cannot open file: `%s'\n", name);
      return (1);
    }
  else
    {
      initialize_scanner (file);
      initialize_parser (name);

      while (!yyparse ()) ;

      fclose (file);
      flush_local_labels (!parse_error_occurred);
      end_of_assembly_file ();
      return (0);
    }
}


#ifdef __STDC__
mem_addr
starting_address (reg_image_t &r_image)
#else
mem_addr
starting_address (r_image)
	  reg_image_t &r_image;
#endif
{
//   if (r_image.PC == 0)
//     {
//       if (program_starting_address)
// 	return (program_starting_address);
//       else
// 	return (program_starting_address
// 		= find_symbol_address (DEFAULT_RUN_LOCATION));
//     }
//   else
    return (r_image.PC);
}


/* Initialize the SPIM stack with ARGC, ARGV, and ENVP data. */

#ifdef _MSC_VER
#define environ	_environ
#endif

#ifdef __STDC__
void
initialize_run_stack (int argc, char **argv)
#else
void
initialize_run_stack (argc, argv)
     int argc;
     char **argv;
#endif
{
  char **p;
  extern char **environ;
  int i, j = 0, env_j;
  mem_addr addrs[10000];

  /* fixme: eventually run for both or neither */
  int context = 0;
  reg_image_t &r_image = reg_images[context];

  /* Put strings on stack: */
  for (p = environ; *p != '\0'; p++)
    addrs[j++] = copy_str_to_stack (r_image, *p);

  env_j = j;
  for (i = 0; i < argc; i++)
    addrs[j++] = copy_str_to_stack (r_image, argv[i]);

  r_image.R[29] = r_image.R[29] & ~3;		/* Round down to nearest word */
  r_image.R[29] -= BYTES_PER_WORD;	/* First free word on stack */

  r_image.R[29] = r_image.R[29] & ~7;		/* Double-word align stack-pointer*/
  if ((j % 2) != 0)		/* Odd number of arguments */
    {
      r_image.R[29] -= BYTES_PER_WORD;	/* Ensure stack ends up double-word aligned */
    }

  /* Build vectors on stack: */
  copy_int_to_stack (r_image, 0);	/* Null-terminate vector */
  for (i = env_j - 1; i >= 0; i--)
    r_image.R[REG_A2] = copy_int_to_stack (r_image, addrs[i]);

  copy_int_to_stack (r_image, 0);	/* Null-terminate vector */
  for (i = j - 1; i >= env_j; i--)
    r_image.R[REG_A1] = copy_int_to_stack (r_image, addrs[i]);

  r_image.R[REG_A0] = argc;

  SET_MEM_WORD (context, r_image.R[29], argc);	/* Leave argc on stack */
}


#ifdef __STDC__
static mem_addr
copy_str_to_stack (reg_image_t &r_image, char *s)
#else
static mem_addr
copy_str_to_stack (r_image, s)
	  reg_image_t &r_image;
     char *s;
#endif
{
  int i = strlen (s);
  while (i >= 0)
    {
      SET_MEM_BYTE (r_image.context, r_image.R[29], s[i]);
      r_image.R[29] -= 1;
      i -= 1;
    }
  return ((mem_addr) r_image.R[29] + 1); /* Leaves stack pointer byte-aligned!! */
}


#ifdef __STDC__
static mem_addr
copy_int_to_stack (reg_image_t &r_image, int n)
#else
static mem_addr
copy_int_to_stack (r_image, n)
	  reg_image_t &r_image;
     int n;
#endif
{
  SET_MEM_WORD (r_image.context, r_image.R[29], n);
  r_image.R[29] -= BYTES_PER_WORD;
  return ((mem_addr) r_image.R[29] + BYTES_PER_WORD);
}



// {
//   if (cont_bkpt && inst_is_breakpoint (pc))
//     {
//       mem_addr addr = r_image.PC == 0 ? pc : r_image.PC;
// 
//       delete_breakpoint (addr);
//       exception_occurred = 0;
//       run_spim (addr, 1, display);
//       add_breakpoint (addr);
//       steps -= 1;
//       pc = r_image.PC;
//     }
// 
//   exception_occurred = 0;
//   if (!run_spim (pc, steps, display))
//     /* Can't restart program */
//     r_image.PC = 0;
//   if (r_image.exception_occurred && Cause(r_image) == (BKPT_EXCPT << 2))
//     return (1);
//   else
//     return (0);
// }


/* Record of where a breakpoint was placed and the instruction previously
   in memory. */

bkpt *bkpts = NULL;

/* Set a breakpoint at memory location ADDR. */

#ifdef __STDC__
void
add_breakpoint (mem_addr addr)
#else
void
add_breakpoint (addr)
     mem_addr addr;
#endif
{
  bkpt *rec = (bkpt *) xmalloc (sizeof (bkpt));

  rec->next = bkpts;
  rec->addr = addr;

  // if ((rec->inst = set_breakpoint (addr)) != NULL)
  bkpts = rec;
  // else
  //   {
  //     if (exception_occurred)
  // 	error ("Cannot put a breakpoint at address 0x%08x\n", addr);
  //     else
  // 	error ("No instruction to breakpoint at address 0x%08x\n", addr);
  //     free (rec);
  //   }
}


/* Delete all breakpoints at memory location ADDR. */

#ifdef __STDC__
void
delete_breakpoint (mem_addr addr)
#else
void
delete_breakpoint (addr)
     mem_addr addr;
#endif
{
  bkpt *p, *b;
  int deleted_one = 0;

  for (p = NULL, b = bkpts; b != NULL; )
    if (b->addr == addr)
      {
	bkpt *n;

	/* SET_MEM_INST (addr, b->inst); */
	if (p == NULL)
	  bkpts = b->next;
	else
	  p->next = b->next;
	n = b->next;
	free (b);
	b = n;
	deleted_one = 1;
      }
    else
      p = b, b = b->next;
  if (!deleted_one)
    error ("No breakpoint to delete at 0x%08x\n", addr);
}


#ifdef __STDC__
static void
delete_all_breakpoints (void)
#else
static void
delete_all_breakpoints ()
#endif
{
  bkpt *b, *n;

  for (b = bkpts, n = NULL; b != NULL; b = n)
    {
      n = b->next;
      free (b);
    }
  bkpts = NULL;
}


/* List all breakpoints. */

#ifdef __STDC__
void
list_breakpoints (void)
#else
void
list_breakpoints ()
#endif
{
  bkpt *b;

  if (bkpts)
    for (b = bkpts;  b != NULL; b = b->next)
      write_output (message_out, "Breakpoint at 0x%08x\n", b->addr);
  else
    write_output (message_out, "No breakpoints set\n");
}



/* Utility routines */

/* Print the error message then exit. */

#ifndef WIN32
/*VARARGS0*/
#ifdef __STDC__
void
fatal_error (char *fmt, ...)
#else
void
fatal_error (va_alist)
va_dcl
#endif
{
  va_list args;
#ifdef __STDC__
  va_start (args, fmt);
#else
  char *fmt;

  va_start (args);
#endif
  fmt = va_arg (args, char *);

#ifdef NO_VFPRINTF
  _doprnt (fmt, args, stderr);
#else
  vfprintf (stderr, fmt, args);
#endif
  exit (-1);
  /*NOTREACHED*/
}
#endif

/* Return the entry in the hash TABLE of length LENGTH with key STRING.
   Return NULL if no such entry exists. */

#ifdef __STDC__
inst_info *
map_string_to_inst_info (inst_info tbl[], int tbl_len, char *id)
#else
inst_info *
map_string_to_inst_info (tbl, tbl_len, id)
     register inst_info tbl [];
     int tbl_len;
     register char *id;
#endif
{
  register int low = 0;
  register int hi = tbl_len - 1;

  while (low <= hi)
    {
      register int mid = (low + hi) / 2;
      register char *idp = id, *np = tbl[mid].name;

      while (*idp == *np && *idp != '\0') {idp ++; np ++;}

      if (*np == '\0' && *idp == '\0') /* End of both strings */
	return (& tbl[mid]);
      else if (*idp > *np)
	low = mid + 1;
      else
	hi = mid - 1;
    }

  return NULL;
}


/* Return the entry in the hash TABLE of length LENGTH with VALUE1 field NUM.
   Return NULL if no such entry exists. */

#ifdef __STDC__
inst_info *
map_int_to_inst_info (inst_info tbl[], int tbl_len, int num)
#else
inst_info *
map_int_to_inst_info (tbl, tbl_len, num)
     register inst_info tbl [];
     int tbl_len;
     register int num;
#endif
{
  register int low = 0;
  register int hi = tbl_len - 1;

  while (low <= hi)
    {
      register int mid = (low + hi) / 2;

      if (tbl[mid].value1 == num)
	return (&tbl[mid]);
      else if (num > tbl[mid].value1)
	low = mid + 1;
      else
	hi = mid - 1;
    }

  return NULL;
}


#ifdef NEED_VSPRINTF
char *
vsprintf (str, fmt, args)
     char *str, *fmt;
     va_list *args;
{
  FILE _strbuf;

  _strbuf._flag = _IOWRT+_IOSTRG;
  _strbuf._ptr = str;
  _strbuf._cnt = 32767;
  _doprnt(fmt, args, &_strbuf);
  putc('\0', &_strbuf);
  return(str);
}
#endif


#ifdef NEED_STRTOL
#ifdef __STDC__
unsigned long
strtol (const char* str, const char** eptr, int base)
#else
long
strtol (str, eptr, base)
     char *str, **eptr;
     int base;
#endif
{
  long result;

  if (base != 0 && base != 16)
    fatal_error ("SPIM's strtol only works for base 16 (not base %d)\n", base);
  if (*str == '0' && (*(str + 1) == 'x' || *(str + 1) == 'X'))
    {
      str += 2;
      sscanf (str, "%lx", &result);
    }
  else if (base == 16)
    {
      sscanf (str, "%lx", &result);
    }
  else
    {
      sscanf (str, "%ld", &result);
    }
  return (result);
}
#endif

#ifdef NEED_STRTOUL
#ifdef __STDC__
unsigned long
strtoul (const char* str, char** eptr, int base)
#else
unsigned long
strtoul (str, eptr, base)
     char *str, **eptr;
     int base;
#endif
{
  unsigned long result;

  if (base != 0 && base != 16)
    fatal_error ("SPIM's strtoul only works for base 16 (not base %d)\n", base);
  if (*str == '0' && (*(str + 1) == 'x' || *(str + 1) == 'X'))
    {
      str += 2;
      sscanf (str, "%lx", &result);
    }
  else if (base == 16)
    {
      sscanf (str, "%lx", &result);
    }
  else
    {
      sscanf (str, "%ld", &result);
    }
  return (result);
}
#endif


#ifdef __STDC__
char *
str_copy (char *str)
#else
char *
str_copy (str)
     char *str;
#endif
{
  return (strcpy ((char *)xmalloc (strlen (str) + 1), str));
}


#ifdef __STDC__
void *
xmalloc (int size)
#else
char *
xmalloc (size)
int size;
#endif
{
#ifdef __STDC__
  void *x = (void *) malloc (size);
#else
  char *x = (char *) malloc (size);
#endif

  if (x == 0)
    fatal_error ("Out of memory at request for %d bytes.\n");
  return (x);
}


/* Allocate a zero'ed block of storage. */

#ifdef __STDC__
void *
zmalloc (int size)
#else
char *
zmalloc (size)
int size;
#endif
{
#ifdef __STDC__
  void *z = (void *) malloc (size);
#else
  char *z = (char *) malloc (size);
#endif

  if (z == 0)
    fatal_error ("Out of memory at request for %d bytes.\n");

  memclr (z, size);
  return (z);
}
