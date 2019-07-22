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
   Macros for accessing memory.

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


/*   $Header: /usr/local/cvsroot/spimbot/mem.h,v 1.6 2004/11/23 04:15:35 craig Exp $
*/

#ifndef __MEM_H
#define __MEM_H

#include <vector>
using namespace std;

#include "inst.h"
#include "SPIMbot.h"
#include "types.h"

/* A note on directions:  "Bottom" of memory is the direction of
   decreasing addresses.  "Top" is the direction of increasing addresses.*/

#define TEXT_BOT ((mem_addr) 0x400000)
/* Amount to grow text segment when we run out of space for instructions. */
#define TEXT_CHUNK_SIZE	4096

/* Non-ANSI C compilers do not like signed chars.  You can change it to
   'char' if the compiler will treat chars as signed values... */
#define BYTE_TYPE signed char

#if ((defined (sun) || defined (hpux)) && !defined(__STDC__))
/* Sun and HP cc compilers: */
#undef BYTE_TYPE
#define BYTE_TYPE char
#endif

#define DATA_BOT ((mem_addr) 0x10000000)

/* Exclusive, but include 4K at top of stack. */
#define STACK_TOP ((mem_addr) 0x80000000)

#define K_TEXT_BOT ((mem_addr) 0x80000000)
#define K_DATA_BOT ((mem_addr) 0x90000000)

typedef struct memimage {
  /* The text segment and boundaries. */
  instruction **text_seg;
  int text_modified; 	/* Non-zero means text segment was written */
  mem_addr text_top;

  /* The data segment and boundaries. */
  mem_word *data_seg;
  int data_modified;	/* Non-zero means a data segment was written */
  short *data_seg_h;	/* Points to same vector as DATA_SEG */

  BYTE_TYPE *data_seg_b;	/* Ditto */
  mem_addr data_top;
  mem_addr gp_midpoint;	/* Middle of $gp area */

  /* The stack segment and boundaries. */
  mem_word *stack_seg;
  short *stack_seg_h;	/* Points to same vector as STACK_SEG */
  BYTE_TYPE *stack_seg_b;	/* Ditto */
  mem_addr stack_bot;

  /* The kernel text segment and boundaries. */
  instruction **k_text_seg;
  mem_addr k_text_top;

  /* Kernel data segment and boundaries. */
  mem_word *k_data_seg;
  short *k_data_seg_h;
  BYTE_TYPE *k_data_seg_b;
  mem_addr k_data_top;

  // generic_robot mmappedIO addrs:
  unsigned int CUR_MMIO_ADDR;
  vector<addr_list_node> mmapped_address_lookup;
  
} mem_image_t;

extern mem_image_t mem_images[MAX_NUM_ROBOTS];
//extern vector<mem_image_t> mem_images;

/* Memory-mapped IO area. */

#define MM_IO_BOT ((mem_addr) 0xffff0000)
#define MM_IO_TOP ((mem_addr) 0xffffffff)

#define RECV_CTRL_ADDR ((mem_addr) 0xffff0000)
#define RECV_READY 0x1
#define RECV_INT_ENABLE 0x2
#define RECV_INT_MASK 0x100
#define RECV_BUFFER_ADDR ((mem_addr) 0xffff0004)

#define TRANS_CTRL_ADDR ((mem_addr) 0xffff0008)
#define TRANS_READY 0x1
#define TRANS_INT_ENABLE 0x2
#define TRANS_INT_MASK 0x200
#define TRANS_BUFFER_ADDR ((mem_addr) 0xffff000c)



/* Translate from SPIM memory address to physical address */

