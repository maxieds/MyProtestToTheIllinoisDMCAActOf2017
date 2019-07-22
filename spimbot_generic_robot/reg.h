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
   Declarations of registers and code for accessing them.

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


/* $Header: /usr/local/cvsroot/spimbot/reg.h,v 1.6 2004/11/23 04:15:37 craig Exp $
*/

#ifndef _REG_H_
#define _REG_H_

//#include <vector>
//using namespace std;

#include "SPIMbot.h"

//typedef int32 reg_word;
typedef uint32 u_reg_word;

typedef struct regimage {
  int context;
  /* General purpose registers: */
  reg_word R[32];
  reg_word HI, LO;
  mem_addr PC, nPC;

  /* Floating Point Coprocessor (1) registers :*/
  double *FPR;		/* Dynamically allocate so overlay */
  float *FGR;		/* is possible */
  int *FWR;		/* is possible */

  int FP_reg_present;	/* Presence bits for FP registers */
  int FP_reg_poison;	/* Poison bits for FP registers */
  int FP_spec_load;	/* Is register waiting for a speculative load */

  /* Other Coprocessor Registers.  The floating point registers
	  (coprocessor 1) are above.  */
  reg_word CpCond[4], CCR[4][32], CPR[4][32];

  /* Exeception Handling Registers (actually registers in Coprocoessor
	  0's register file) */
  int exception_occurred;
  // mem_addr program_starting_address;

  /* Non-zero means store instructions in kernel, not user, text segment */
  int in_kernel;
  /* Locations for next instruction in user and kernel text segments */
  mem_addr next_text_pc;
  mem_addr next_k_text_pc;

  mem_addr next_data_pc;	/* Location for next datum in user process */
  mem_addr next_k_data_pc;	/* Location for next datum in kernel */
  mem_addr next_gp_item_addr; /* Address of next item accessed off $gp */
  int auto_alignment;	/* Non-zero => align literal to natural bound*/
} reg_image_t;

extern reg_image_t reg_images[MAX_NUM_ROBOTS];
//extern vector<reg_image_t> reg_images;
extern int num_contexts;

/* Argument passing registers */

#define REG_V0 2
#define REG_A0 4
#define REG_A1 5
#define REG_A2 6
#define REG_A3 7
#define REG_FA0 12
#define REG_SP 29


/* Result registers */

#define REG_RES 2
#define REG_FRES 0


/* $gp registers */

#define REG_GP 28



#define FPR_S(REGIMAGE, REGNO) ((REGIMAGE).FGR[REGNO])

#define FPR_D(REGIMAGE, REGNO) (double) (((REGNO) & 0x1) \
			       ? (run_error ("Bit 0 in FP double reg\n") ? 0.0 : 0.0)\
			       : (REGIMAGE).FPR[(REGNO) >> 1])

#define FPR_W(REGIMAGE, REGNO) ((REGIMAGE).FWR[REGNO])


#define SET_FPR_S(REGIMAGE, REGNO, VALUE) {(REGIMAGE).FGR[REGNO] = (float) (VALUE);}

#define SET_FPR_D(REGIMAGE, REGNO, VALUE) {if ((REGNO) & 0x1)	\
				 run_error ("Bit 0 in FP double reg\n");\
	          else (REGIMAGE).FPR[REGNO >> 1] = (double) (VALUE);}

#define SET_FPR_W(REGIMAGE, REGNO, VALUE) {(REGIMAGE).FWR[REGNO] = (int) (VALUE);}


/* Floating point control and condition registers: */

#define FCR(REGIMAGE)		(REGIMAGE).CPR[1]
#define FPId(REGIMAGE)		((REGIMAGE).CPR[1][0])
#define FpCond(REGIMAGE)		((REGIMAGE).CPR[1][31])



#define EntryHI(REGIMAGE)         ((REGIMAGE).CPR[0][0])
#define EntryLO(REGIMAGE)         ((REGIMAGE).CPR[0][1])
#define Index(REGIMAGE)           ((REGIMAGE).CPR[0][2])
#define Random(REGIMAGE)          ((REGIMAGE).CPR[0][3])
#define Context(REGIMAGE)		((REGIMAGE).CPR[0][4])
#define BadVAddr(REGIMAGE)	((REGIMAGE).CPR[0][8])
#define Status_Reg(REGIMAGE)	((REGIMAGE).CPR[0][12])
#define Cause(REGIMAGE)		((REGIMAGE).CPR[0][13])
#define EPC(REGIMAGE)		((REGIMAGE).CPR[0][14])
#define PRId(REGIMAGE)		((REGIMAGE).CPR[0][15])


#define USER_MODE(REGIMAGE) (Status_Reg(REGIMAGE) & 0x2)
#define INTERRUPTS_ON(REGIMAGE) (Status_Reg(REGIMAGE) & 0x1)

#endif
