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
   Execute SPIM instructions.

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


/* $Header: /usr/local/cvsroot/spimbot/run.c,v 1.10 2004/11/23 04:15:38 craig Exp $
*/


#ifdef mips
#define _IEEE 1
#include <nan.h>
#else
#define NaN(X) ((X) != (X))
#endif

#include <math.h>
#include <stdio.h>

#include "spim.h"
#include "reg.h"
#include "inst.h"
#include "spim-utils.h"
#include "mem.h"
#include "sym-tbl.h"
#include "y.tab.h"
#include "mips-syscall.h"
#include "run.h"
//#include "robot.h"
#include "robotutils.h"

int force_break = 0;	/* For the execution env. to force an execution break */
int total_steps = 0;

#ifndef _MSC_VER
extern int errno;
#endif

#ifdef __STDC__
long atol (const char *);
#else
long atol ();
#endif


/* Local functions: */

#ifdef __STDC__
static void long_multiply (int context, reg_word v1, reg_word v2);
#else
static void long_multiply ();
#endif


#define SIGN_BIT(X) ((X) & 0x80000000)

#define ARITH_OVFL(RESULT, OP1, OP2) (SIGN_BIT (OP1) == SIGN_BIT (OP2) \
				      && SIGN_BIT (OP1) != SIGN_BIT (RESULT))


/* Executed delayed branch and jump instructions by running the
   instruction from the delay slot before transfering control.  Note,
   in branches that don't jump, the instruction in the delay slot is
   executed by falling through normally.

   We take advantage of the MIPS architecture, which leaves undefined
   the result of executing a delayed instruction in a delay slot.  Here
   we execute the second branch. */

#define BRANCH_INST(TEST, TARGET) {if (TEST)				\
				    {					\
				      mem_addr target = (TARGET);	\
				      if (delayed_branches)		\
					/* +4 since jump in delay slot */\
					target += BYTES_PER_WORD;	\
				      JUMP_INST (target)		\
				    }					\
				  }


#define JUMP_INST(TARGET) {if (delayed_branches)			\
		run_spim (context, /* reg_image.PC + BYTES_PER_WORD, 1, */ display); \
			  /* -4 since PC is bumped after this inst */	\
	 reg_image.PC = (TARGET) - BYTES_PER_WORD;				\
  }


/* Result from load is available immediate, but no program should ever have
   assumed otherwise because of exceptions.*/

#define LOAD_INST(OP, ADDR, DEST_A, MASK)	\
				 {reg_word tmp;				\
				   OP (context, tmp, (ADDR));		\
				   *(DEST_A) = tmp & (MASK);		\
				 }


#define DELAYED_UPDATE(A, D) {if (delayed_addr1 != NULL)		\
				fatal_error("Two calls to DELAYED_UPDATE\n");\
				delayed_addr1 = A; delayed_value1 = D;	\
			      }


#define DO_DELAYED_UPDATE() if (delayed_loads)				\
			       {					\
				 /* Check for delayed updates */	\
				 if (delayed_addr2 != NULL)		\
				   *delayed_addr2 = delayed_value2;	\
				 delayed_addr2 = delayed_addr1;		\
				 delayed_value2 = delayed_value1;	\
				 delayed_addr1 = NULL;			\
			       }



/* Run a program starting at PC for N steps and display each
   instruction before executing if FLAG is non-zero.  If CONTINUE is
   non-zero, then step through a breakpoint.  Return non-zero if
   breakpoint is encountered. */

#ifdef __STDC__
int
run_program (mem_addr pc, int steps, int display, int cont_bkpt)
#else
int
run_program (pc, steps, display, cont_bkpt)
     mem_addr pc;
     int steps, display, cont_bkpt;
#endif
{
  for (int i = 0 ; i < steps ; ++ i) {
	 total_steps ++;

	 for (int context = 0 ; context < num_contexts ; ++ context) {
		reg_image_t &r_image = reg_images[context];
		
		if ((context == 0) && inst_is_breakpoint (r_image.PC)) {
                    if (cont_bkpt) {
			 mem_addr addr = r_image.PC;
			 
			 delete_breakpoint (addr);
			 r_image.exception_occurred = 0;
			 run_spim (context, display);
			 add_breakpoint (addr);
		  } else {
			 return (1);
		  }
		} else {
		  if (!run_spim (context, display)) {
			 r_image.PC = 0;
		  }
		}
	 }	
	 cont_bkpt = 0;
	 int spimbot_break = world_update();
	 if (spimbot_break >= 0) {		
               return (spimbot_break); 
	 }
  }
  return (0);

  // r_image.exception_occurred = 0;
  // if (!run_spim (context, PC, steps, display))
  //   /* Can't restart program */
  //   r_image.PC = 0;
  // if (inst_is_breakpoint (r_image.PC)) 
  //   return (1);
  // else
  //   return (0);
}

/* Run the program stored in memory, starting at address PC for
   STEPS_TO_RUN instruction executions.  If flag DISPLAY is non-zero, print
   each instruction before it executes. Return non-zero if program's
   execution can continue. */


#ifdef __STDC__
int
run_spim (int context, int display)
#else
int
run_spim (context, initial_PC, steps_to_run, display)
	  int context;
     mem_addr initial_PC;
     int steps_to_run;
     int display;
