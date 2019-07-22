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
   Code to create, maintain and access memory.

   Copyright (C) 1990-2003 by James Larus (larus@cs.wisc.edu).
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


/* $Header: /usr/local/cvsroot/spimbot/mem.c,v 1.7 2004/11/23 04:15:35 craig Exp $
*/


#include "spim.h"
#include "reg.h"
#include "inst.h"
#include "spim-utils.h"
#include "mem.h"
//#include "robot.h"
#include "SPIMbot.h"
#include "robotutils.h"

/* Exported Variables: */

reg_word R[32];
reg_word HI, LO;
int HI_present, LO_present;
mem_addr PC, nPC;
double *FPR;			/* Dynamically allocate so overlay */
float *FGR;			/* is possible */
int *FWR;			/* is possible */
int FP_reg_present;		/* Presence bits for FP registers */
int FP_reg_poison;		/* Poison bits for FP registers */
int FP_spec_load;		/* Is register waiting for a speculative ld */
reg_word CpCond[4], CCR[4][32], CPR[4][32];

mem_image_t mem_images[MAX_NUM_ROBOTS];
//vector<mem_image_t> mem_images(10);

// instruction **text_seg;
// int text_modified;		/* Non-zero means text segment was written */
// mem_addr text_top;
// mem_word *data_seg;
// int data_modified;		/* Non-zero means a data segment was written */
// short *data_seg_h;		/* Points to same vector as DATA_SEG */
// BYTE_TYPE *data_seg_b;		/* Ditto */
// mem_addr data_top;
// mem_addr gp_midpoint;		/* Middle of $gp area */
// mem_word *stack_seg;
// short *stack_seg_h;		/* Points to same vector as STACK_SEG */
// BYTE_TYPE *stack_seg_b;		/* Ditto */
// mem_addr stack_bot;
// instruction **k_text_seg;
// mem_addr k_text_top;
// mem_word *k_data_seg;
// short *k_data_seg_h;
// BYTE_TYPE *k_data_seg_b;
// mem_addr k_data_top;

/* Local functions: */

#ifdef __STDC__
static void free_instructions (register instruction **inst, int n);
// static mem_word read_memory_mapped_IO (mem_addr addr);
// static void write_memory_mapped_IO (int context, mem_addr addr, mem_word value);
#else
static void free_instructions ();
// static mem_word read_memory_mapped_IO ();
// static void write_memory_mapped_IO ();
#endif


/* Local variables: */

static int32 data_size_limit, stack_size_limit, k_data_size_limit;



/* Memory is allocated in five chunks:
	text, data, stack, kernel text, and kernel data.

   The arrays are independent and have different semantics.

   text is allocated from 0x400000 up and only contains INSTRUCTIONs.
   It does not expand.

   data is allocated from 0x10000000 up.  It can be extended by the
   SBRK system call.  Programs can only read and write this segment.

   stack grows from 0x7fffefff down.  It is automatically extended.
   Programs can only read and write this segment.

   k_text is like text, except its is allocated from 0x80000000 up.

   k_data is like data, but is allocated from 0x90000000 up.

   Both kernel text and kernel data can only be accessed in kernel mode.
*/

/* The text segments contain pointers to instructions, not actual
   instructions, so they must be allocated large enough to hold as many
   pointers as there would be instructions (the two differ on machines in
   which pointers are not 32 bits long).  The following calculations round
   up in case size is not a multiple of BYTES_PER_WORD.  */

#define BYTES_TO_INST(N) (((N) + BYTES_PER_WORD - 1) / BYTES_PER_WORD * sizeof(instruction*))


#ifdef __STDC__
void
make_memory (int context, int text_size, int data_size, int data_limit,
	     int stack_size, int stack_limit, int k_text_size,
	     int k_data_size, int k_data_limit)
#else
void
make_memory (context, text_size,
	     data_size, data_limit,
	     stack_size, stack_limit,
	     k_text_size,
	     k_data_size, k_data_limit)
	  int context;
     int text_size, data_size, data_limit, stack_size, stack_limit,
       k_text_size, k_data_size, k_data_limit;
