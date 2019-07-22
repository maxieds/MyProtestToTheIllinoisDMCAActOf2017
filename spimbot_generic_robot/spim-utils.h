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
   Interface to misc. routines for SPIM.

   Copyright (C) 1990-2000 by James Larus (larus@cs.wisc.edu).
   ALL RIGHTS RESERVED.

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


/* $Header: /usr/local/cvsroot/spimbot/spim-utils.h,v 1.5 2004/11/23 04:15:39 craig Exp $
*/

#include "reg.h"

typedef struct bkptrec
{
  mem_addr addr;
  instruction *inst;
  struct bkptrec *next;
} bkpt;

extern bkpt *bkpts;

/* Exported functions: */
void set_current_image(int i);
extern int current_image;

#ifdef __STDC__
void add_breakpoint (mem_addr addr);
char *data_seg_as_string (char *buf, int *max_buf_len, int *string_len);
void delete_breakpoint (mem_addr addr);
void fatal_error (char *fmt, ...);
void initialize_registers (reg_image_t &r_image);
void initialize_run_stack (int argc, char **argv);
void initialize_world (int context, char* trap_file);
char *insts_as_string (mem_addr from, mem_addr to, char *buf, int *max_buf_len, int *string_len);
void list_breakpoints (void);
inst_info *map_int_to_inst_info (inst_info tbl[], int tbl_len, int num);
inst_info *map_string_to_inst_info (inst_info tbl[], int tbl_len, char *id);
char *mem_as_string (mem_addr from, mem_addr to, char *buf, int *max_buf_len, int *string_len);
int read_assembly_file (int context, char *name);
char *registers_as_string (char *buf, int *max_buf_len, int *string_len, int print_gpr_hex, int print_fpr_hex);
mem_addr starting_address (reg_image_t &r_image);
char *str_copy (char *str);
void write_startup_message (void);
void *xmalloc (int);
void *zmalloc (int);
#else
void add_breakpoint ();
char *data_seg_as_string ();
void delete_breakpoint ();
void fatal_error ();
void initialize_registers ();
void initialize_run_stack ();
void initialize_world ();
char *insts_as_string ();
void list_breakpoints ();
inst_info *map_int_to_inst_info ();
inst_info *map_string_to_inst_info ();
char* mem_as_string ();
int read_assembly_file ();
char *registers_as_string ();
mem_addr starting_address ();
char *str_copy ();
void write_startup_message ();
char *xmalloc ();
char *zmalloc ();
#endif