#endif
{
  register instruction *inst;
  static reg_word *delayed_addr1 = NULL, delayed_value1;
  static reg_word *delayed_addr2 = NULL, delayed_value2;
// int step, step_size, next_step;  fixme cleanup?
// int spimbot_break = 0;
  reg_image_t &reg_image = reg_images[context];

// 	  if (force_break)
// 	    {
// 	      force_break = 0;
// 	      return (1);
// 	    }

  reg_image.R[0] = 0;		/* Maintain invariant value */

  // printf("0x%08x\n", reg_image.PC);

  READ_MEM_INST (context, inst, reg_image.PC);
  
  if (inst == NULL)
	 return 0;
  
  if (reg_image.exception_occurred)  {
	 reg_image.exception_occurred = 0;
	 EPC(reg_image) = ROUND_DOWN (reg_image.PC, BYTES_PER_WORD);
	 handle_exception(reg_image);
	 return 1;  // continue;
  }
  else if (inst == NULL)
	 run_error ("Attempt to execute non-instruction at 0x%08x\n", reg_image.PC);
  else if (EXPR (inst) != NULL
			  && EXPR (inst)->symbol != NULL
			  && EXPR (inst)->symbol->addr == 0)
	 {
		error ("Instruction references undefined symbol at 0x%08x\n",
				 reg_image.PC);
		print_inst (reg_image.PC);
		run_error ("");
	 }
  
  if (display)
	 print_inst (reg_image.PC);

#ifdef TEST_ASM
  test_assembly (inst);
#endif

  DO_DELAYED_UPDATE ();
  
  switch (OPCODE (inst)) {
  case Y_ADD_OP:
	 {
		register reg_word vs = reg_image.R[RS (inst)], vt = reg_image.R[RT (inst)];
		register reg_word sum = vs + vt;
		
		if (ARITH_OVFL (sum, vs, vt))
		  RAISE_EXCEPTION (reg_image, OVF_EXCPT, break);
		reg_image.R[RD (inst)] = sum;
		break;
	 }
	 
  case Y_ADDI_OP:
	 {
		register reg_word vs = reg_image.R[RS (inst)], imm = (short) IMM (inst);
		register reg_word sum = vs + imm;
		
		if (ARITH_OVFL (sum, vs, imm))
		  RAISE_EXCEPTION (reg_image, OVF_EXCPT, break);
		reg_image.R[RT (inst)] = sum;
		break;
	 }
	 
  case Y_ADDIU_OP:
	 reg_image.R[RT (inst)] = reg_image.R[RS (inst)] + (short) IMM (inst);
	 break;
	 
  case Y_ADDU_OP:
	 reg_image.R[RD (inst)] = reg_image.R[RS (inst)] + reg_image.R[RT (inst)];
	 break;
	 
  case Y_AND_OP:
	 reg_image.R[RD (inst)] = reg_image.R[RS (inst)] & reg_image.R[RT (inst)];
	 break;
	 
  case Y_ANDI_OP:
	 reg_image.R[RT (inst)] = reg_image.R[RS (inst)] & (0xffff & IMM (inst));
	 break;
	 
  case Y_BC0F_OP:
  case Y_BC2F_OP:
  case Y_BC3F_OP:
	 BRANCH_INST (reg_image.CpCond[OPCODE (inst) - Y_BC0F_OP] == 0,
					  reg_image.PC + IDISP (inst));
	 break;
	 
  case Y_BC0T_OP:
  case Y_BC2T_OP:
  case Y_BC3T_OP:
	 BRANCH_INST (reg_image.CpCond[OPCODE (inst) - Y_BC0T_OP] != 0,
					  reg_image.PC + IDISP (inst));
	 break;
	 
  case Y_BEQ_OP:
	 BRANCH_INST (reg_image.R[RS (inst)] == reg_image.R[RT (inst)],
					  reg_image.PC + IDISP (inst));
	 break;
	 
  case Y_BGEZ_OP:
	 BRANCH_INST (SIGN_BIT (reg_image.R[RS (inst)]) == 0,
					  reg_image.PC + IDISP (inst));
	 break;
	 
  case Y_BGEZAL_OP:
	 if (delayed_branches) {
		reg_image.R[31] = reg_image.PC + 2 * BYTES_PER_WORD;
         }
	 else
		reg_image.R[31] = reg_image.PC + BYTES_PER_WORD;
	 BRANCH_INST (SIGN_BIT (reg_image.R[RS (inst)]) == 0,
					  reg_image.PC + IDISP (inst));
	 break;
	 
  case Y_BGTZ_OP:
	 BRANCH_INST (reg_image.R[RS (inst)] != 0 && SIGN_BIT (reg_image.R[RS (inst)]) == 0,
					  reg_image.PC + IDISP (inst));
	 break;
			
  case Y_BLEZ_OP:
	 BRANCH_INST (reg_image.R[RS (inst)] == 0 || SIGN_BIT (reg_image.R[RS (inst)]) != 0,
					  reg_image.PC + IDISP (inst));
	 break;
	 
  case Y_BLTZ_OP:
	 BRANCH_INST (SIGN_BIT (reg_image.R[RS (inst)]) != 0,
					  reg_image.PC + IDISP (inst));
	 break;
	 
  case Y_BLTZAL_OP:
	 if (delayed_branches) {
		reg_image.R[31] = reg_image.PC + 2 * BYTES_PER_WORD;
         }
	 else
		reg_image.R[31] = reg_image.PC + BYTES_PER_WORD;
	 BRANCH_INST (SIGN_BIT (reg_image.R[RS (inst)]) != 0,
					  reg_image.PC + IDISP (inst));
	 break;
			
  case Y_BNE_OP:
	 BRANCH_INST (reg_image.R[RS (inst)] != reg_image.R[RT (inst)],
					  reg_image.PC + IDISP (inst));
	 break;
	 
  case Y_BREAK_OP:
	 if (RD (inst) == 1) { 
		/* Debugger breakpoint */
		RAISE_EXCEPTION (reg_image, BKPT_EXCPT, return (1))
                     printf("RAISE_EXCEPTION (if)\n");
         }
		else {
		  RAISE_EXCEPTION (reg_image, BKPT_EXCPT, break);
                  printf("RAISE_EXCEPTION (else)\n");
                }
	 
  case Y_CFC0_OP:
  case Y_CFC2_OP:
  case Y_CFC3_OP:
	 reg_image.R[RT (inst)] = reg_image.CCR[OPCODE (inst) - Y_CFC0_OP][RD (inst)];
	 break;

  case Y_COP0_OP:
  case Y_COP1_OP:
  case Y_COP2_OP:
  case Y_COP3_OP:
	 reg_image.CCR[OPCODE (inst) - Y_COP0_OP][RD (inst)] = reg_image.R[RT (inst)];
	 break;
	 
  case Y_CTC0_OP:
  case Y_CTC2_OP:
  case Y_CTC3_OP:
	 reg_image.CCR[OPCODE (inst) - Y_CTC0_OP][RD (inst)] = reg_image.R[RT (inst)];
	 break;
	 
  case Y_DIV_OP:
	 /* The behavior of this instruction is undefined on divide by
		 zero or overflow. */
	 if (reg_image.R[RT (inst)] != 0
		  && (((unsigned)reg_image.R[RS (inst)]) != 0x80000000 && 
				((unsigned)reg_image.R[RT (inst)]) != 0xffffffff))
		{
		  reg_image.LO = (reg_word) reg_image.R[RS (inst)] / (reg_word) reg_image.R[RT (inst)];
		  reg_image.HI = (reg_word) reg_image.R[RS (inst)] % (reg_word) reg_image.R[RT (inst)];
		}
	 break;
	 
  case Y_DIVU_OP:
	 /* The behavior of this instruction is undefined on divide by
		 zero or overflow. */
	 if (reg_image.R[RT (inst)] != 0
		  && (((unsigned)reg_image.R[RS (inst)]) != 0x80000000 && 
				((unsigned)reg_image.R[RT (inst)]) != 0xffffffff))
		{
		  reg_image.LO = ((u_reg_word) reg_image.R[RS (inst)] / (u_reg_word) reg_image.R[RT (inst)]);
		  reg_image.HI = ((u_reg_word) reg_image.R[RS (inst)] % (u_reg_word) reg_image.R[RT (inst)]);
		}
	 break;
			
  case Y_J_OP:
	 JUMP_INST (((reg_image.PC & 0xf0000000) | TARGET (inst) << 2));
	 break;
	 
  case Y_JAL_OP:
	 if (delayed_branches)
		reg_image.R[31] = reg_image.PC + 2 * BYTES_PER_WORD;
	 else
		reg_image.R[31] = reg_image.PC + BYTES_PER_WORD;
	 JUMP_INST (((reg_image.PC & 0xf0000000) | (TARGET (inst) << 2)));
	 break;
	 
  case Y_JALR_OP:
	 {
		mem_addr tmp = reg_image.R[RS (inst)];
		
		if (delayed_branches)
		  reg_image.R[RD (inst)] = reg_image.PC + 2 * BYTES_PER_WORD;
		else
		  reg_image.R[RD (inst)] = reg_image.PC + BYTES_PER_WORD;
		JUMP_INST (tmp);
	 }
	 break;
	 
  case Y_JR_OP:
	 {
		mem_addr tmp = reg_image.R[RS (inst)];
		
		JUMP_INST (tmp);
	 }
	 break;
	 
  case Y_LB_OP:
	 LOAD_INST (READ_MEM_BYTE, reg_image.R[BASE (inst)] + IOFFSET (inst),
					&reg_image.R[RT (inst)], 0xffffffff);
	 break;
	 
  case Y_LBU_OP:
	 LOAD_INST (READ_MEM_BYTE, reg_image.R[BASE (inst)] + IOFFSET (inst),
					&reg_image.R[RT (inst)], 0xff);
	 break;
	 
  case Y_LH_OP:
	 LOAD_INST (READ_MEM_HALF, reg_image.R[BASE (inst)] + IOFFSET (inst),
					&reg_image.R[RT (inst)], 0xffffffff);
	 break;
	 
  case Y_LHU_OP:
	 LOAD_INST (READ_MEM_HALF, reg_image.R[BASE (inst)] + IOFFSET (inst),
					&reg_image.R[RT (inst)], 0xffff);
	 break;
	 
  case Y_LUI_OP:
	 reg_image.R[RT (inst)] = (IMM (inst) << 16) & 0xffff0000;
	 break;
	 
  case Y_LW_OP:
	 LOAD_INST (READ_MEM_WORD, reg_image.R[BASE (inst)] + IOFFSET (inst),
					&reg_image.R[RT (inst)], 0xffffffff);
	 break;
	 
  case Y_LWC0_OP:
  case Y_LWC2_OP:
  case Y_LWC3_OP:
	 LOAD_INST (READ_MEM_WORD, reg_image.R[BASE (inst)] + IOFFSET (inst),
					&reg_image.CPR[OPCODE (inst) - Y_LWC0_OP][RT (inst)],
					0xffffffff);
	 break;
	 
  case Y_LWL_OP:
	 {
		register mem_addr addr = reg_image.R[BASE (inst)] + IOFFSET (inst);
		reg_word word;	/* Can't be register */
		register int byte = addr & 0x3;
		reg_word reg_val = reg_image.R[RT (inst)];

		LOAD_INST (READ_MEM_WORD, addr & 0xfffffffc, &word,
					  0xffffffff);
		DO_DELAYED_UPDATE ();

		if ((!reg_image.exception_occurred) || ((Cause(reg_image) >> 2) > LAST_REAL_EXCEPT))
#ifdef BIGENDIAN
		  switch (byte)
		    {
		    case 0:
		      reg_image.R[RT (inst)] = word;
		      break;

		    case 1:
		      reg_image.R[RT (inst)] = ((word & 0xffffff) << 8) | (reg_val & 0xff);
		      break;

		    case 2:
		      reg_image.R[RT (inst)] = ((word & 0xffff) << 16) | (reg_val & 0xffff);
		      break;

		    case 3:
		      reg_image.R[RT (inst)] = ((word & 0xff) << 24) | (reg_val & 0xffffff);
		      break;
		    }
#else
		switch (byte)
		  {
		  case 0:
		    reg_image.R[RT (inst)] = ((word & 0xff) << 24) | (reg_val & 0xffffff);
		    break;

		  case 1:
		    reg_image.R[RT (inst)] = ((word & 0xffff) << 16) | (reg_val & 0xffff);
		    break;

		  case 2:
		    reg_image.R[RT (inst)] = ((word & 0xffffff) << 8) | (reg_val & 0xff);
		    break;

		  case 3:
		    reg_image.R[RT (inst)] = word;
		    break;
		  }
#endif
		break;
	 }

  case Y_LWR_OP:
	 {
		register mem_addr addr = reg_image.R[BASE (inst)] + IOFFSET (inst);
		reg_word word;	/* Can't be register */
		register int byte = addr & 0x3;
		reg_word reg_val = reg_image.R[RT (inst)];

		LOAD_INST (READ_MEM_WORD, addr & 0xfffffffc, &word, 0xffffffff);
		DO_DELAYED_UPDATE ();

		if ((!reg_image.exception_occurred) || ((Cause(reg_image) >> 2) > LAST_REAL_EXCEPT))
#ifdef BIGENDIAN
		  switch (byte)
		    {
		    case 0:
		      reg_image.R[RT (inst)] = (reg_val & 0xffffff00)
				  | ((unsigned)(word & 0xff000000) >> 24);
		      break;

		    case 1:
		      reg_image.R[RT (inst)] = (reg_val & 0xffff0000)
				  | ((unsigned)(word & 0xffff0000) >> 16);
		      break;

		    case 2:
		      reg_image.R[RT (inst)] = (reg_val & 0xff000000)
				  | ((unsigned)(word & 0xffffff00) >> 8);
		      break;

		    case 3:
		      reg_image.R[RT (inst)] = word;
		      break;
		    }
#else
		switch (byte)
		  {
		    /* NB: The description of the little-endian case in Kane is
		       totally wrong. */
		  case 0:	/* 3 in book */
		    reg_image.R[RT (inst)] = word;
		    break;

		  case 1:	/* 0 in book */
		    reg_image.R[RT (inst)] = (reg_val & 0xff000000)
		      | ((word & 0xffffff00) >> 8);
		    break;

		  case 2:	/* 1 in book */
		    reg_image.R[RT (inst)] = (reg_val & 0xffff0000)
		      | ((word & 0xffff0000) >> 16);
		    break;

		  case 3:	/* 2 in book */
		    reg_image.R[RT (inst)] = (reg_val & 0xffffff00)
		      | ((word & 0xff000000) >> 24);
		    break;
		  }
#endif
		break;
	 }

  case Y_MFC0_OP:
  case Y_MFC2_OP:
  case Y_MFC3_OP:
	 reg_image.R[RT (inst)] = reg_image.CPR[OPCODE (inst) - Y_MFC0_OP][RD (inst)];
	 break;

  case Y_MFHI_OP:
	 reg_image.R[RD (inst)] = reg_image.HI;
	 break;

  case Y_MFLO_OP:
	 reg_image.R[RD (inst)] = reg_image.LO;
	 break;

  case Y_MTC0_OP:
  case Y_MTC2_OP:
  case Y_MTC3_OP:
	 reg_image.CPR[OPCODE (inst) - Y_MTC0_OP][RD (inst)] = reg_image.R[RT (inst)];
	 break;

  case Y_MTHI_OP:
	 reg_image.HI = reg_image.R[RS (inst)];
	 break;

  case Y_MTLO_OP:
	 reg_image.LO = reg_image.R[RS (inst)];
	 break;

  case Y_MULT_OP:
	 {
		reg_word v1 = reg_image.R[RS (inst)], v2 = reg_image.R[RT (inst)];
		int neg_sign = 0;

		if (v1 < 0)
		  v1 = - v1, neg_sign = 1;
		if (v2 < 0)
		  v2 = - v2, neg_sign = ! neg_sign;

		long_multiply (context, v1, v2);
		if (neg_sign)
		  {
		    reg_image.LO = ~ reg_image.LO;
		    reg_image.HI = ~ reg_image.HI;
		    reg_image.LO += 1;
		    if (reg_image.LO == 0)
		      reg_image.HI += 1;
		  }
	 }
	 break;

  case Y_MULTU_OP:
	 long_multiply (context, reg_image.R[RS (inst)], reg_image.R[RT (inst)]);
	 break;

  case Y_NOR_OP:
	 reg_image.R[RD (inst)] = ~ (reg_image.R[RS (inst)] | reg_image.R[RT (inst)]);
	 break;

  case Y_OR_OP:
	 reg_image.R[RD (inst)] = reg_image.R[RS (inst)] | reg_image.R[RT (inst)];
	 break;

  case Y_ORI_OP:
	 reg_image.R[RT (inst)] = reg_image.R[RS (inst)] | (0xffff & IMM (inst));
	 break;

  case Y_RFE_OP:
	 Status_Reg(reg_image) = (Status_Reg(reg_image) & 0xfffffff0) | ((Status_Reg(reg_image) & 0x3c) >> 2);
	 break;

  case Y_SB_OP:
	 SET_MEM_BYTE (context, reg_image.R[BASE (inst)] + IOFFSET (inst), reg_image.R[RT (inst)]);
	 break;

  case Y_SH_OP:
	 SET_MEM_HALF (context, reg_image.R[BASE (inst)] + IOFFSET (inst), reg_image.R[RT (inst)]);
	 break;

  case Y_SLL_OP:
	 {
		int shamt = SHAMT (inst);

		if (shamt >= 0 && shamt < 32)
		  reg_image.R[RD (inst)] = reg_image.R[RT (inst)] << shamt;
		else
		  reg_image.R[RD (inst)] = reg_image.R[RT (inst)];
		break;
	 }

  case Y_SLLV_OP:
	 {
		int shamt = (reg_image.R[RS (inst)] & 0x1f);

		if (shamt >= 0 && shamt < 32)
		  reg_image.R[RD (inst)] = reg_image.R[RT (inst)] << shamt;
		else
		  reg_image.R[RD (inst)] = reg_image.R[RT (inst)];
		break;
	 }

  case Y_SLT_OP:
	 if (reg_image.R[RS (inst)] < reg_image.R[RT (inst)])
		reg_image.R[RD (inst)] = 1;
	 else
		reg_image.R[RD (inst)] = 0;
	 break;

  case Y_SLTI_OP:
	 if (reg_image.R[RS (inst)] < (short) IMM (inst))
		reg_image.R[RT (inst)] = 1;
	 else
		reg_image.R[RT (inst)] = 0;
	 break;

  case Y_SLTIU_OP:
	 {
		int x = (short) IMM (inst);

		if ((u_reg_word) reg_image.R[RS (inst)] < (u_reg_word) x)
		  reg_image.R[RT (inst)] = 1;
		else
		  reg_image.R[RT (inst)] = 0;
		break;
	 }

  case Y_SLTU_OP:
	 if ((u_reg_word) reg_image.R[RS (inst)] < (u_reg_word) reg_image.R[RT (inst)])
		reg_image.R[RD (inst)] = 1;
	 else
		reg_image.R[RD (inst)] = 0;
	 break;

  case Y_SRA_OP:
	 {
		int shamt = SHAMT (inst);
		reg_word val = reg_image.R[RT (inst)];

		if (shamt >= 0 && shamt < 32)
		  reg_image.R[RD (inst)] = val >> shamt;
		else
		  reg_image.R[RD (inst)] = val;
		break;
	 }

  case Y_SRAV_OP:
	 {
		int shamt = reg_image.R[RS (inst)] & 0x1f;
		reg_word val = reg_image.R[RT (inst)];

		if (shamt >= 0 && shamt < 32)
		  reg_image.R[RD (inst)] = val >> shamt;
		else
		  reg_image.R[RD (inst)] = val;
		break;
	 }

  case Y_SRL_OP:
	 {
		int shamt = SHAMT (inst);
		u_reg_word val = reg_image.R[RT (inst)];

		if (shamt >= 0 && shamt < 32)
		  reg_image.R[RD (inst)] = val >> shamt;
		else
		  reg_image.R[RD (inst)] = val;
		break;
	 }

  case Y_SRLV_OP:
	 {
		int shamt = reg_image.R[RS (inst)] & 0x1f;
		u_reg_word val = reg_image.R[RT (inst)];

		if (shamt >= 0 && shamt < 32)
		  reg_image.R[RD (inst)] = val >> shamt;
		else
		  reg_image.R[RD (inst)] = val;
		break;
	 }

  case Y_SUB_OP:
	 {
		register reg_word vs = reg_image.R[RS (inst)], vt = reg_image.R[RT (inst)];
		register reg_word diff = vs - vt;

		if (SIGN_BIT (vs) != SIGN_BIT (vt)
		    && SIGN_BIT (vs) != SIGN_BIT (diff))
		  RAISE_EXCEPTION (reg_image, OVF_EXCPT, break);
		reg_image.R[RD (inst)] = diff;
		break;
	 }

  case Y_SUBU_OP:
	 reg_image.R[RD (inst)] = (u_reg_word)reg_image.R[RS (inst)]-(u_reg_word)reg_image.R[RT (inst)];
	 break;

  case Y_SW_OP:
	 SET_MEM_WORD (context, reg_image.R[BASE (inst)] + IOFFSET (inst), reg_image.R[RT (inst)]);
	 break;

  case Y_SWC0_OP:
  case Y_SWC2_OP:
  case Y_SWC3_OP:
	 SET_MEM_WORD (context, reg_image.R[BASE (inst)] + IOFFSET (inst),
						reg_image.CPR[OPCODE (inst) - Y_SWC0_OP][RT (inst)]);
	 break;

  case Y_SWL_OP:
	 {
		register mem_addr addr = reg_image.R[BASE (inst)] + IOFFSET (inst);
		mem_word data;
		reg_word reg = reg_image.R[RT (inst)];
		register int byte = addr & 0x3;

		READ_MEM_WORD (context, data, (addr & 0xfffffffc));
#ifdef BIGENDIAN
		switch (byte)
		  {
		  case 0:
		    data = reg;
		    break;

		  case 1:
		    data = (data & 0xff000000) | (reg >> 8 & 0xffffff);
		    break;

		  case 2:
		    data = (data & 0xffff0000) | (reg >> 16 & 0xffff);
		    break;

		  case 3:
		    data = (data & 0xffffff00) | (reg >> 24 & 0xff);
		    break;
		  }
#else
		switch (byte)
		  {
		  case 0:
		    data = (data & 0xffffff00) | (reg >> 24 & 0xff);
		    break;

		  case 1:
		    data = (data & 0xffff0000) | (reg >> 16 & 0xffff);
		    break;

		  case 2:
		    data = (data & 0xff000000) | (reg >> 8 & 0xffffff);
		    break;

		  case 3:
		    data = reg;
		    break;
		  }
#endif
		SET_MEM_WORD (context, addr & 0xfffffffc, data);
		break;
	 }

  case Y_SWR_OP:
	 {
		register mem_addr addr = reg_image.R[BASE (inst)] + IOFFSET (inst);
		mem_word data;
		reg_word reg = reg_image.R[RT (inst)];
		register int byte = addr & 0x3;

		READ_MEM_WORD (context, data, (addr & 0xfffffffc));
#ifdef BIGENDIAN
		switch (byte)
		  {
		  case 0:
		    data = ((reg << 24) & 0xff000000) | (data & 0xffffff);
		    break;

		  case 1:
		    data = ((reg << 16) & 0xffff0000) | (data & 0xffff);
		    break;

		  case 2:
		    data = ((reg << 8) & 0xffffff00) | (data & 0xff) ;
		    break;

		  case 3:
		    data = reg;
		    break;
		  }
#else
		switch (byte)
		  {
		  case 0:
		    data = reg;
		    break;

		  case 1:
		    data = ((reg << 8) & 0xffffff00) | (data & 0xff) ;
		    break;

		  case 2:
		    data = ((reg << 16) & 0xffff0000) | (data & 0xffff);
		    break;

		  case 3:
		    data = ((reg << 24) & 0xff000000) | (data & 0xffffff);
		    break;
		  }
#endif
		SET_MEM_WORD (context, addr & 0xfffffffc, data);
		break;
	 }

  case Y_SYSCALL_OP:
	 if (!do_syscall (context))
		return (0);
	 break;

  case Y_TLBP_OP:
  case Y_TLBR_OP:
  case Y_TLBWI_OP:
  case Y_TLBWR_OP:
	 fatal_error ("Unimplemented operation\n");
	 break;

  case Y_XOR_OP:
	 reg_image.R[RD (inst)] = reg_image.R[RS (inst)] ^ reg_image.R[RT (inst)];
	 break;

  case Y_XORI_OP:
	 reg_image.R[RT (inst)] = reg_image.R[RS (inst)] ^ (0xffff & IMM (inst));
	 break;


	 /* FPA Operations */


  case Y_ABS_S_OP:
	 SET_FPR_S (reg_image, FD (inst), fabs (FPR_S (reg_image, FS (inst))));
	 break;

  case Y_ABS_D_OP: 
	 SET_FPR_D (reg_image, FD (inst), fabs (FPR_D (reg_image, FS (inst))));
	 break;

  case Y_ADD_S_OP:
	 SET_FPR_S (reg_image, FD (inst), FPR_S (reg_image, FS (inst)) + FPR_S (reg_image, FT (inst)));
	 /* Should trap on inexact/overflow/underflow */
	 break;

  case Y_ADD_D_OP:
	 SET_FPR_D (reg_image, FD (inst), FPR_D (reg_image, FS (inst)) + FPR_D (reg_image, FT (inst)));
	 /* Should trap on inexact/overflow/underflow */
	 break;

  case Y_BC1F_OP:
	 BRANCH_INST (FpCond(reg_image) == 0,
					  reg_image.PC + IDISP (inst));
	 break;

  case Y_BC1T_OP:
	 BRANCH_INST (FpCond(reg_image) == 1,
					  reg_image.PC + IDISP (inst));
	 break;

  case Y_C_F_S_OP:
  case Y_C_UN_S_OP:
  case Y_C_EQ_S_OP:
  case Y_C_UEQ_S_OP:
  case Y_C_OLT_S_OP:
  case Y_C_OLE_S_OP:
  case Y_C_ULT_S_OP:
  case Y_C_ULE_S_OP:
  case Y_C_SF_S_OP:
  case Y_C_NGLE_S_OP:
  case Y_C_SEQ_S_OP:
  case Y_C_NGL_S_OP:
  case Y_C_LT_S_OP:
  case Y_C_NGE_S_OP:
  case Y_C_LE_S_OP:
  case Y_C_NGT_S_OP:
	 {
		float v1 = FPR_S (reg_image, FS (inst)), v2 = FPR_S (reg_image, FT (inst));
		double dv1 = v1, dv2 = v2;
		int less, equal, unordered;
		int cond = COND (inst);

		if (NaN (dv1) || NaN (dv2))
		  {
		    less = 0;
		    equal = 0;
		    unordered = 1;
		    if (cond & COND_IN)
		      RAISE_EXCEPTION (reg_image, INVALID_EXCEPT, break);
		  }
		else
		  {
		    less = v1 < v2;
		    equal = v1 == v2;
		    unordered = 0;
		  }
		FpCond(reg_image) = 0;
		if (cond & COND_LT)
		  FpCond(reg_image) |= less;
		if (cond & COND_EQ)
		  FpCond(reg_image) |= equal;
		if (cond & COND_UN)
		  FpCond(reg_image) |= unordered;
	 }
	 break;

  case Y_C_F_D_OP:
  case Y_C_UN_D_OP:
  case Y_C_EQ_D_OP:
  case Y_C_UEQ_D_OP:
  case Y_C_OLT_D_OP:
  case Y_C_OLE_D_OP:
  case Y_C_ULT_D_OP:
  case Y_C_ULE_D_OP:
  case Y_C_SF_D_OP:
  case Y_C_NGLE_D_OP:
  case Y_C_SEQ_D_OP:
  case Y_C_NGL_D_OP:
  case Y_C_LT_D_OP:
  case Y_C_NGE_D_OP:
  case Y_C_LE_D_OP:
  case Y_C_NGT_D_OP:
	 {
		double v1 = FPR_D (reg_image, FS (inst)), v2 = FPR_D (reg_image, FT (inst));
		int less, equal, unordered;
		int cond = COND (inst);

		if (NaN (v1) || NaN (v2))
		  {
		    less = 0;
		    equal = 0;
		    unordered = 1;
		    if (cond & COND_IN)
		      RAISE_EXCEPTION (reg_image, INVALID_EXCEPT, break);
		  }
		else
		  {
		    less = v1 < v2;
		    equal = v1 == v2;
		    unordered = 0;
		  }
		FpCond(reg_image) = 0;
		if (cond & COND_LT)
		  FpCond(reg_image) |= less;
		if (cond & COND_EQ)
		  FpCond(reg_image) |= equal;
		if (cond & COND_UN)
		  FpCond(reg_image) |= unordered;
	 }
	 break;

  case Y_CFC1_OP:
	 reg_image.R[RT (inst)] = FCR(reg_image)[RD (inst)]; /* RD not FS */
	 break;

  case Y_CTC1_OP:
	 FCR(reg_image)[RD (inst)] = reg_image.R[RT (inst)]; /* RD not FS */
	 break;

  case Y_CVT_D_S_OP:
	 {
		double val = FPR_S (reg_image, FS (inst));

		SET_FPR_D (reg_image, FD (inst), val);
		break;
	 }

  case Y_CVT_D_W_OP:
	 {
		double val = FPR_W (reg_image, FS (inst));

		SET_FPR_D (reg_image, FD (inst), val);
		break;
	 }

  case Y_CVT_S_D_OP:
	 {
		float val = (float)FPR_D (reg_image, FS (inst));

		SET_FPR_S (reg_image, FD (inst), val);
		break;
	 }

  case Y_CVT_S_W_OP:
	 {
		float val = (float)FPR_W (reg_image, FS (inst));

		SET_FPR_S (reg_image, FD (inst), val);
		break;
	 }

  case Y_CVT_W_D_OP:
	 {
		int val = (int)FPR_D (reg_image, FS (inst));

		SET_FPR_W (reg_image, FD (inst), val);
		break;
	 }

  case Y_CVT_W_S_OP:
	 {
		int val = (int)FPR_S (reg_image, FS (inst));

		SET_FPR_W (reg_image, FD (inst), val);
		break;
	 }

  case Y_DIV_S_OP:
	 SET_FPR_S (reg_image, FD (inst), FPR_S (reg_image, FS (inst)) / FPR_S (reg_image, FT (inst)));
	 break;

  case Y_DIV_D_OP:
	 SET_FPR_D (reg_image, FD (inst), FPR_D (reg_image, FS (inst)) / FPR_D (reg_image, FT (inst)));
	 break;

  case Y_LWC1_OP:
	 {
		reg_word *wp = (reg_word *) &reg_image.FGR[FT (inst)];

		LOAD_INST (READ_MEM_WORD, reg_image.R[BASE (inst)] + IOFFSET (inst), wp,
					  0xffffffff);
		break;
	 }

  case Y_MFC1_OP:
	 {
		float val = reg_image.FGR[RD (inst)]; /* RD not FS */
		reg_word *vp = (reg_word *) &val;

		reg_image.R[RT (inst)] = *vp; /* Fool coercion */
		break;
	 }

  case Y_MOV_S_OP:
	 SET_FPR_S (reg_image, FD (inst), FPR_S (reg_image, FS (inst)));
	 break;

  case Y_MOV_D_OP:
	 SET_FPR_D (reg_image, FD (inst), FPR_D (reg_image, FS (inst)));
	 break;

  case Y_MTC1_OP:
	 {
		reg_word word = reg_image.R[RT (inst)];
		float *wp = (float *) &word;

		reg_image.FGR[RD (inst)] = *wp; /* RD not FS, fool coercion */
		break;
	 }

  case Y_MUL_S_OP:
	 SET_FPR_S (reg_image, FD (inst), FPR_S (reg_image, FS (inst)) * FPR_S (reg_image, FT (inst)));
	 break;

  case Y_MUL_D_OP:
	 SET_FPR_D (reg_image, FD (inst), FPR_D (reg_image, FS (inst)) * FPR_D (reg_image, FT (inst)));
	 break;

  case Y_NEG_S_OP:
	 SET_FPR_S (reg_image, FD (inst), -FPR_S (reg_image, FS (inst)));
	 break;

  case Y_NEG_D_OP:
	 SET_FPR_D (reg_image, FD (inst), -FPR_D (reg_image, FS (inst)));
	 break;

  case Y_SUB_S_OP:
	 SET_FPR_S (reg_image, FD (inst), FPR_S (reg_image, FS (inst)) - FPR_S (reg_image, FT (inst)));
	 break;

  case Y_SUB_D_OP:
	 SET_FPR_D (reg_image, FD (inst), FPR_D (reg_image, FS (inst)) - FPR_D (reg_image, FT (inst)));
	 break;

  case Y_SWC1_OP:
	 {
		float val = reg_image.FGR[RT (inst)];
		reg_word *vp = (reg_word *) &val;

		SET_MEM_WORD (context, reg_image.R[BASE (inst)] + IOFFSET (inst), *vp);
		break;
	 }

  default:
	 fatal_error ("Unknown instruction type: %d\n", OPCODE (inst));
	 break;
  }

  /* After instruction executes: */
  reg_image.PC += BYTES_PER_WORD;
 
  if (reg_image.exception_occurred) {
	 if ((Cause(reg_image) >> 2) > LAST_REAL_EXCEPT)
		EPC(reg_image) = reg_image.PC - BYTES_PER_WORD;
	 
	 handle_exception (reg_image);
  }

  /* Executed enought steps, return, but are able to continue. */
  return (1);
}