#endif
{
  if (data_size <= 65536)
    data_size = 65536;

  mem_image_t &mem_image = mem_images[context];

  if (mem_image.text_seg == NULL)
    mem_image.text_seg = (instruction **) xmalloc (BYTES_TO_INST(text_size));
  else
    {
      free_instructions (mem_image.text_seg, (mem_image.text_top - TEXT_BOT) / BYTES_PER_WORD);
      mem_image.text_seg = (instruction **) realloc (mem_image.text_seg, BYTES_TO_INST(text_size));
    }
  memclr (mem_image.text_seg, BYTES_TO_INST(text_size));
  mem_image.text_top = TEXT_BOT + text_size;

  if (mem_image.data_seg == NULL)
    mem_image.data_seg = (mem_word *) xmalloc (data_size);
  else
    mem_image.data_seg = (mem_word *) realloc (mem_image.data_seg, data_size);
  memclr (mem_image.data_seg, data_size);
  mem_image.data_seg_b = (BYTE_TYPE *) mem_image.data_seg;
  mem_image.data_seg_h = (short *) mem_image.data_seg;
  mem_image.data_top = DATA_BOT + data_size;
  data_size_limit = data_limit;

  if (mem_image.stack_seg == NULL)
    mem_image.stack_seg = (mem_word *) xmalloc (stack_size);
  else
    mem_image.stack_seg = (mem_word *) realloc (mem_image.stack_seg, stack_size);
  memclr (mem_image.stack_seg, stack_size);
  mem_image.stack_seg_b = (BYTE_TYPE *) mem_image.stack_seg;
  mem_image.stack_seg_h = (short *) mem_image.stack_seg;
  mem_image.stack_bot = STACK_TOP - stack_size;
  stack_size_limit = stack_limit;

  if (mem_image.k_text_seg == NULL)
    mem_image.k_text_seg = (instruction **) xmalloc (BYTES_TO_INST(k_text_size));
  else
    {
      free_instructions (mem_image.k_text_seg,
			 (mem_image.k_text_top - K_TEXT_BOT) / BYTES_PER_WORD);
      mem_image.k_text_seg = (instruction **) realloc(mem_image.k_text_seg,
					    BYTES_TO_INST(k_text_size));
    }
  memclr (mem_image.k_text_seg, BYTES_TO_INST(k_text_size));
  mem_image.k_text_top = K_TEXT_BOT + k_text_size;

  if (mem_image.k_data_seg == NULL)
    mem_image.k_data_seg = (mem_word *) xmalloc (k_data_size);
  else
    mem_image.k_data_seg = (mem_word *) realloc (mem_image.k_data_seg, k_data_size);
  memclr (mem_image.k_data_seg, k_data_size);
  mem_image.k_data_seg_b = (BYTE_TYPE *) mem_image.k_data_seg;
  mem_image.k_data_seg_h = (short *) mem_image.k_data_seg;
  mem_image.k_data_top = K_DATA_BOT + k_data_size;
  k_data_size_limit = k_data_limit;

  mem_image.text_modified = 1;
  mem_image.data_modified = 1;

  // generic robot mmappedIO addrs:
  //mem_image.CUR_MMIO_ADDR = 0xffff0000;
  
}


/* Free the storage used by the old instructions in memory. */

#ifdef __STDC__
static void
free_instructions (register instruction **inst, int n)
#else
static void
free_instructions (inst, n)
     register instruction **inst;
     int n;
#endif
{
  for ( ; n > 0; n --, inst ++)
    if (*inst)
      free_inst (*inst);
}


/* Expand the data segment by adding N bytes. */

#ifdef __STDC__
void
expand_data (int context, int addl_bytes)
#else
void
expand_data (addl_bytes)
     int addl_bytes;
#endif
{
  mem_image_t &mem_image = mem_images[context];
  int old_size = mem_image.data_top - DATA_BOT;
  int new_size = old_size + addl_bytes;
  register BYTE_TYPE *p;

  if (addl_bytes < 0 || (source_file && new_size > data_size_limit))
    {
      error ("Can't expand data segment by %d bytes to %d bytes\n",
	     addl_bytes, new_size);
      run_error ("Use -ldata # with # > %d\n", new_size);
    }
  mem_image.data_seg = (mem_word *) realloc (mem_image.data_seg, new_size);
  if (mem_image.data_seg == NULL)
    fatal_error ("realloc failed in expand_data\n");

  mem_image.data_seg_b = (BYTE_TYPE *) mem_image.data_seg;
  mem_image.data_seg_h = (short *) mem_image.data_seg;
  mem_image.data_top += addl_bytes;

  /* Zero new memory */
  for (p = mem_image.data_seg_b + old_size; p < mem_image.data_seg_b + new_size; )
    *p ++ = 0;
}