#ifdef __STDC__
#define MEM_ADDRESS(CONTEXT, ADDR)													\
((((mem_addr) (ADDR) >= TEXT_BOT) && ((mem_addr) (ADDR) < mem_images[CONTEXT].text_top))	   \
 ? (mem_addr) (ADDR) - TEXT_BOT + (char*) mem_images[CONTEXT].text_seg			   \
 : ((((mem_addr) (ADDR) >= DATA_BOT) && ((mem_addr) (ADDR) < mem_images[CONTEXT].data_top))	   \
    ? (mem_addr) (ADDR) - DATA_BOT + (char*) mem_images[CONTEXT].data_seg		   \
    : ((((mem_addr) (ADDR) >= mem_images[CONTEXT].stack_bot) && ((mem_addr) (ADDR) < STACK_TOP)) \
       ? (mem_addr) (ADDR) - mem_images[CONTEXT].stack_bot + (char*) mem_images[CONTEXT].stack_seg		   \
       : ((((mem_addr) (ADDR) >= K_TEXT_BOT) && ((mem_addr) (ADDR) < mem_images[CONTEXT].k_text_top)) \
	  ? (mem_addr) (ADDR) - K_TEXT_BOT + (char*) mem_images[CONTEXT].k_text_seg		   \
	  : ((((mem_addr) (ADDR) >= K_DATA_BOT) && ((mem_addr) (ADDR) < mem_images[CONTEXT].k_data_top)) \
	     ? (mem_addr) (ADDR) - K_DATA_BOT + (char*) mem_images[CONTEXT].k_data_seg	   \
	     : (void*)run_error ("Memory address out of bounds\n"))))))
#else
#define MEM_ADDRESS(CONTEXT, ADDR)													\
((((mem_addr) (ADDR) >= TEXT_BOT) && ((mem_addr) (ADDR) < mem_images[CONTEXT].text_top))	   \
 ? (mem_addr) (ADDR) - TEXT_BOT + (char*) mem_images[CONTEXT].text_seg			   \
 : ((((mem_addr) (ADDR) >= DATA_BOT) && ((mem_addr) (ADDR) < mem_images[CONTEXT].data_top))	   \
    ? (mem_addr) (ADDR) - DATA_BOT + (char*) mem_images[CONTEXT].data_seg		   \
    : ((((mem_addr) (ADDR) >= mem_images[CONTEXT].stack_bot) && ((mem_addr) (ADDR) < STACK_TOP)) \
       ? (mem_addr) (ADDR) - mem_images[CONTEXT].stack_bot + (char*) mem_images[CONTEXT].stack_seg		   \
       : ((((mem_addr) (ADDR) >= K_TEXT_BOT) && ((mem_addr) (ADDR) < mem_images[CONTEXT].k_text_top)) \
	  ? (mem_addr) (ADDR) - K_TEXT_BOT + (char*) mem_images[CONTEXT].k_text_seg		   \
	  : ((((mem_addr) (ADDR) >= K_DATA_BOT) && ((mem_addr) (ADDR) < mem_images[CONTEXT].k_data_top)) \
	     ? (mem_addr) (ADDR) - K_DATA_BOT + (char*) mem_images[CONTEXT].k_data_seg	   \
	     : (char*)run_error ("Memory address out of bounds\n"))))))
#endif

#define READ_MEM_INST(CONTEXT, LOC, ADDR)							\
{register mem_addr _addr_ = (mem_addr) (ADDR);				   \
   if (_addr_ >= TEXT_BOT && _addr_ < mem_images[CONTEXT].text_top && !(_addr_ & 0x3))	   \
     LOC = mem_images[CONTEXT].text_seg [(_addr_ - TEXT_BOT) >> 2];				   \
   else if (_addr_ >= K_TEXT_BOT && _addr_ < mem_images[CONTEXT].k_text_top && !(_addr_ & 0x3))\
     LOC = mem_images[CONTEXT].k_text_seg [(_addr_ - K_TEXT_BOT) >> 2];			   \
   else {LOC = bad_text_read (CONTEXT, _addr_); printf("LOC = bad_text_read\n");}}