/* Multiply two 32-bit numbers, V1 and V2, to produce a 64 bit result in
   the HI/LO registers.	 The algorithm is high-school math:

	 A B
       x C D
       ------
       AD || BD
 AC || CB || 0

 where A and B are the high and low short words of V1, C and D are the short
 words of V2, AD is the product of A and D, and X || Y is (X << 16) + Y.
 Since the algorithm is programmed in C, we need to be careful not to
 overflow. */

#ifdef __STDC__
static void
long_multiply (int context, reg_word v1, reg_word v2)
#else
static void
long_multiply (context, v1, v2)
	  int context;
     reg_word v1, v2;
#endif
{
  register u_reg_word a, b, c, d;
  register u_reg_word bd, ad, cb, ac;
  register u_reg_word mid, mid2, carry_mid = 0;

  a = (v1 >> 16) & 0xffff;
  b = v1 & 0xffff;
  c = (v2 >> 16) & 0xffff;
  d = v2 & 0xffff;

  bd = b * d;
  ad = a * d;
  cb = c * b;
  ac = a * c;

  mid = ad + cb;
  if (mid < ad || mid < cb)
    /* Arithmetic overflow or carry-out */
    carry_mid = 1;

  mid2 = mid + ((bd >> 16) & 0xffff);
  if (mid2 < mid || mid2 < ((bd >> 16) & 0xffff))
    /* Arithmetic overflow or carry-out */
    carry_mid += 1;

  reg_images[context].LO = (bd & 0xffff) | ((mid2 & 0xffff) << 16);
  reg_images[context].HI = ac + (carry_mid << 16) + ((mid2 >> 16) & 0xffff);
}