/* Expand the stack segment by adding N bytes.  Can't use REALLOC
   since it copies from bottom of memory blocks and stack grows down from
   top of its block. */

#ifdef __STDC__
void
expand_stack (int context, int addl_bytes)
#else
void
expand_stack (addl_bytes)
     int addl_bytes;
#endif
{
  mem_image_t &mem_image = mem_images[context];
  int old_size = STACK_TOP - mem_image.stack_bot;
  int new_size = old_size + MAX (addl_bytes, old_size);
  mem_word *new_seg;
  register mem_word *po, *pn;

  if (addl_bytes < 0 || (source_file && new_size > stack_size_limit))
    {
      error ("Can't expand stack segment by %d bytes to %d bytes\n",
	     addl_bytes, new_size);
      run_error ("Use -lstack # with # > %d\n", new_size);
    }

  new_seg = (mem_word *) xmalloc (new_size);
  po = mem_image.stack_seg + (old_size / BYTES_PER_WORD - 1);
  pn = new_seg + (new_size / BYTES_PER_WORD - 1);

  for ( ; po >= mem_image.stack_seg ; ) *pn -- = *po --;
  for ( ; pn >= new_seg ; ) *pn -- = 0;

  free (mem_image.stack_seg);
  mem_image.stack_seg = new_seg;
  mem_image.stack_seg_b = (BYTE_TYPE *) mem_image.stack_seg;
  mem_image.stack_seg_h = (short *) mem_image.stack_seg;
  mem_image.stack_bot -= (new_size - old_size);
}


/* Expand the kernel data segment by adding N bytes. */

#ifdef __STDC__
void
expand_k_data (int context, int addl_bytes)
#else
void
expand_k_data (addl_bytes)
     int addl_bytes;
#endif
{
  mem_image_t &mem_image = mem_images[context];
  int old_size = mem_image.k_data_top - K_DATA_BOT;
  int new_size = old_size + addl_bytes;
  register BYTE_TYPE *p;

  if (addl_bytes < 0 || (source_file && new_size > k_data_size_limit))
    {
      error ("Can't expand kernel data segment by %d bytes to %d bytes\n",
	     addl_bytes, new_size);
      run_error ("Use -lkdata # with # > %d\n", new_size);
    }
  mem_image.k_data_seg = (mem_word *) realloc (mem_image.k_data_seg, new_size);
  if (mem_image.k_data_seg == NULL)
    fatal_error ("realloc failed in expand_k_data\n");

  mem_image.k_data_seg_b = (BYTE_TYPE *) mem_image.k_data_seg;
  mem_image.k_data_seg_h = (short *) mem_image.k_data_seg;
  mem_image.k_data_top += addl_bytes;

  /* Zero new memory */
  for (p = mem_image.k_data_seg_b + old_size / BYTES_PER_WORD;
       p < mem_image.k_data_seg_b + new_size / BYTES_PER_WORD; )
    *p ++ = 0;
}



/* Handle the infrequent and erroneous cases in the memory access macros. */

#ifdef __STDC__
instruction *
bad_text_read (int context, mem_addr addr)
#else
instruction *
bad_text_read (addr)
     mem_addr addr;
#endif
{
  reg_image_t &reg_image = reg_images[context];
  RAISE_EXCEPTION (reg_image, IBUS_EXCPT, BadVAddr(reg_image) = addr);
  return (inst_decode (0));
}


#ifdef __STDC__
void
bad_text_write (int context, mem_addr addr, instruction *inst)
#else
void
bad_text_write (addr, inst)
     mem_addr addr;
     instruction *inst;
#endif
{
  reg_image_t &reg_image = reg_images[context];
  RAISE_EXCEPTION (reg_image, IBUS_EXCPT, BadVAddr(reg_image) = addr);
  SET_MEM_WORD (context, addr, ENCODING (inst));
}