#define READ_MEM_BYTE(CONTEXT, LOC, ADDR)							\
{register mem_addr _addr_ = (mem_addr) (ADDR);				   \
   if (_addr_ >= DATA_BOT && _addr_ < mem_images[CONTEXT].data_top)				   \
    LOC = mem_images[CONTEXT].data_seg_b [_addr_ - DATA_BOT];				   \
   else if (_addr_ >= mem_images[CONTEXT].stack_bot && _addr_ < STACK_TOP)			   \
     LOC = mem_images[CONTEXT].stack_seg_b [_addr_ - mem_images[CONTEXT].stack_bot];				   \
   else if (_addr_ >= K_DATA_BOT && _addr_ < mem_images[CONTEXT].k_data_top)		   \
    LOC = mem_images[CONTEXT].k_data_seg_b [_addr_ - K_DATA_BOT];				   \
   else									   \
     LOC = bad_mem_read (CONTEXT, _addr_, 0, (mem_word *)&LOC);}


#define READ_MEM_HALF(CONTEXT, LOC, ADDR)							\
{register mem_addr _addr_ = (mem_addr) (ADDR);				   \
   if (_addr_ >= DATA_BOT && _addr_ < mem_images[CONTEXT].data_top && !(_addr_ & 0x1))	   \
     LOC = mem_images[CONTEXT].data_seg_h [(_addr_ - DATA_BOT) >> 1];			   \
  else if (_addr_ >= mem_images[CONTEXT].stack_bot && _addr_ < STACK_TOP && !(_addr_ & 0x1))   \
    LOC = mem_images[CONTEXT].stack_seg_h [(_addr_ - mem_images[CONTEXT].stack_bot) >> 1];			   \
   else if (_addr_ >= K_DATA_BOT && _addr_ < mem_images[CONTEXT].k_data_top && !(_addr_ & 0x1))\
     LOC = mem_images[CONTEXT].k_data_seg_h [(_addr_ - K_DATA_BOT) >> 1];			   \
  else									   \
    LOC = bad_mem_read (CONTEXT, _addr_, 0x1, (mem_word *)&LOC);}


#define READ_MEM_WORD(CONTEXT, LOC, ADDR)					   \
{register mem_addr _addr_ = (mem_addr) (ADDR);				   \
   if (_addr_ >= DATA_BOT && _addr_ < mem_images[CONTEXT].data_top && !(_addr_ & 0x3))	   \
     LOC = mem_images[CONTEXT].data_seg [(_addr_ - DATA_BOT) >> 2];				   \
  else if (_addr_ >= mem_images[CONTEXT].stack_bot && _addr_ < STACK_TOP && !(_addr_ & 0x3))   \
    LOC = mem_images[CONTEXT].stack_seg [(_addr_ - mem_images[CONTEXT].stack_bot) >> 2];			   \
   else if (_addr_ >= K_DATA_BOT && _addr_ < mem_images[CONTEXT].k_data_top && !(_addr_ & 0x3))\
     LOC = mem_images[CONTEXT].k_data_seg [(_addr_ - K_DATA_BOT) >> 2];			   \
  else									   \
    LOC = bad_mem_read (CONTEXT, _addr_, 0x3, (mem_word *)&LOC);}


#define SET_MEM_INST(CONTEXT, ADDR, INST)					   \
{register mem_addr _addr_ = (mem_addr) (ADDR);				   \
   mem_images[CONTEXT].text_modified = 1;							   \
   if (_addr_ >= TEXT_BOT && _addr_ < mem_images[CONTEXT].text_top && !(_addr_ & 0x3))	   \
     mem_images[CONTEXT].text_seg [(_addr_ - TEXT_BOT) >> 2] = INST;			   \
   else if (_addr_ >= K_TEXT_BOT && _addr_ < mem_images[CONTEXT].k_text_top && !(_addr_ & 0x3))\
     mem_images[CONTEXT].k_text_seg [(_addr_ - K_TEXT_BOT) >> 2] = INST;			   \
   else bad_text_write (CONTEXT, _addr_, INST);}


