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
   Interface to code to manipulate data segment directives.

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


/* $Header: /usr/local/cvsroot/spimbot/data.h,v 1.3 2004/11/23 04:15:34 craig Exp $
*/


/* Exported functions: */

#ifdef __STDC__
void align_data (int alignment);
mem_addr current_data_pc (void);
void data_begins_at_point (int context, mem_addr addr);
void enable_data_alignment (void);
void end_of_assembly_file (void);
void extern_directive (char *name, int size);
void increment_data_pc (int value);
void k_data_begins_at_point (int context, mem_addr addr);
void lcomm_directive (char *name, int size);
void set_data_alignment (int);
void set_data_pc (mem_addr addr);
void set_text_pc (mem_addr addr);
void store_byte (int value);
void store_double (double *value);
void store_float (double *value);
void store_half (int value);
void store_string (char *string, int length, int null_terminate);
void store_word (int value);
void user_kernel_data_segment (int to_kernel);
#else
void align_data ();
mem_addr current_data_pc ();
void data_begins_at_point ();
void enable_data_alignment ();
void end_of_assembly_file ();
void extern_directive ();
void increment_data_pc ();
void k_data_begins_at_point ();
void lcomm_directive ();
void set_data_alignment ();
void set_data_pc ();
void set_text_pc ();
void store_byte ();
void store_double ();
void store_float ();
void store_half ();
void store_string ();
void store_word ();
void user_kernel_data_segment ();
#endif