#ifdef __STDC__
mem_word
bad_mem_read (int context, mem_addr addr, int mask, mem_word *dest)
#else
mem_word
bad_mem_read (addr, mask, dest)
     mem_addr addr;
     int mask;
     mem_word *dest;
#endif
{
  mem_word tmp;
  reg_image_t &reg_image = reg_images[context];
  mem_image_t &mem_image = mem_images[context];

  if (addr & mask)
    RAISE_EXCEPTION (reg_image, ADDRL_EXCPT, BadVAddr(reg_image) = addr)
  else if (addr >= TEXT_BOT && addr < mem_image.text_top)
    switch (mask)
      {
      case 0x0:
	tmp = ENCODING (mem_image.text_seg [(addr - TEXT_BOT) >> 2]);
#ifdef BIGENDIAN
	tmp = (unsigned)tmp >> (8 * (3 - (addr & 0x3)));
#else
	tmp = (unsigned)tmp >> (8 * (addr & 0x3));
#endif
	return (0xff & tmp);

      case 0x1:
	tmp = ENCODING (mem_image.text_seg [(addr - TEXT_BOT) >> 2]);
#ifdef BIGENDIAN
	tmp = (unsigned)tmp >> (8 * (2 - (addr & 0x2)));
#else
	tmp = (unsigned)tmp >> (8 * (addr & 0x2));
#endif
	return (0xffff & tmp);

      case 0x3:
	{
	instruction *inst = mem_image.text_seg [(addr - TEXT_BOT) >> 2];
	if (inst == NULL)
	  return 0;
	else
	  return (ENCODING (inst));
	}

      default:
	run_error ("Bad mask (0x%x) in bad_mem_read\n", mask);
      }
  else if (addr > mem_image.data_top
	   && addr < mem_image.stack_bot
	   /* If more than 16 MB below stack, probably is bad data ref */
	   && addr > mem_image.stack_bot - 16*K*K)
    {
      /* Grow stack segment */
      expand_stack (context, mem_image.stack_bot - addr + 4);
      *dest = 0;		/* Newly allocated memory */
      return (0);
    }
  // else if (MM_IO_BOT <= addr && addr <= MM_IO_TOP)
  //   return (read_memory_mapped_IO (addr));
  else if (SPIMBOT_IO_BOT <= addr && addr <= SPIMBOT_IO_TOP) 
	 return (read_spimbot_IO (context, addr));
  else
    /* Address out of range */
    RAISE_EXCEPTION (reg_image, DBUS_EXCPT, BadVAddr(reg_image) = addr)
  return (0);
}


#ifdef __STDC__
void
bad_mem_write (int context, mem_addr addr, mem_word value, int mask)
#else
void
bad_mem_write (addr, value, mask)
     mem_addr addr;
     mem_word value;
     int mask;