#define SET_MEM_BYTE(CONTEXT, ADDR, VALUE)					   \
{register mem_addr _addr_ = (mem_addr) (ADDR);				   \
   mem_images[CONTEXT].data_modified = 1;							   \
   if (_addr_ >= DATA_BOT && _addr_ < mem_images[CONTEXT].data_top)				   \
     mem_images[CONTEXT].data_seg_b [_addr_ - DATA_BOT] = (unsigned char) (VALUE);		   \
   else if (_addr_ >= mem_images[CONTEXT].stack_bot && _addr_ < STACK_TOP)			   \
     mem_images[CONTEXT].stack_seg_b [_addr_ - mem_images[CONTEXT].stack_bot] = (unsigned char) (VALUE);	   \
   else if (_addr_ >= K_DATA_BOT && _addr_ < mem_images[CONTEXT].k_data_top)		   \
     mem_images[CONTEXT].k_data_seg_b [_addr_ - K_DATA_BOT] = (unsigned char) (VALUE);	   \
   else bad_mem_write (CONTEXT, _addr_, VALUE, 0);}


#define SET_MEM_HALF(CONTEXT, ADDR, VALUE)					   \
{register mem_addr _addr_ = (mem_addr) (ADDR);				   \
   mem_images[CONTEXT].data_modified = 1;							   \
   if (_addr_ >= DATA_BOT && _addr_ < mem_images[CONTEXT].data_top && !(_addr_ & 0x1))	   \
     mem_images[CONTEXT].data_seg_h [(_addr_ - DATA_BOT) >> 1] = (unsigned short) (VALUE);	   \
   else if (_addr_ >= mem_images[CONTEXT].stack_bot && _addr_ < STACK_TOP && !(_addr_ & 0x1))  \
     mem_images[CONTEXT].stack_seg_h [(_addr_ - mem_images[CONTEXT].stack_bot) >> 1] = (unsigned short) (VALUE);   \
   else if (_addr_ >= K_DATA_BOT && _addr_ < mem_images[CONTEXT].k_data_top && !(_addr_ & 0x1))\
     mem_images[CONTEXT].k_data_seg_h [(_addr_ - K_DATA_BOT) >> 1] = (unsigned short) (VALUE); \
   else bad_mem_write (CONTEXT, _addr_, VALUE, 0x1);}


#define SET_MEM_WORD(CONTEXT, ADDR, VALUE)					   \
{register mem_addr _addr_ = (mem_addr) (ADDR);				   \
   mem_images[CONTEXT].data_modified = 1;							   \
   if (_addr_ >= DATA_BOT && _addr_ < mem_images[CONTEXT].data_top && !(_addr_ & 0x3))	   \
     mem_images[CONTEXT].data_seg [(_addr_ - DATA_BOT) >> 2] = (mem_word) (VALUE);		   \
   else if (_addr_ >= mem_images[CONTEXT].stack_bot && _addr_ < STACK_TOP && !(_addr_ & 0x3))  \
     mem_images[CONTEXT].stack_seg [(_addr_ - mem_images[CONTEXT].stack_bot) >> 2] = (mem_word) (VALUE);	   \
   else if (_addr_ >= K_DATA_BOT && _addr_ < mem_images[CONTEXT].k_data_top && !(_addr_ & 0x3))\
     mem_images[CONTEXT].k_data_seg [(_addr_ - K_DATA_BOT) >> 2] = (mem_word) (VALUE);	   \
   else bad_mem_write (CONTEXT, _addr_, VALUE, 0x3);}




/* Exported functions: */

#ifdef __STDC__
mem_word bad_mem_read (int context, mem_addr addr, int mask, mem_word *dest);
void bad_mem_write (int context, mem_addr addr, mem_word value, int mask);
instruction *bad_text_read (int context, mem_addr addr);
void bad_text_write (int context, mem_addr addr, instruction *inst);
void check_memory_mapped_IO (int context);
void expand_data (int context, int addl_bytes);
void expand_k_data (int context, int addl_bytes);
void expand_stack (int context, int addl_bytes);
void make_memory (int context, int text_size, int data_size, int data_limit,
		  int stack_size, int stack_limit, int k_text_size,
		  int k_data_size, int k_data_limit);
void print_mem (mem_addr addr);
#else
mem_word bad_mem_read ();
void bad_mem_write ();
instruction *bad_text_read ();
void bad_text_write ();
void check_memory_mapped_IO ();
void expand_data ();
void expand_k_data ();
void expand_stack ();
void make_memory ();
void print_mem ();
#endif

#endif /* __MEM_H */