#endif
{
  mem_word tmp;
  reg_image_t &reg_image = reg_images[context];
  mem_image_t &mem_image = mem_images[context];

  if (addr & mask)
    /* Unaligned address fault */
    RAISE_EXCEPTION (reg_image, ADDRS_EXCPT, BadVAddr(reg_image) = addr)
    else if (addr >= TEXT_BOT && addr < mem_image.text_top)
  {
    switch (mask)
    {
    case 0x0:
      tmp = ENCODING (mem_image.text_seg [(addr - TEXT_BOT) >> 2]);
#ifdef BIGENDIAN
      tmp = ((tmp & ~(0xff << (8 * (3 - (addr & 0x3)))))
	       | (value & 0xff) << (8 * (3 - (addr & 0x3))));
#else
      tmp = ((tmp & ~(0xff << (8 * (addr & 0x3))))
	       | (value & 0xff) << (8 * (addr & 0x3)));
#endif
      mem_image.text_seg [(addr - TEXT_BOT) >> 2] = inst_decode (tmp);
      break;
      
    case 0x1:
      tmp = ENCODING (mem_image.text_seg [(addr - TEXT_BOT) >> 2]);
#ifdef BIGENDIAN
      tmp = ((tmp & ~(0xffff << (8 * (2 - (addr & 0x2)))))
	       | (value & 0xffff) << (8 * (2 - (addr & 0x2))));
#else
      tmp = ((tmp & ~(0xffff << (8 * (addr & 0x2))))
	       | (value & 0xffff) << (8 * (addr & 0x2)));
#endif
      mem_image.text_seg [(addr - TEXT_BOT) >> 2] = inst_decode (tmp);
      break;
      
    case 0x3:
      mem_image.text_seg [(addr - TEXT_BOT) >> 2] = inst_decode (value);
      break;
      
    default:
      run_error ("Bad mask (0x%x) in bad_mem_read\n", mask);
    }
    
    mem_image.text_modified = 1;
  }
  else if (addr > mem_image.data_top
	   && addr < mem_image.stack_bot
	   /* If more than 16 MB below stack, probably is bad data ref */
	   && addr > mem_image.stack_bot - 16*K*K)
  {
    /* Grow stack segment */
    expand_stack (context, mem_image.stack_bot - addr + 4);
    if (addr >= mem_image.stack_bot)
    {
      if (mask == 0)
	mem_image.stack_seg_b [addr - mem_image.stack_bot] = (char)value;
      else if (mask == 1)
	mem_image.stack_seg_h [(addr - mem_image.stack_bot) >> 1] = (short)value;
      else
	mem_image.stack_seg [(addr - mem_image.stack_bot) >> 2] = value;
    }
    else
      RAISE_EXCEPTION (reg_image, DBUS_EXCPT, BadVAddr(reg_image) = addr)
      
    mem_image.data_modified = 1;
  }
  // else if (MM_IO_BOT <= addr && addr <= MM_IO_TOP)
  //   write_memory_mapped_IO (addr, value);
  else if (SPIMBOT_IO_BOT <= addr && addr <= SPIMBOT_IO_TOP) 
	 write_spimbot_IO (context, addr, value);
  else
    /* Address out of range */
    RAISE_EXCEPTION (reg_image, DBUS_EXCPT, BadVAddr(reg_image) = addr)
}



/* Memory-mapped IO routines: */

static long recv_control, recv_buffer, recv_buffer_filled;
static long trans_control, trans_buffer, trans_buffer_filled;


/* Every IO_INTERVAL time steps, check if input is available and output
   is possible.  If so, update the control registers and buffers. */

#ifdef __STDC__
void
check_memory_mapped_IO (int context)
#else
void
check_memory_mapped_IO ()
#endif
{
  static long mm_io_initialized = 0;
  reg_image_t &reg_image = reg_images[context];

  if (!mm_io_initialized)
    {
      recv_control = RECV_READY;
      trans_control = TRANS_READY;
      mm_io_initialized = 1;
    }

  if (console_input_available ())
    {
      recv_buffer_filled -= IO_INTERVAL;
      if (recv_buffer_filled <= 0)
	{
	  recv_buffer = get_console_char ();
	  recv_control |= RECV_READY;
	  recv_buffer_filled = RECV_LATENCY;
	  if ((recv_control & RECV_INT_ENABLE)
	      && INTERRUPTS_ON(reg_image)
	      && (Status_Reg(reg_image) & RECV_INT_MASK))
	    RAISE_EXCEPTION (reg_image, INT_EXCPT, Cause(reg_image) |= RECV_INT_MASK);
	}
    }
  else if (recv_buffer_filled <= 0)
    recv_control &= ~RECV_READY;

  if (trans_buffer_filled > 0)
    {
      trans_buffer_filled -= IO_INTERVAL;
      if (trans_buffer_filled <= 0)
	{
	  put_console_char ((char)trans_buffer);
	  trans_control |= TRANS_READY;
	  trans_buffer_filled = 0;
	  if ((trans_control & TRANS_INT_ENABLE)
	      && INTERRUPTS_ON(reg_image)
	      && (Status_Reg(reg_image) & TRANS_INT_MASK))
	    RAISE_EXCEPTION (reg_image, INT_EXCPT, Cause(reg_image) |= TRANS_INT_MASK)
	}
    }
}

// SPIMBOT: we over-ride these functions with our own I/O routines

// /* Invoked on a write in the memory-mapped IO area. */
// #ifdef __STDC__
// static void
// write_memory_mapped_IO (int context, mem_addr addr, mem_word value)
// #else
// static void
// write_memory_mapped_IO (addr, value)
//      mem_addr addr;
//      mem_word value;
// #endif
// {
//   reg_image_t &reg_image = reg_images[context];
// 
//   switch (addr)
//     {
//     case TRANS_CTRL_ADDR:
//       trans_control = ((trans_control & ~TRANS_INT_ENABLE)
// 		       | (value & TRANS_INT_ENABLE));
// 
//       if ((trans_control & TRANS_READY)
// 	  && (trans_control & TRANS_INT_ENABLE)
// 	  && INTERRUPTS_ON(reg_image)
// 			 && (Status_Reg(reg_image) & TRANS_INT_MASK))
// 	/* Raise an interrupt immediately on enabling a ready xmitter */
// 	RAISE_EXCEPTION (reg_image, INT_EXCPT, Cause(reg_image) |= TRANS_INT_MASK)
//       break;
// 
//     case TRANS_BUFFER_ADDR:
//       if (trans_control & TRANS_READY) /* Ignore if not ready */
// 	{
// 	  trans_buffer = value & 0xff;
// 	  trans_control &= ~TRANS_READY;
// 	  trans_buffer_filled = TRANS_LATENCY;
// 	}
//       break;
// 
//     case RECV_CTRL_ADDR:
//       recv_control = ((recv_control & ~RECV_INT_ENABLE)
// 		      | (value & RECV_INT_ENABLE));
//       break;
// 
//     case RECV_BUFFER_ADDR:
//       break;
// 
//     default:
//       run_error ("Write to unused memory-mapped IO address (0x%x)\n",
// 		 addr);
//     }
// }

// /* Invoked on a read in the memory-mapped IO area. */
// 
// #ifdef __STDC__
// static mem_word
// read_memory_mapped_IO (mem_addr addr)
// #else
// static mem_word
// read_memory_mapped_IO (addr)
//      mem_addr addr;
// #endif
// {
//   switch (addr)
//     {
//     case TRANS_CTRL_ADDR:
//       return (trans_control);
// 
//     case TRANS_BUFFER_ADDR:
//       return (trans_buffer & 0xff);
// 
//     case RECV_CTRL_ADDR:
//       return (recv_control);
// 
//     case RECV_BUFFER_ADDR:
//       recv_control &= ~RECV_READY;
//       recv_buffer_filled = 0;
//       return (recv_buffer & 0xff);
// 
//     default:
//       run_error ("Read from unused memory-mapped IO address (0x%x)\n",
// 		 addr);
//       return (0);
//     }
// }



/* Misc. routines */

#ifdef __STDC__
void
print_mem (mem_addr addr)
#else
void
print_mem (addr)
     mem_addr addr;
#endif
{
  mem_word value;
  int context = 0;
  mem_image_t &mem_image = mem_images[context];

  if (addr & 0x3)
    addr &= ~0x3;		/* Address must be word-aligned */

  if (TEXT_BOT <= addr && addr < mem_image.text_top)
    print_inst (addr);
  else if (DATA_BOT <= addr && addr < mem_image.data_top)
    {
      READ_MEM_WORD (context, value, addr);
      write_output (message_out, "Data seg @ 0x%08x (%d) = 0x%08x (%d)\n",
		    addr, addr, value, value);
    }
  else if (mem_image.stack_bot <= addr && addr < STACK_TOP)
    {
      READ_MEM_WORD (context, value, addr);
      write_output (message_out, "Stack seg @ 0x%08x (%d) = 0x%08x (%d)\n",
		    addr, addr, value, value);
    }
  else if (K_TEXT_BOT <= addr && addr < mem_image.k_text_top)
    print_inst (addr);
  else if (K_DATA_BOT <= addr && addr < mem_image.k_data_top)
    {
      READ_MEM_WORD (context, value, addr);
      write_output (message_out,
		    "Kernel Data seg @ 0x%08x (%d) = 0x%08x (%d)\n",
		    addr, addr, value, value);
    }
  else
    error ("Address 0x%08x (%d) to print_mem is out of bounds\n", addr, addr);
}
