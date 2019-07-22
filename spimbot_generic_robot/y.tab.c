/* A Bison parser, made by GNU Bison 1.875d.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     Y_EOF = 258,
     Y_NL = 259,
     Y_INT = 260,
     Y_ID = 261,
     Y_REG = 262,
     Y_FP_REG = 263,
     Y_STR = 264,
     Y_FP = 265,
     Y_ABS_D_OP = 266,
     Y_ABS_S_OP = 267,
     Y_ADDIU_OP = 268,
     Y_ADDI_OP = 269,
     Y_ADDU_OP = 270,
     Y_ADD_D_OP = 271,
     Y_ADD_OP = 272,
     Y_ADD_S_OP = 273,
     Y_ANDI_OP = 274,
     Y_AND_OP = 275,
     Y_BC0F_OP = 276,
     Y_BC0T_OP = 277,
     Y_BC1F_OP = 278,
     Y_BC1T_OP = 279,
     Y_BC2F_OP = 280,
     Y_BC2T_OP = 281,
     Y_BC3F_OP = 282,
     Y_BC3T_OP = 283,
     Y_BEQ_OP = 284,
     Y_BGEZAL_OP = 285,
     Y_BGEZ_OP = 286,
     Y_BGTZ_OP = 287,
     Y_BLEZ_OP = 288,
     Y_BLTZAL_OP = 289,
     Y_BLTZ_OP = 290,
     Y_BNE_OP = 291,
     Y_BREAK_OP = 292,
     Y_CFC0_OP = 293,
     Y_CFC1_OP = 294,
     Y_CFC2_OP = 295,
     Y_CFC3_OP = 296,
     Y_COP0_OP = 297,
     Y_COP1_OP = 298,
     Y_COP2_OP = 299,
     Y_COP3_OP = 300,
     Y_CTC0_OP = 301,
     Y_CTC1_OP = 302,
     Y_CTC2_OP = 303,
     Y_CTC3_OP = 304,
     Y_CVT_D_S_OP = 305,
     Y_CVT_D_W_OP = 306,
     Y_CVT_S_D_OP = 307,
     Y_CVT_S_W_OP = 308,
     Y_CVT_W_D_OP = 309,
     Y_CVT_W_S_OP = 310,
     Y_C_EQ_D_OP = 311,
     Y_C_EQ_S_OP = 312,
     Y_C_F_D_OP = 313,
     Y_C_F_S_OP = 314,
     Y_C_LE_D_OP = 315,
     Y_C_LE_S_OP = 316,
     Y_C_LT_D_OP = 317,
     Y_C_LT_S_OP = 318,
     Y_C_NGE_D_OP = 319,
     Y_C_NGE_S_OP = 320,
     Y_C_NGLE_D_OP = 321,
     Y_C_NGLE_S_OP = 322,
     Y_C_NGL_D_OP = 323,
     Y_C_NGL_S_OP = 324,
     Y_C_NGT_D_OP = 325,
     Y_C_NGT_S_OP = 326,
     Y_C_OLT_D_OP = 327,
     Y_C_OLT_S_OP = 328,
     Y_C_OLE_D_OP = 329,
     Y_C_OLE_S_OP = 330,
     Y_C_SEQ_D_OP = 331,
     Y_C_SEQ_S_OP = 332,
     Y_C_SF_D_OP = 333,
     Y_C_SF_S_OP = 334,
     Y_C_UEQ_D_OP = 335,
     Y_C_UEQ_S_OP = 336,
     Y_C_ULT_D_OP = 337,
     Y_C_ULT_S_OP = 338,
     Y_C_ULE_D_OP = 339,
     Y_C_ULE_S_OP = 340,
     Y_C_UN_D_OP = 341,
     Y_C_UN_S_OP = 342,
     Y_DIVU_OP = 343,
     Y_DIV_D_OP = 344,
     Y_DIV_OP = 345,
     Y_DIV_S_OP = 346,
     Y_JALR_OP = 347,
     Y_JAL_OP = 348,
     Y_JR_OP = 349,
     Y_J_OP = 350,
     Y_LBU_OP = 351,
     Y_LB_OP = 352,
     Y_LHU_OP = 353,
     Y_LH_OP = 354,
     Y_LUI_OP = 355,
     Y_LWC0_OP = 356,
     Y_LWC1_OP = 357,
     Y_LWC2_OP = 358,
     Y_LWC3_OP = 359,
     Y_LWL_OP = 360,
     Y_LWR_OP = 361,
     Y_LW_OP = 362,
     Y_MFC0_OP = 363,
     Y_MFC1_OP = 364,
     Y_MFC2_OP = 365,
     Y_MFC3_OP = 366,
     Y_MFHI_OP = 367,
     Y_MFLO_OP = 368,
     Y_MOV_D_OP = 369,
     Y_MOV_S_OP = 370,
     Y_MTC0_OP = 371,
     Y_MTC1_OP = 372,
     Y_MTC2_OP = 373,
     Y_MTC3_OP = 374,
     Y_MTHI_OP = 375,
     Y_MTLO_OP = 376,
     Y_MULTU_OP = 377,
     Y_MULT_OP = 378,
     Y_MUL_D_OP = 379,
     Y_MUL_S_OP = 380,
     Y_NEG_D_OP = 381,
     Y_NEG_S_OP = 382,
     Y_NOR_OP = 383,
     Y_ORI_OP = 384,
     Y_OR_OP = 385,
     Y_PFW_OP = 386,
     Y_RFE_OP = 387,
     Y_SB_OP = 388,
     Y_SH_OP = 389,
     Y_SLLV_OP = 390,
     Y_SLL_OP = 391,
     Y_SLTIU_OP = 392,
     Y_SLTI_OP = 393,
     Y_SLTU_OP = 394,
     Y_SLT_OP = 395,
     Y_SRAV_OP = 396,
     Y_SRA_OP = 397,
     Y_SRLV_OP = 398,
     Y_SRL_OP = 399,
     Y_SUBU_OP = 400,
     Y_SUB_D_OP = 401,
     Y_SUB_OP = 402,
     Y_SUB_S_OP = 403,
     Y_SWC0_OP = 404,
     Y_SWC1_OP = 405,
     Y_SWC2_OP = 406,
     Y_SWC3_OP = 407,
     Y_SWL_OP = 408,
     Y_SWR_OP = 409,
     Y_SW_OP = 410,
     Y_SYSCALL_OP = 411,
     Y_TLBP_OP = 412,
     Y_TLBR_OP = 413,
     Y_TLBWI_OP = 414,
     Y_TLBWR_OP = 415,
     Y_XORI_OP = 416,
     Y_XOR_OP = 417,
     Y_ABS_POP = 418,
     Y_BAL_POP = 419,
     Y_BEQZ_POP = 420,
     Y_BGEU_POP = 421,
     Y_BGE_POP = 422,
     Y_BGTU_POP = 423,
     Y_BGT_POP = 424,
     Y_BLEU_POP = 425,
     Y_BLE_POP = 426,
     Y_BLTU_POP = 427,
     Y_BLT_POP = 428,
     Y_BNEZ_POP = 429,
     Y_B_POP = 430,
     Y_LA_POP = 431,
     Y_LD_POP = 432,
     Y_LI_POP = 433,
     Y_LI_D_POP = 434,
     Y_LI_S_POP = 435,
     Y_L_D_POP = 436,
     Y_L_S_POP = 437,
     Y_MFC1_D_POP = 438,
     Y_MTC1_D_POP = 439,
     Y_MOVE_POP = 440,
     Y_MULOU_POP = 441,
     Y_MULO_POP = 442,
     Y_MUL_POP = 443,
     Y_NEGU_POP = 444,
     Y_NEG_POP = 445,
     Y_NOP_POP = 446,
     Y_NOT_POP = 447,
     Y_REMU_POP = 448,
     Y_REM_POP = 449,
     Y_ROL_POP = 450,
     Y_ROR_POP = 451,
     Y_SD_POP = 452,
     Y_SEQ_POP = 453,
     Y_SGEU_POP = 454,
     Y_SGE_POP = 455,
     Y_SGTU_POP = 456,
     Y_SGT_POP = 457,
     Y_SLEU_POP = 458,
     Y_SLE_POP = 459,
     Y_SNE_POP = 460,
     Y_S_D_POP = 461,
     Y_S_S_POP = 462,
     Y_ULHU_POP = 463,
     Y_ULH_POP = 464,
     Y_ULW_POP = 465,
     Y_USH_POP = 466,
     Y_USW_POP = 467,
     Y_ALIAS_DIR = 468,
     Y_ALIGN_DIR = 469,
     Y_ASCII_DIR = 470,
     Y_ASCIIZ_DIR = 471,
     Y_ASM0_DIR = 472,
     Y_BGNB_DIR = 473,
     Y_BYTE_DIR = 474,
     Y_COMM_DIR = 475,
     Y_DATA_DIR = 476,
     Y_DOUBLE_DIR = 477,
     Y_ENDB_DIR = 478,
     Y_ENDR_DIR = 479,
     Y_END_DIR = 480,
     Y_ENT_DIR = 481,
     Y_ERR_DIR = 482,
     Y_EXTERN_DIR = 483,
     Y_FILE_DIR = 484,
     Y_FLOAT_DIR = 485,
     Y_FMASK_DIR = 486,
     Y_FRAME_DIR = 487,
     Y_GLOBAL_DIR = 488,
     Y_HALF_DIR = 489,
     Y_K_TEXT_DIR = 490,
     Y_K_DATA_DIR = 491,
     Y_LABEL_DIR = 492,
     Y_LCOMM_DIR = 493,
     Y_LIVEREG_DIR = 494,
     Y_LOC_DIR = 495,
     Y_MASK_DIR = 496,
     Y_NOALIAS_DIR = 497,
     Y_OPTIONS_DIR = 498,
     Y_RDATA_DIR = 499,
     Y_REPEAT_DIR = 500,
     Y_SDATA_DIR = 501,
     Y_SET_DIR = 502,
     Y_SPACE_DIR = 503,
     Y_STRUCT_DIR = 504,
     Y_TEXT_DIR = 505,
     Y_VERSTAMP_DIR = 506,
     Y_VREG_DIR = 507,
     Y_WORD_DIR = 508
   };
#endif
#define Y_EOF 258
#define Y_NL 259
#define Y_INT 260
#define Y_ID 261
#define Y_REG 262
#define Y_FP_REG 263
#define Y_STR 264
#define Y_FP 265
#define Y_ABS_D_OP 266
#define Y_ABS_S_OP 267
#define Y_ADDIU_OP 268
#define Y_ADDI_OP 269
#define Y_ADDU_OP 270
#define Y_ADD_D_OP 271
#define Y_ADD_OP 272
#define Y_ADD_S_OP 273
#define Y_ANDI_OP 274
#define Y_AND_OP 275
#define Y_BC0F_OP 276
#define Y_BC0T_OP 277
#define Y_BC1F_OP 278
#define Y_BC1T_OP 279
#define Y_BC2F_OP 280
#define Y_BC2T_OP 281
#define Y_BC3F_OP 282
#define Y_BC3T_OP 283
#define Y_BEQ_OP 284
#define Y_BGEZAL_OP 285
#define Y_BGEZ_OP 286
#define Y_BGTZ_OP 287
#define Y_BLEZ_OP 288
#define Y_BLTZAL_OP 289
#define Y_BLTZ_OP 290
#define Y_BNE_OP 291
#define Y_BREAK_OP 292
#define Y_CFC0_OP 293
#define Y_CFC1_OP 294
#define Y_CFC2_OP 295
#define Y_CFC3_OP 296
#define Y_COP0_OP 297
#define Y_COP1_OP 298
#define Y_COP2_OP 299
#define Y_COP3_OP 300
#define Y_CTC0_OP 301
#define Y_CTC1_OP 302
#define Y_CTC2_OP 303
#define Y_CTC3_OP 304
#define Y_CVT_D_S_OP 305
#define Y_CVT_D_W_OP 306
#define Y_CVT_S_D_OP 307
#define Y_CVT_S_W_OP 308
#define Y_CVT_W_D_OP 309
#define Y_CVT_W_S_OP 310
#define Y_C_EQ_D_OP 311
#define Y_C_EQ_S_OP 312
#define Y_C_F_D_OP 313
#define Y_C_F_S_OP 314
#define Y_C_LE_D_OP 315
#define Y_C_LE_S_OP 316
#define Y_C_LT_D_OP 317
#define Y_C_LT_S_OP 318
#define Y_C_NGE_D_OP 319
#define Y_C_NGE_S_OP 320
#define Y_C_NGLE_D_OP 321
#define Y_C_NGLE_S_OP 322
#define Y_C_NGL_D_OP 323
#define Y_C_NGL_S_OP 324
#define Y_C_NGT_D_OP 325
#define Y_C_NGT_S_OP 326
#define Y_C_OLT_D_OP 327
#define Y_C_OLT_S_OP 328
#define Y_C_OLE_D_OP 329
#define Y_C_OLE_S_OP 330
#define Y_C_SEQ_D_OP 331
#define Y_C_SEQ_S_OP 332
#define Y_C_SF_D_OP 333
#define Y_C_SF_S_OP 334
#define Y_C_UEQ_D_OP 335
#define Y_C_UEQ_S_OP 336
#define Y_C_ULT_D_OP 337
#define Y_C_ULT_S_OP 338
#define Y_C_ULE_D_OP 339
#define Y_C_ULE_S_OP 340
#define Y_C_UN_D_OP 341
#define Y_C_UN_S_OP 342
#define Y_DIVU_OP 343
#define Y_DIV_D_OP 344
#define Y_DIV_OP 345
#define Y_DIV_S_OP 346
#define Y_JALR_OP 347
#define Y_JAL_OP 348
#define Y_JR_OP 349
#define Y_J_OP 350
#define Y_LBU_OP 351
#define Y_LB_OP 352
#define Y_LHU_OP 353
#define Y_LH_OP 354
#define Y_LUI_OP 355
#define Y_LWC0_OP 356
#define Y_LWC1_OP 357
#define Y_LWC2_OP 358
#define Y_LWC3_OP 359
#define Y_LWL_OP 360
#define Y_LWR_OP 361
#define Y_LW_OP 362
#define Y_MFC0_OP 363
#define Y_MFC1_OP 364
#define Y_MFC2_OP 365
#define Y_MFC3_OP 366
#define Y_MFHI_OP 367
#define Y_MFLO_OP 368
#define Y_MOV_D_OP 369
#define Y_MOV_S_OP 370
#define Y_MTC0_OP 371
#define Y_MTC1_OP 372
#define Y_MTC2_OP 373
#define Y_MTC3_OP 374
#define Y_MTHI_OP 375
#define Y_MTLO_OP 376
#define Y_MULTU_OP 377
#define Y_MULT_OP 378
#define Y_MUL_D_OP 379
#define Y_MUL_S_OP 380
#define Y_NEG_D_OP 381
#define Y_NEG_S_OP 382
#define Y_NOR_OP 383
#define Y_ORI_OP 384
#define Y_OR_OP 385
#define Y_PFW_OP 386
#define Y_RFE_OP 387
#define Y_SB_OP 388
#define Y_SH_OP 389
#define Y_SLLV_OP 390
#define Y_SLL_OP 391
#define Y_SLTIU_OP 392
#define Y_SLTI_OP 393
#define Y_SLTU_OP 394
#define Y_SLT_OP 395
#define Y_SRAV_OP 396
#define Y_SRA_OP 397
#define Y_SRLV_OP 398
#define Y_SRL_OP 399
#define Y_SUBU_OP 400
#define Y_SUB_D_OP 401
#define Y_SUB_OP 402
#define Y_SUB_S_OP 403
#define Y_SWC0_OP 404
#define Y_SWC1_OP 405
#define Y_SWC2_OP 406
#define Y_SWC3_OP 407
#define Y_SWL_OP 408
#define Y_SWR_OP 409
#define Y_SW_OP 410
#define Y_SYSCALL_OP 411
#define Y_TLBP_OP 412
#define Y_TLBR_OP 413
#define Y_TLBWI_OP 414
#define Y_TLBWR_OP 415
#define Y_XORI_OP 416
#define Y_XOR_OP 417
#define Y_ABS_POP 418
#define Y_BAL_POP 419
#define Y_BEQZ_POP 420
#define Y_BGEU_POP 421
#define Y_BGE_POP 422
#define Y_BGTU_POP 423
#define Y_BGT_POP 424
#define Y_BLEU_POP 425
#define Y_BLE_POP 426
#define Y_BLTU_POP 427
#define Y_BLT_POP 428
#define Y_BNEZ_POP 429
#define Y_B_POP 430
#define Y_LA_POP 431
#define Y_LD_POP 432
#define Y_LI_POP 433
#define Y_LI_D_POP 434
#define Y_LI_S_POP 435
#define Y_L_D_POP 436
#define Y_L_S_POP 437
#define Y_MFC1_D_POP 438
#define Y_MTC1_D_POP 439
#define Y_MOVE_POP 440
#define Y_MULOU_POP 441
#define Y_MULO_POP 442
#define Y_MUL_POP 443
#define Y_NEGU_POP 444
#define Y_NEG_POP 445
#define Y_NOP_POP 446
#define Y_NOT_POP 447
#define Y_REMU_POP 448
#define Y_REM_POP 449
#define Y_ROL_POP 450
#define Y_ROR_POP 451
#define Y_SD_POP 452
#define Y_SEQ_POP 453
#define Y_SGEU_POP 454
#define Y_SGE_POP 455
#define Y_SGTU_POP 456
#define Y_SGT_POP 457
#define Y_SLEU_POP 458
#define Y_SLE_POP 459
#define Y_SNE_POP 460
#define Y_S_D_POP 461
#define Y_S_S_POP 462
#define Y_ULHU_POP 463
#define Y_ULH_POP 464
#define Y_ULW_POP 465
#define Y_USH_POP 466
#define Y_USW_POP 467
#define Y_ALIAS_DIR 468
#define Y_ALIGN_DIR 469
#define Y_ASCII_DIR 470
#define Y_ASCIIZ_DIR 471
#define Y_ASM0_DIR 472
#define Y_BGNB_DIR 473
#define Y_BYTE_DIR 474
#define Y_COMM_DIR 475
#define Y_DATA_DIR 476
#define Y_DOUBLE_DIR 477
#define Y_ENDB_DIR 478
#define Y_ENDR_DIR 479
#define Y_END_DIR 480
#define Y_ENT_DIR 481
#define Y_ERR_DIR 482
#define Y_EXTERN_DIR 483
#define Y_FILE_DIR 484
#define Y_FLOAT_DIR 485
#define Y_FMASK_DIR 486
#define Y_FRAME_DIR 487
#define Y_GLOBAL_DIR 488
#define Y_HALF_DIR 489
#define Y_K_TEXT_DIR 490
#define Y_K_DATA_DIR 491
#define Y_LABEL_DIR 492
#define Y_LCOMM_DIR 493
#define Y_LIVEREG_DIR 494
#define Y_LOC_DIR 495
#define Y_MASK_DIR 496
#define Y_NOALIAS_DIR 497
#define Y_OPTIONS_DIR 498
#define Y_RDATA_DIR 499
#define Y_REPEAT_DIR 500
#define Y_SDATA_DIR 501
#define Y_SET_DIR 502
#define Y_SPACE_DIR 503
#define Y_STRUCT_DIR 504
#define Y_TEXT_DIR 505
#define Y_VERSTAMP_DIR 506
#define Y_VREG_DIR 507
#define Y_WORD_DIR 508




/* Copy the first part of user declarations.  */
#line 293 "parser.y"

#include <stdio.h>

#include "spim.h"
#include "reg.h"
#include "inst.h"
#include "spim-utils.h"
#include "mem.h"
#include "sym-tbl.h"
#include "data.h"
#include "scanner.h"
#include "parser.h"

/* return (0) */
#define LINE_PARSE_DONE YYACCEPT

/* return (1) */
#define FILE_PARSE_DONE YYABORT

typedef struct ll
{
  label *head;
  struct ll *tail;
} label_list;


/* Exported Variables: */

int data_dir;			/* Non-zero means item in data segment */

int text_dir;			/* Non-zero means item in text segment */

int parse_error_occurred;  /* Non-zero => parse resulted in error */


/* Local functions: */

#ifdef __STDC__
static imm_expr *branch_offset (int n_inst);
static void check_imm_range (imm_expr*, int32, int32);
static void check_uimm_range (imm_expr*, uint32, uint32);
static void clear_labels (void);
static label_list *cons_label (label *head, label_list *tail);
static void div_inst (int op, int rd, int rs, int rt, int const_divisor);
static void mult_inst (int op, int rd, int rs, int rt);
static void nop_inst (void);
static void set_eq_inst (int op, int rd, int rs, int rt);
static void set_ge_inst (int op, int rd, int rs, int rt);
static void set_gt_inst (int op, int rd, int rs, int rt);
static void set_le_inst (int op, int rd, int rs, int rt);
static void store_word_data (int value);
static void trap_inst (void);
static void yywarn (char const *);
#else
static imm_expr *branch_offset ();
static void check_imm_range();
static void check_uimm_range();
static void clear_labels ();
static label_list *cons_label ();
static void div_inst ();
static void mult_inst ();
static void nop_inst ();
static void set_eq_inst ();
static void set_ge_inst ();
static void set_gt_inst ();
static void set_le_inst ();
static void store_word_data ();
static void trap_inst ();
static void yywarn ();
#endif


/* Local variables: */

static int null_term;		/* Non-zero means string terminate by \0 */

static void (*store_op) (void *);	/* Function to store items in an EXPR_LST */

static label_list *this_line_labels = NULL; /* List of label for curent line */

static int noat_flag = 0;	/* Non-zero means program can use $1 */

static char *input_file_name;	/* Name of file being parsed */



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 679 "y.tab.c"

#if ! defined (yyoverflow) || YYERROR_VERBOSE

# ifndef YYFREE
#  define YYFREE free
# endif
# ifndef YYMALLOC
#  define YYMALLOC malloc
# endif

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   define YYSTACK_ALLOC alloca
#  endif
# else
#  if defined (alloca) || defined (_ALLOCA_H)
#   define YYSTACK_ALLOC alloca
#  else
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
# else
#  if defined (__STDC__) || defined (__cplusplus)
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   define YYSIZE_T size_t
#  endif
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (defined (YYSTYPE_IS_TRIVIAL) && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short int yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short int) + sizeof (YYSTYPE))			\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined (__GNUC__) && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  register YYSIZE_T yyi;		\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (0)
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short int yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   886

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  261
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  95
/* YYNRULES -- Number of rules. */
#define YYNRULES  390
/* YYNRULES -- Number of states. */
#define YYNSTATES  601

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   508

#define YYTRANSLATE(YYX) 						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned short int yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     256,   257,     2,   258,     2,   259,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   254,     2,
       2,   255,   260,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short int yyprhs[] =
{
       0,     0,     3,     4,     7,    10,    12,    15,    19,    20,
      24,    25,    29,    31,    33,    35,    39,    43,    47,    51,
      55,    59,    63,    67,    71,    75,    79,    83,    87,    91,
      95,    97,   100,   102,   106,   110,   114,   118,   122,   127,
     132,   136,   141,   146,   150,   155,   159,   164,   168,   173,
     178,   183,   188,   192,   197,   202,   206,   210,   215,   220,
     225,   230,   234,   239,   244,   249,   254,   259,   264,   269,
     274,   279,   284,   289,   294,   297,   301,   305,   310,   315,
     320,   325,   330,   335,   340,   345,   350,   355,   358,   361,
     365,   368,   372,   375,   378,   382,   386,   390,   395,   399,
     403,   407,   409,   411,   413,   415,   417,   419,   421,   423,
     425,   427,   429,   431,   433,   435,   437,   439,   441,   443,
     445,   447,   449,   451,   453,   455,   457,   459,   461,   463,
     465,   467,   469,   471,   473,   475,   477,   479,   481,   483,
     485,   487,   489,   491,   493,   495,   497,   499,   501,   503,
     505,   507,   509,   511,   513,   515,   517,   519,   521,   523,
     525,   527,   529,   531,   533,   535,   537,   539,   541,   543,
     545,   547,   549,   551,   553,   555,   557,   559,   561,   563,
     565,   567,   569,   571,   573,   575,   577,   579,   581,   583,
     585,   587,   589,   591,   593,   595,   597,   599,   601,   603,
     605,   607,   609,   611,   613,   615,   617,   619,   621,   623,
     625,   627,   629,   631,   633,   635,   637,   639,   641,   643,
     645,   647,   649,   651,   653,   655,   657,   659,   661,   663,
     665,   667,   669,   671,   673,   675,   677,   679,   681,   683,
     685,   687,   689,   691,   693,   695,   697,   699,   701,   703,
     705,   707,   709,   711,   713,   715,   717,   719,   721,   723,
     725,   727,   729,   731,   733,   735,   737,   739,   741,   743,
     745,   747,   749,   751,   753,   755,   757,   759,   761,   763,
     767,   770,   771,   775,   776,   780,   782,   785,   786,   790,
     794,   796,   799,   801,   804,   805,   809,   812,   815,   817,
     820,   824,   828,   830,   834,   835,   839,   843,   848,   851,
     852,   856,   859,   863,   867,   871,   875,   879,   882,   885,
     887,   890,   892,   895,   898,   901,   904,   906,   909,   911,
     914,   918,   923,   924,   928,   929,   932,   936,   938,   943,
     945,   950,   954,   958,   962,   969,   976,   977,   980,   982,
     984,   986,   993,   995,   999,  1003,  1005,  1009,  1012,  1014,
    1016,  1018,  1020,  1022,  1024,  1026,  1028,  1030,  1032,  1034,
    1036,  1038,  1040,  1043,  1045,  1047,  1051,  1052,  1055,  1057,
    1059,  1062,  1064,  1068,  1071,  1073,  1074,  1077,  1079,  1080,
    1081
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short int yyrhs[] =
{
     262,     0,    -1,    -1,   263,   264,    -1,   265,   266,    -1,
     266,    -1,   354,   254,    -1,   354,   255,     5,    -1,    -1,
     270,   267,   269,    -1,    -1,   314,   268,   269,    -1,   269,
      -1,     4,    -1,     3,    -1,   271,   331,   322,    -1,   272,
     342,   322,    -1,   273,   331,   328,    -1,   176,   331,   322,
      -1,   178,   331,   329,    -1,   179,   338,    10,    -1,   180,
     338,    10,    -1,   210,   331,   322,    -1,   274,   331,   322,
      -1,   275,   338,   322,    -1,   276,   336,   322,    -1,   277,
     342,   322,    -1,   212,   336,   322,    -1,   211,   336,   322,
      -1,   278,   339,   322,    -1,   279,    -1,    37,     5,    -1,
     191,    -1,   163,   331,   332,    -1,   190,   331,   332,    -1,
     189,   331,   332,    -1,   192,   331,   332,    -1,   185,   331,
     332,    -1,   280,   331,   332,   333,    -1,   280,   331,   332,
     329,    -1,   280,   331,   329,    -1,   281,   331,   332,   333,
      -1,   281,   331,   332,     5,    -1,   281,   331,     5,    -1,
     282,   331,   332,   327,    -1,   282,   331,   327,    -1,   283,
     331,   332,   328,    -1,   283,   331,   328,    -1,   284,   331,
     332,     5,    -1,   284,   331,   332,   333,    -1,   285,   331,
     332,   333,    -1,   285,   331,   332,   329,    -1,   285,   331,
     329,    -1,   286,   331,   332,   333,    -1,   286,   331,   332,
     329,    -1,   286,   331,   329,    -1,   287,   331,   332,    -1,
     287,   331,   332,   333,    -1,   287,   331,   332,   329,    -1,
     288,   331,   332,   333,    -1,   288,   331,   332,   329,    -1,
     293,   332,   333,    -1,   196,   331,   332,   333,    -1,   195,
     331,   332,   333,    -1,   196,   331,   332,   329,    -1,   195,
     331,   332,   329,    -1,   289,   331,   332,   333,    -1,   289,
     331,   332,   329,    -1,   290,   331,   332,   333,    -1,   290,
     331,   332,   329,    -1,   291,   331,   332,   333,    -1,   291,
     331,   332,   329,    -1,   292,   331,   332,   333,    -1,   292,
     331,   332,   329,    -1,   294,   343,    -1,   295,   332,   343,
      -1,   296,   332,   343,    -1,   297,   332,   333,   343,    -1,
     297,   332,   325,   343,    -1,   298,   332,   333,   343,    -1,
     298,   332,   325,   343,    -1,   299,   332,   333,   343,    -1,
     299,   332,   325,   343,    -1,   300,   332,   333,   343,    -1,
     300,   332,   325,   343,    -1,   301,   332,   333,   343,    -1,
     301,   332,   325,   343,    -1,   302,   343,    -1,   302,   332,
      -1,   302,   334,   332,    -1,   303,   343,    -1,   304,   342,
     342,    -1,   305,   335,    -1,   306,   335,    -1,   307,   335,
     342,    -1,   308,   342,   342,    -1,   309,   338,   339,    -1,
     310,   338,   339,   340,    -1,   311,   338,   340,    -1,   312,
     338,   340,    -1,   313,   339,   340,    -1,    97,    -1,    96,
      -1,    99,    -1,    98,    -1,   107,    -1,   105,    -1,   106,
      -1,   177,    -1,   131,    -1,   101,    -1,   103,    -1,   104,
      -1,   100,    -1,   209,    -1,   208,    -1,   102,    -1,   182,
      -1,   181,    -1,   133,    -1,   134,    -1,   155,    -1,   153,
      -1,   154,    -1,   197,    -1,   149,    -1,   151,    -1,   152,
      -1,   150,    -1,   207,    -1,   206,    -1,   132,    -1,   156,
      -1,    17,    -1,    15,    -1,    20,    -1,   162,    -1,   130,
      -1,   140,    -1,   139,    -1,   135,    -1,   141,    -1,   143,
      -1,    14,    -1,    13,    -1,   138,    -1,   137,    -1,    19,
      -1,   129,    -1,   161,    -1,   136,    -1,   142,    -1,   144,
      -1,   128,    -1,   147,    -1,   145,    -1,    90,    -1,    88,
      -1,   194,    -1,   193,    -1,   188,    -1,   187,    -1,   186,
      -1,   204,    -1,   203,    -1,   202,    -1,   201,    -1,   200,
      -1,   199,    -1,   198,    -1,   205,    -1,   123,    -1,   122,
      -1,    22,    -1,    24,    -1,    26,    -1,    28,    -1,    21,
      -1,    23,    -1,    25,    -1,    27,    -1,    31,    -1,    30,
      -1,    32,    -1,    33,    -1,    35,    -1,    34,    -1,   165,
      -1,   174,    -1,    29,    -1,    36,    -1,   169,    -1,   168,
      -1,   167,    -1,   166,    -1,   173,    -1,   172,    -1,   171,
      -1,   170,    -1,    95,    -1,    94,    -1,    93,    -1,    92,
      -1,   175,    -1,   164,    -1,   115,    -1,   114,    -1,   112,
      -1,   113,    -1,   120,    -1,   121,    -1,   108,    -1,   109,
      -1,   183,    -1,   110,    -1,   111,    -1,   116,    -1,   117,
      -1,   184,    -1,   118,    -1,   119,    -1,    38,    -1,    39,
      -1,    40,    -1,    41,    -1,    46,    -1,    47,    -1,    48,
      -1,    49,    -1,    12,    -1,    11,    -1,    18,    -1,    16,
      -1,    91,    -1,    89,    -1,   125,    -1,   124,    -1,   148,
      -1,   146,    -1,    50,    -1,    51,    -1,    52,    -1,    53,
      -1,    54,    -1,    55,    -1,   127,    -1,   126,    -1,    59,
      -1,    87,    -1,    57,    -1,    81,    -1,    73,    -1,    75,
      -1,    83,    -1,    85,    -1,    79,    -1,    67,    -1,    77,
      -1,    69,    -1,    63,    -1,    65,    -1,    61,    -1,    71,
      -1,    58,    -1,    86,    -1,    56,    -1,    80,    -1,    72,
      -1,    74,    -1,    82,    -1,    84,    -1,    78,    -1,    66,
      -1,    76,    -1,    68,    -1,    62,    -1,    64,    -1,    60,
      -1,    70,    -1,   213,     7,     7,    -1,   214,   348,    -1,
      -1,   215,   315,   344,    -1,    -1,   216,   316,   344,    -1,
     217,    -1,   218,     5,    -1,    -1,   219,   317,   349,    -1,
     220,   354,   348,    -1,   221,    -1,   221,     5,    -1,   236,
      -1,   236,     5,    -1,    -1,   222,   318,   350,    -1,   225,
     351,    -1,   223,     5,    -1,   224,    -1,   226,   354,    -1,
     226,   354,     5,    -1,   228,   354,   348,    -1,   227,    -1,
     229,     5,     9,    -1,    -1,   230,   319,   350,    -1,   231,
       5,     5,    -1,   232,   337,     5,   337,    -1,   233,   354,
      -1,    -1,   234,   320,   349,    -1,   237,   354,    -1,   238,
     354,   348,    -1,   239,     5,     5,    -1,   240,     5,     5,
      -1,   241,     5,     5,    -1,   242,     7,     7,    -1,   243,
     354,    -1,   245,   348,    -1,   244,    -1,   244,     5,    -1,
     246,    -1,   246,     5,    -1,   247,   354,    -1,   248,   348,
      -1,   249,   348,    -1,   250,    -1,   250,     5,    -1,   235,
      -1,   235,     5,    -1,   251,     5,     5,    -1,   252,   337,
       5,     5,    -1,    -1,   253,   321,   349,    -1,    -1,   323,
     324,    -1,   256,   337,   257,    -1,   330,    -1,   330,   256,
     337,   257,    -1,     6,    -1,     6,   256,   337,   257,    -1,
       6,   258,   330,    -1,   330,   258,   354,    -1,     6,   259,
     330,    -1,     6,   258,   330,   256,   337,   257,    -1,     6,
     259,   330,   256,   337,   257,    -1,    -1,   326,   329,    -1,
     329,    -1,   329,    -1,   330,    -1,   256,   330,   257,   260,
     260,     5,    -1,   354,    -1,     6,   258,   330,    -1,     6,
     259,   330,    -1,     5,    -1,     5,   258,     5,    -1,     5,
       5,    -1,   337,    -1,   337,    -1,   337,    -1,   337,    -1,
     337,    -1,   337,    -1,     7,    -1,   341,    -1,   341,    -1,
     341,    -1,     8,    -1,     7,    -1,     8,    -1,   354,    -1,
     344,   345,    -1,   345,    -1,     9,    -1,     9,   254,     5,
      -1,    -1,   347,   348,    -1,     5,    -1,   354,    -1,   349,
     346,    -1,   346,    -1,   346,   254,     5,    -1,   350,    10,
      -1,    10,    -1,    -1,   352,   353,    -1,   354,    -1,    -1,
      -1,   355,     6,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,   383,   383,   383,   385,   386,   390,   401,   413,   412,
     419,   418,   424,   428,   433,   442,   458,   466,   472,   486,
     492,   503,   513,   537,   565,   580,   596,   606,   630,   655,
     670,   676,   684,   690,   700,   706,   712,   718,   724,   730,
     737,   744,   750,   756,   762,   768,   773,   779,   785,   793,
     799,   805,   823,   842,   848,   865,   882,   891,   897,   910,
     915,   929,   935,   944,   953,   965,   978,   983,   994,   999,
    1011,  1016,  1027,  1032,  1043,  1049,  1055,  1062,  1067,  1091,
    1098,  1121,  1128,  1137,  1144,  1153,  1160,  1183,  1193,  1202,
    1211,  1219,  1225,  1231,  1237,  1254,  1260,  1266,  1272,  1278,
    1284,  1292,  1293,  1294,  1295,  1296,  1297,  1298,  1299,  1300,
    1303,  1304,  1305,  1308,  1311,  1312,  1315,  1316,  1317,  1321,
    1322,  1323,  1324,  1325,  1326,  1329,  1330,  1331,  1334,  1335,
    1336,  1340,  1341,  1347,  1348,  1349,  1350,  1351,  1352,  1353,
    1356,  1357,  1358,  1361,  1362,  1363,  1364,  1367,  1368,  1369,
    1372,  1373,  1374,  1379,  1381,  1382,  1385,  1386,  1387,  1388,
    1391,  1392,  1393,  1396,  1397,  1400,  1401,  1404,  1405,  1408,
    1409,  1412,  1413,  1416,  1417,  1418,  1419,  1420,  1421,  1422,
    1423,  1426,  1427,  1428,  1429,  1430,  1431,  1434,  1435,  1438,
    1439,  1442,  1443,  1445,  1446,  1448,  1449,  1451,  1452,  1455,
    1456,  1457,  1458,  1461,  1462,  1465,  1466,  1469,  1470,  1473,
    1474,  1477,  1478,  1479,  1480,  1481,  1482,  1483,  1484,  1485,
    1486,  1489,  1490,  1491,  1492,  1493,  1494,  1495,  1496,  1499,
    1500,  1503,  1504,  1505,  1506,  1507,  1508,  1509,  1510,  1513,
    1514,  1515,  1516,  1517,  1518,  1521,  1522,  1525,  1526,  1527,
    1528,  1529,  1530,  1531,  1532,  1533,  1534,  1535,  1536,  1537,
    1538,  1539,  1540,  1541,  1542,  1543,  1544,  1545,  1546,  1547,
    1548,  1549,  1550,  1551,  1552,  1553,  1554,  1555,  1556,  1561,
    1563,  1568,  1568,  1574,  1574,  1581,  1583,  1587,  1586,  1595,
    1607,  1614,  1623,  1630,  1640,  1639,  1651,  1653,  1655,  1657,
    1659,  1662,  1668,  1674,  1678,  1677,  1689,  1691,  1694,  1702,
    1701,  1713,  1724,  1731,  1734,  1736,  1738,  1740,  1742,  1748,
    1755,  1764,  1771,  1780,  1789,  1798,  1804,  1811,  1820,  1827,
    1836,  1838,  1842,  1841,  1852,  1852,  1854,  1859,  1864,  1869,
    1875,  1881,  1887,  1892,  1898,  1904,  1912,  1912,  1914,  1920,
    1927,  1932,  1937,  1942,  1948,  1956,  1958,  1961,  1970,  1972,
    1974,  1976,  1978,  1980,  1982,  1991,  1993,  1995,  1997,  2005,
    2007,  2012,  2018,  2019,  2023,  2028,  2039,  2039,  2041,  2043,
    2057,  2061,  2065,  2075,  2079,  2086,  2086,  2088,  2089,  2093,
    2093
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "Y_EOF", "Y_NL", "Y_INT", "Y_ID",
  "Y_REG", "Y_FP_REG", "Y_STR", "Y_FP", "Y_ABS_D_OP", "Y_ABS_S_OP",
  "Y_ADDIU_OP", "Y_ADDI_OP", "Y_ADDU_OP", "Y_ADD_D_OP", "Y_ADD_OP",
  "Y_ADD_S_OP", "Y_ANDI_OP", "Y_AND_OP", "Y_BC0F_OP", "Y_BC0T_OP",
  "Y_BC1F_OP", "Y_BC1T_OP", "Y_BC2F_OP", "Y_BC2T_OP", "Y_BC3F_OP",
  "Y_BC3T_OP", "Y_BEQ_OP", "Y_BGEZAL_OP", "Y_BGEZ_OP", "Y_BGTZ_OP",
  "Y_BLEZ_OP", "Y_BLTZAL_OP", "Y_BLTZ_OP", "Y_BNE_OP", "Y_BREAK_OP",
  "Y_CFC0_OP", "Y_CFC1_OP", "Y_CFC2_OP", "Y_CFC3_OP", "Y_COP0_OP",
  "Y_COP1_OP", "Y_COP2_OP", "Y_COP3_OP", "Y_CTC0_OP", "Y_CTC1_OP",
  "Y_CTC2_OP", "Y_CTC3_OP", "Y_CVT_D_S_OP", "Y_CVT_D_W_OP", "Y_CVT_S_D_OP",
  "Y_CVT_S_W_OP", "Y_CVT_W_D_OP", "Y_CVT_W_S_OP", "Y_C_EQ_D_OP",
  "Y_C_EQ_S_OP", "Y_C_F_D_OP", "Y_C_F_S_OP", "Y_C_LE_D_OP", "Y_C_LE_S_OP",
  "Y_C_LT_D_OP", "Y_C_LT_S_OP", "Y_C_NGE_D_OP", "Y_C_NGE_S_OP",
  "Y_C_NGLE_D_OP", "Y_C_NGLE_S_OP", "Y_C_NGL_D_OP", "Y_C_NGL_S_OP",
  "Y_C_NGT_D_OP", "Y_C_NGT_S_OP", "Y_C_OLT_D_OP", "Y_C_OLT_S_OP",
  "Y_C_OLE_D_OP", "Y_C_OLE_S_OP", "Y_C_SEQ_D_OP", "Y_C_SEQ_S_OP",
  "Y_C_SF_D_OP", "Y_C_SF_S_OP", "Y_C_UEQ_D_OP", "Y_C_UEQ_S_OP",
  "Y_C_ULT_D_OP", "Y_C_ULT_S_OP", "Y_C_ULE_D_OP", "Y_C_ULE_S_OP",
  "Y_C_UN_D_OP", "Y_C_UN_S_OP", "Y_DIVU_OP", "Y_DIV_D_OP", "Y_DIV_OP",
  "Y_DIV_S_OP", "Y_JALR_OP", "Y_JAL_OP", "Y_JR_OP", "Y_J_OP", "Y_LBU_OP",
  "Y_LB_OP", "Y_LHU_OP", "Y_LH_OP", "Y_LUI_OP", "Y_LWC0_OP", "Y_LWC1_OP",
  "Y_LWC2_OP", "Y_LWC3_OP", "Y_LWL_OP", "Y_LWR_OP", "Y_LW_OP", "Y_MFC0_OP",
  "Y_MFC1_OP", "Y_MFC2_OP", "Y_MFC3_OP", "Y_MFHI_OP", "Y_MFLO_OP",
  "Y_MOV_D_OP", "Y_MOV_S_OP", "Y_MTC0_OP", "Y_MTC1_OP", "Y_MTC2_OP",
  "Y_MTC3_OP", "Y_MTHI_OP", "Y_MTLO_OP", "Y_MULTU_OP", "Y_MULT_OP",
  "Y_MUL_D_OP", "Y_MUL_S_OP", "Y_NEG_D_OP", "Y_NEG_S_OP", "Y_NOR_OP",
  "Y_ORI_OP", "Y_OR_OP", "Y_PFW_OP", "Y_RFE_OP", "Y_SB_OP", "Y_SH_OP",
  "Y_SLLV_OP", "Y_SLL_OP", "Y_SLTIU_OP", "Y_SLTI_OP", "Y_SLTU_OP",
  "Y_SLT_OP", "Y_SRAV_OP", "Y_SRA_OP", "Y_SRLV_OP", "Y_SRL_OP",
  "Y_SUBU_OP", "Y_SUB_D_OP", "Y_SUB_OP", "Y_SUB_S_OP", "Y_SWC0_OP",
  "Y_SWC1_OP", "Y_SWC2_OP", "Y_SWC3_OP", "Y_SWL_OP", "Y_SWR_OP", "Y_SW_OP",
  "Y_SYSCALL_OP", "Y_TLBP_OP", "Y_TLBR_OP", "Y_TLBWI_OP", "Y_TLBWR_OP",
  "Y_XORI_OP", "Y_XOR_OP", "Y_ABS_POP", "Y_BAL_POP", "Y_BEQZ_POP",
  "Y_BGEU_POP", "Y_BGE_POP", "Y_BGTU_POP", "Y_BGT_POP", "Y_BLEU_POP",
  "Y_BLE_POP", "Y_BLTU_POP", "Y_BLT_POP", "Y_BNEZ_POP", "Y_B_POP",
  "Y_LA_POP", "Y_LD_POP", "Y_LI_POP", "Y_LI_D_POP", "Y_LI_S_POP",
  "Y_L_D_POP", "Y_L_S_POP", "Y_MFC1_D_POP", "Y_MTC1_D_POP", "Y_MOVE_POP",
  "Y_MULOU_POP", "Y_MULO_POP", "Y_MUL_POP", "Y_NEGU_POP", "Y_NEG_POP",
  "Y_NOP_POP", "Y_NOT_POP", "Y_REMU_POP", "Y_REM_POP", "Y_ROL_POP",
  "Y_ROR_POP", "Y_SD_POP", "Y_SEQ_POP", "Y_SGEU_POP", "Y_SGE_POP",
  "Y_SGTU_POP", "Y_SGT_POP", "Y_SLEU_POP", "Y_SLE_POP", "Y_SNE_POP",
  "Y_S_D_POP", "Y_S_S_POP", "Y_ULHU_POP", "Y_ULH_POP", "Y_ULW_POP",
  "Y_USH_POP", "Y_USW_POP", "Y_ALIAS_DIR", "Y_ALIGN_DIR", "Y_ASCII_DIR",
  "Y_ASCIIZ_DIR", "Y_ASM0_DIR", "Y_BGNB_DIR", "Y_BYTE_DIR", "Y_COMM_DIR",
  "Y_DATA_DIR", "Y_DOUBLE_DIR", "Y_ENDB_DIR", "Y_ENDR_DIR", "Y_END_DIR",
  "Y_ENT_DIR", "Y_ERR_DIR", "Y_EXTERN_DIR", "Y_FILE_DIR", "Y_FLOAT_DIR",
  "Y_FMASK_DIR", "Y_FRAME_DIR", "Y_GLOBAL_DIR", "Y_HALF_DIR",
  "Y_K_TEXT_DIR", "Y_K_DATA_DIR", "Y_LABEL_DIR", "Y_LCOMM_DIR",
  "Y_LIVEREG_DIR", "Y_LOC_DIR", "Y_MASK_DIR", "Y_NOALIAS_DIR",
  "Y_OPTIONS_DIR", "Y_RDATA_DIR", "Y_REPEAT_DIR", "Y_SDATA_DIR",
  "Y_SET_DIR", "Y_SPACE_DIR", "Y_STRUCT_DIR", "Y_TEXT_DIR",
  "Y_VERSTAMP_DIR", "Y_VREG_DIR", "Y_WORD_DIR", "':'", "'='", "'('", "')'",
  "'+'", "'-'", "'>'", "$accept", "LINE", "@1", "LBL_CMD", "OPT_LBL",
  "CMD", "@2", "@3", "TERM", "ASM_CODE", "LOAD_OP", "LOAD_COP",
  "LOAD_IMM_OP", "ULOADH_POP", "LOADF_OP", "STORE_OP", "STORE_COP",
  "STOREF_OP", "SYS_OP", "BINARY_OP_I", "BINARY_OPR_I",
  "BINARY_IMM_ARITH_OP", "BINARY_IMM_LOGICAL_OP", "SHIFT_OP",
  "BINARY_OP_NOI", "SUB_OP", "DIV_POP", "MUL_POP", "SET_LE_POP",
  "SET_GT_POP", "SET_GE_POP", "SET_EQ_POP", "MULT_OP", "NULLARY_BR_OP",
  "UNARY_BR_OP", "UNARY_BR_POP", "BINARY_BR_OP", "BR_GT_POP", "BR_GE_POP",
  "BR_LT_POP", "BR_LE_POP", "J_OPS", "B_OP", "MOVE_COP_OP",
  "MOV_FROM_HILO_OP", "MOV_TO_HILO_OP", "MOV_COP_OP", "CTL_COP_OP",
  "FP_ABS_OP", "FP_BINARY_OP", "FP_CONVERT_OP", "FP_NEG_OP", "FP_CMP_OP",
  "ASM_DIRECTIVE", "@4", "@5", "@6", "@7", "@8", "@9", "@10", "ADDRESS",
  "@11", "ADDR", "BR_IMM32", "@12", "IMM16", "UIMM16", "IMM32", "ABS_ADDR",
  "DEST_REG", "SRC1", "SRC2", "DEST", "REG", "SOURCE", "REGISTER",
  "F_DEST", "F_SRC1", "F_SRC2", "FP_REGISTER", "COP_REG", "LABEL",
  "STR_LST", "STR", "EXPRESSION", "@13", "EXPR", "EXPR_LST", "FP_EXPR_LST",
  "OPTIONAL_ID", "@14", "OPT_ID", "ID", "@15", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short int yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,    58,    61,    40,    41,    43,    45,
      62
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short int yyr1[] =
{
       0,   261,   263,   262,   264,   264,   265,   265,   267,   266,
     268,   266,   266,   269,   269,   270,   270,   270,   270,   270,
     270,   270,   270,   270,   270,   270,   270,   270,   270,   270,
     270,   270,   270,   270,   270,   270,   270,   270,   270,   270,
     270,   270,   270,   270,   270,   270,   270,   270,   270,   270,
     270,   270,   270,   270,   270,   270,   270,   270,   270,   270,
     270,   270,   270,   270,   270,   270,   270,   270,   270,   270,
     270,   270,   270,   270,   270,   270,   270,   270,   270,   270,
     270,   270,   270,   270,   270,   270,   270,   270,   270,   270,
     270,   270,   270,   270,   270,   270,   270,   270,   270,   270,
     270,   271,   271,   271,   271,   271,   271,   271,   271,   271,
     272,   272,   272,   273,   274,   274,   275,   275,   275,   276,
     276,   276,   276,   276,   276,   277,   277,   277,   278,   278,
     278,   279,   279,   280,   280,   280,   280,   280,   280,   280,
     281,   281,   281,   282,   282,   282,   282,   283,   283,   283,
     284,   284,   284,   285,   286,   286,   287,   287,   287,   287,
     288,   288,   288,   289,   289,   290,   290,   291,   291,   292,
     292,   293,   293,   294,   294,   294,   294,   294,   294,   294,
     294,   295,   295,   295,   295,   295,   295,   296,   296,   297,
     297,   298,   298,   299,   299,   300,   300,   301,   301,   302,
     302,   302,   302,   303,   303,   304,   304,   305,   305,   306,
     306,   307,   307,   307,   307,   307,   307,   307,   307,   307,
     307,   308,   308,   308,   308,   308,   308,   308,   308,   309,
     309,   310,   310,   310,   310,   310,   310,   310,   310,   311,
     311,   311,   311,   311,   311,   312,   312,   313,   313,   313,
     313,   313,   313,   313,   313,   313,   313,   313,   313,   313,
     313,   313,   313,   313,   313,   313,   313,   313,   313,   313,
     313,   313,   313,   313,   313,   313,   313,   313,   313,   314,
     314,   315,   314,   316,   314,   314,   314,   317,   314,   314,
     314,   314,   314,   314,   318,   314,   314,   314,   314,   314,
     314,   314,   314,   314,   319,   314,   314,   314,   314,   320,
     314,   314,   314,   314,   314,   314,   314,   314,   314,   314,
     314,   314,   314,   314,   314,   314,   314,   314,   314,   314,
     314,   314,   321,   314,   323,   322,   324,   324,   324,   324,
     324,   324,   324,   324,   324,   324,   326,   325,   327,   328,
     329,   329,   329,   329,   329,   330,   330,   330,   331,   332,
     333,   334,   335,   336,   337,   338,   339,   340,   341,   342,
     342,   343,   344,   344,   345,   345,   347,   346,   348,   348,
     349,   349,   349,   350,   350,   352,   351,   353,   353,   355,
     354
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     0,     2,     2,     1,     2,     3,     0,     3,
       0,     3,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     2,     1,     3,     3,     3,     3,     3,     4,     4,
       3,     4,     4,     3,     4,     3,     4,     3,     4,     4,
       4,     4,     3,     4,     4,     3,     3,     4,     4,     4,
       4,     3,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     2,     3,     3,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     2,     2,     3,
       2,     3,     2,     2,     3,     3,     3,     4,     3,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       2,     0,     3,     0,     3,     1,     2,     0,     3,     3,
       1,     2,     1,     2,     0,     3,     2,     2,     1,     2,
       3,     3,     1,     3,     0,     3,     3,     4,     2,     0,
       3,     2,     3,     3,     3,     3,     3,     2,     2,     1,
       2,     1,     2,     2,     2,     2,     1,     2,     1,     2,
       3,     4,     0,     3,     0,     2,     3,     1,     4,     1,
       4,     3,     3,     3,     6,     6,     0,     2,     1,     1,
       1,     6,     1,     3,     3,     1,     3,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     1,     3,     0,     2,     1,     1,
       2,     1,     3,     2,     1,     0,     2,     1,     0,     0,
       2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short int yydefact[] =
{
       2,     0,   389,     1,    14,    13,   230,   229,   144,   143,
     134,   232,   133,   231,   147,   135,   177,   173,   178,   174,
     179,   175,   180,   176,   189,   182,   181,   183,   184,   186,
     185,   190,     0,   221,   222,   223,   224,   225,   226,   227,
     228,   239,   240,   241,   242,   243,   244,   265,   249,   263,
     247,   277,   261,   275,   259,   276,   260,   272,   256,   274,
     258,   278,   262,   267,   251,   268,   252,   273,   257,   271,
     255,   266,   250,   269,   253,   270,   254,   264,   248,   157,
     234,   156,   233,   202,   201,   200,   199,   102,   101,   104,
     103,   113,   110,   116,   111,   112,   106,   107,   105,   211,
     212,   214,   215,   207,   208,   206,   205,   216,   217,   219,
     220,   209,   210,   172,   171,   236,   235,   246,   245,   153,
     148,   137,   109,   131,   119,   120,   140,   150,   146,   145,
     139,   138,   141,   151,   142,   152,   155,   238,   154,   237,
     125,   128,   126,   127,   122,   123,   121,   132,   149,   136,
       0,   204,   187,   194,   193,   192,   191,   198,   197,   196,
     195,   188,   203,     0,   108,     0,     0,     0,   118,   117,
     213,   218,     0,   162,   161,   160,     0,     0,    32,     0,
     159,   158,     0,     0,   124,   169,   168,   167,   166,   165,
     164,   163,   170,   130,   129,   115,   114,     0,     0,     0,
       0,   389,   281,   283,   285,     0,   287,   389,   290,   294,
       0,   298,   385,   389,   302,   389,     0,   304,     0,     0,
     389,   309,   328,   292,   389,   389,     0,     0,     0,     0,
     389,   319,   389,   321,   389,   389,   389,   326,     0,     0,
     332,     3,     0,     5,    12,     8,     0,     0,     0,     0,
       0,     0,     0,     0,    30,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   389,
       0,     0,     0,     0,     0,     0,     0,   389,   389,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    10,
       0,     0,    31,   364,     0,   358,   334,     0,   368,     0,
     365,     0,     0,     0,     0,     0,     0,     0,   334,   334,
     363,   334,     0,   378,   280,   379,     0,     0,   286,   376,
     389,   291,     0,   297,   296,   388,   299,   389,     0,     0,
       0,     0,   308,   376,   329,   293,   311,   389,     0,     0,
       0,     0,   317,   320,   318,   322,   323,   324,   325,   327,
       0,     0,   376,     4,     0,   334,   369,   370,   334,     0,
     334,   334,   334,   334,   334,   366,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     359,    74,   371,   389,   389,   346,   346,   346,   346,   346,
      88,     0,   359,    87,    90,     0,    92,   362,    93,     0,
       0,     0,     0,     0,     0,     0,     0,     6,     0,   390,
      33,    18,     0,   355,     0,     0,    19,   350,   352,    20,
      21,    37,    35,    34,    36,     0,     0,    22,    28,    27,
     279,   374,   282,   373,   284,   381,   389,   288,   289,   384,
     295,   386,   387,   300,   301,   303,   305,   306,     0,   310,
     312,   313,   314,   315,   316,   330,     0,   333,     9,    15,
      16,    17,   349,    23,    24,    25,    26,    29,    40,     0,
      43,     0,    45,   348,     0,    47,     0,     0,    52,     0,
      55,     0,    56,     0,     0,     0,     0,     0,    61,   360,
      75,    76,   389,     0,   389,   389,   389,   389,   389,   389,
     389,   389,   389,    89,    91,    94,    95,    96,     0,    98,
     367,    99,   100,    11,     7,   339,     0,   335,   337,   357,
       0,     0,     0,     0,    65,    63,    64,    62,     0,   372,
       0,   377,   380,   383,   307,   331,    39,    38,    42,    41,
      44,    46,    48,    49,    51,    50,    54,    53,    58,    57,
      60,    59,    67,    66,    69,    68,    71,    70,    73,    72,
      78,   347,    77,    80,    79,    82,    81,    84,    83,    86,
      85,    97,     0,     0,     0,     0,     0,   389,   356,   353,
     354,     0,   375,   382,     0,   341,   343,   336,     0,   342,
       0,   340,     0,     0,   338,     0,     0,     0,   351,   344,
     345
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short int yydefgoto[] =
{
      -1,     1,     2,   241,   242,   243,   354,   406,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   316,   317,   319,   322,   329,   333,
     352,   411,   412,   517,   492,   493,   472,   461,   462,   417,
     294,   379,   488,   391,   396,   309,   380,   299,   364,   509,
     300,   358,   381,   432,   433,   435,   436,   314,   437,   440,
     324,   325,   441,   418,   291
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -415
static const short int yypact[] =
{
    -415,    24,   530,  -415,  -415,  -415,  -415,  -415,  -415,  -415,
    -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,
    -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,
    -415,  -415,    25,  -415,  -415,  -415,  -415,  -415,  -415,  -415,
    -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,
    -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,
    -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,
    -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,
    -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,
    -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,
    -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,
    -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,
    -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,
    -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,
    -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,
      44,  -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,
    -415,  -415,  -415,    44,  -415,    44,    50,    50,  -415,  -415,
    -415,  -415,    44,  -415,  -415,  -415,    44,    44,  -415,    44,
    -415,  -415,    44,    44,  -415,  -415,  -415,  -415,  -415,  -415,
    -415,  -415,  -415,  -415,  -415,  -415,  -415,    44,    44,    44,
      67,    78,  -415,  -415,  -415,    88,  -415,  -415,    89,  -415,
      92,  -415,  -415,  -415,  -415,  -415,    93,  -415,    94,    44,
    -415,  -415,    95,    96,  -415,  -415,    97,    99,   102,   104,
    -415,   120,    78,   121,  -415,    78,    78,   128,   131,    44,
    -415,  -415,   530,  -415,  -415,  -415,    44,     9,    44,    44,
      50,    44,     9,    50,  -415,    44,    44,    44,    44,    44,
      44,    44,    44,    44,    44,    44,    44,    44,    44,  -415,
      44,    44,    44,    44,    44,    44,    44,    44,  -415,     9,
      44,    44,    44,     9,    50,    50,    50,    50,    50,  -415,
    -193,   103,  -415,  -415,    44,  -415,  -415,     3,  -415,   132,
    -415,   133,    44,    44,    44,    44,    44,    44,  -415,  -415,
    -415,  -415,   137,  -415,  -415,  -415,   138,   138,  -415,  -415,
      78,  -415,   135,  -415,  -415,   140,   144,    78,   147,   135,
     153,   154,  -415,  -415,  -415,  -415,  -415,    78,   155,   158,
     159,   160,  -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,
     161,   163,  -415,  -415,    82,  -415,  -415,  -415,  -415,     3,
    -415,  -415,  -415,  -415,  -415,  -415,    -1,    37,    -1,    -1,
      44,    -1,    -1,    44,    44,    44,    44,    44,    44,    44,
    -415,  -415,  -415,  -415,  -415,    44,    44,    44,    44,    44,
    -415,    44,   162,  -415,  -415,     9,  -415,  -415,  -415,     9,
       9,    50,    50,    50,    50,    50,    82,  -415,   165,  -415,
    -415,  -415,     5,    -4,  -171,   166,  -415,  -415,  -415,  -415,
    -415,  -415,  -415,  -415,  -415,    -1,    -1,  -415,  -415,  -415,
    -415,   -82,   138,  -415,   138,   -81,    78,    84,  -415,  -415,
     164,  -415,  -415,  -415,  -415,  -415,   164,  -415,    44,    84,
    -415,  -415,  -415,  -415,  -415,  -415,   172,    84,  -415,  -415,
    -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,    -1,
    -415,    52,  -415,  -415,     3,  -415,     3,    61,  -415,    -1,
    -415,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  -415,  -415,
    -415,  -415,  -415,     3,  -415,  -415,  -415,  -415,  -415,  -415,
    -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,    50,  -415,
    -415,  -415,  -415,  -415,  -415,  -206,    44,  -415,  -185,  -415,
     176,   166,   166,   -75,  -415,  -415,  -415,  -415,   178,  -415,
     179,  -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,
    -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,
    -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,
    -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,
    -415,  -415,    44,   166,   166,   -72,    44,  -415,  -415,  -415,
    -415,   -74,  -415,  -415,   -70,   -68,   -67,  -415,   -66,  -415,
     -65,  -415,    44,    44,  -415,   185,   -64,   -63,  -415,  -415,
    -415
};

/* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] =
{
    -415,  -415,  -415,  -415,  -415,   -50,  -415,  -415,  -341,  -415,
    -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,
    -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,
    -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,
    -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,
    -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,
    -415,  -283,  -415,  -415,  -340,  -415,  -278,  -366,  -119,  -394,
     207,   136,   399,  -415,  -190,  -184,  -143,  -155,  -261,  -373,
    -251,  -238,  -208,  -120,  -350,  -414,  -415,  -172,  -314,  -131,
    -415,  -415,  -415,    -2,  -415
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -390
static const short int yytable[] =
{
     290,   519,   365,   475,   413,   414,   293,   295,   413,   414,
     413,   515,   301,   458,   363,   311,   356,   357,   518,   449,
     295,   523,   295,   532,     3,   427,   428,   405,   429,   295,
     292,   511,   512,   295,   295,   532,   295,   365,   457,   295,
     295,   395,   470,   532,   293,   400,   495,   497,   499,   501,
     572,   293,   573,   574,   295,   310,   310,   538,   298,   293,
     344,   407,   408,   347,   348,   513,   542,   362,   293,   393,
     394,   576,   459,   577,   312,   460,   331,   463,   464,   465,
     466,   467,   529,   313,   529,     4,     5,   521,   522,  -376,
    -376,   398,   399,   318,   321,   361,   351,   323,   328,   330,
     334,   335,   338,   295,   339,   295,   295,   340,   310,   409,
     541,   341,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   343,   345,   579,   580,   401,
     402,   403,   404,   349,   392,   571,   350,   397,   397,   397,
     507,   508,   419,   420,   430,   439,  -389,   431,   438,   443,
     365,   365,   510,   510,   510,   444,   445,   504,   447,   448,
     451,   505,   506,   452,   453,   450,   455,   454,   456,  -361,
     514,   413,   528,   530,   533,   490,   491,   535,   416,   585,
     586,   578,   581,   582,   583,   587,   590,   591,   592,   593,
     598,   594,   353,   599,   600,   595,   540,   434,   446,   315,
       0,     0,     0,     0,     0,   320,     0,     0,     0,     0,
       0,   326,     0,   327,     0,     0,     0,     0,   332,     0,
       0,     0,   336,   337,     0,     0,     0,     0,   342,     0,
     315,     0,   346,   315,   315,     0,   489,     0,     0,     0,
       0,     0,   489,   489,   489,   489,   489,   468,     0,   473,
       0,     0,   478,   480,   520,   415,     0,   510,     0,   415,
       0,   516,     0,     0,   531,     0,     0,   382,     0,     0,
       0,     0,     0,     0,     0,   382,   382,     0,     0,     0,
       0,     0,   489,   489,   560,     0,   562,   563,   564,   565,
     566,   567,   568,   569,   570,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   534,   524,   526,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   315,     0,
       0,     0,     0,   442,     0,   315,   489,     0,   489,     0,
       0,     0,     0,     0,   489,   315,   489,     0,   489,   489,
     489,   489,   489,   489,   489,     0,     0,     0,     0,     0,
     536,     0,     0,     0,     0,   473,     0,     0,     0,     0,
     544,     0,   546,   548,   550,   552,   554,   556,   558,     0,
     296,     0,   297,   575,   561,     0,     0,     0,     0,   302,
       0,   382,   382,   303,   304,     0,   305,     0,     0,   306,
     307,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   308,     0,   383,   384,   385,   386,
     387,   388,   389,   390,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   584,
     410,     0,     0,   588,   315,     0,     0,     0,   421,   422,
     423,   424,   425,   426,     0,     0,     0,     0,     0,   596,
     597,     0,     0,   355,     0,   359,   360,     0,     0,     0,
       0,     0,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   376,   377,   378,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     382,     0,   382,   382,   382,   382,   382,   382,   382,   382,
     382,     0,   469,   471,   474,   476,   477,   479,   481,   482,
     483,   484,   485,   486,   487,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   503,     0,     0,
       0,     0,     0,     4,     5,     0,     0,     0,     0,     0,
       0,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,     0,     0,     0,   589,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,     0,     0,     0,
       0,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   494,   496,   498,   500,   502,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   525,   527,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   537,     0,
     539,     0,     0,     0,     0,     0,   543,     0,   545,     0,
     547,   549,   551,   553,   555,   557,   559
};

static const short int yycheck[] =
{
       2,     5,   253,   369,     5,     6,     7,   150,     5,     6,
       5,     6,   167,   354,   252,   199,     7,     8,   412,   333,
     163,   415,   165,   437,     0,   308,   309,   288,   311,   172,
       5,   404,   405,   176,   177,   449,   179,   288,   352,   182,
     183,   279,     5,   457,     7,   283,   386,   387,   388,   389,
     256,     7,   258,   259,   197,   198,   199,     5,     8,     7,
     232,   254,   255,   235,   236,   406,     5,   251,     7,   277,
     278,   256,   355,   258,     7,   358,   219,   360,   361,   362,
     363,   364,   432,     5,   434,     3,     4,   258,   259,     5,
       6,   281,   282,     5,     5,   250,   239,     5,     5,     5,
       5,     5,     5,   246,     5,   248,   249,     5,   251,     6,
     476,     7,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,     5,     5,   521,   522,   284,
     285,   286,   287,     5,   277,   508,     5,   280,   281,   282,
     401,   402,    10,    10,     7,    10,     6,     9,   320,     5,
     401,   402,   403,   404,   405,   327,     9,   395,     5,     5,
       5,   399,   400,     5,     5,   337,     5,     7,     5,     7,
       5,     5,   254,   254,    10,   383,   384,     5,   297,   573,
     574,     5,   257,     5,     5,   257,   260,   257,   256,   256,
       5,   257,   242,   257,   257,   260,   474,   317,   329,   201,
      -1,    -1,    -1,    -1,    -1,   207,    -1,    -1,    -1,    -1,
      -1,   213,    -1,   215,    -1,    -1,    -1,    -1,   220,    -1,
      -1,    -1,   224,   225,    -1,    -1,    -1,    -1,   230,    -1,
     232,    -1,   234,   235,   236,    -1,   379,    -1,    -1,    -1,
      -1,    -1,   385,   386,   387,   388,   389,   366,    -1,   368,
      -1,    -1,   371,   372,   258,   256,    -1,   508,    -1,   256,
      -1,   256,    -1,    -1,   436,    -1,    -1,   269,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   277,   278,    -1,    -1,    -1,
      -1,    -1,   425,   426,   492,    -1,   494,   495,   496,   497,
     498,   499,   500,   501,   502,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   448,   425,   426,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   320,    -1,
      -1,    -1,    -1,   325,    -1,   327,   469,    -1,   471,    -1,
      -1,    -1,    -1,    -1,   477,   337,   479,    -1,   481,   482,
     483,   484,   485,   486,   487,    -1,    -1,    -1,    -1,    -1,
     469,    -1,    -1,    -1,    -1,   474,    -1,    -1,    -1,    -1,
     479,    -1,   481,   482,   483,   484,   485,   486,   487,    -1,
     163,    -1,   165,   516,   493,    -1,    -1,    -1,    -1,   172,
      -1,   383,   384,   176,   177,    -1,   179,    -1,    -1,   182,
     183,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   197,    -1,   270,   271,   272,   273,
     274,   275,   276,   277,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   572,
     294,    -1,    -1,   576,   436,    -1,    -1,    -1,   302,   303,
     304,   305,   306,   307,    -1,    -1,    -1,    -1,    -1,   592,
     593,    -1,    -1,   246,    -1,   248,   249,    -1,    -1,    -1,
      -1,    -1,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     492,    -1,   494,   495,   496,   497,   498,   499,   500,   501,
     502,    -1,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   376,   377,   378,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   391,    -1,    -1,
      -1,    -1,    -1,     3,     4,    -1,    -1,    -1,    -1,    -1,
      -1,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,   577,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,    -1,    -1,    -1,
      -1,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   385,   386,   387,   388,   389,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   425,   426,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   469,    -1,
     471,    -1,    -1,    -1,    -1,    -1,   477,    -1,   479,    -1,
     481,   482,   483,   484,   485,   486,   487
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short int yystos[] =
{
       0,   262,   263,     0,     3,     4,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   264,   265,   266,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     354,   355,     5,     7,   331,   337,   331,   331,     8,   338,
     341,   338,   331,   331,   331,   331,   331,   331,   331,   336,
     337,   336,     7,     5,   348,   354,   315,   316,     5,   317,
     354,     5,   318,     5,   351,   352,   354,   354,     5,   319,
       5,   337,   354,   320,     5,     5,   354,   354,     5,     5,
       5,     7,   354,     5,   348,     5,   354,   348,   348,     5,
       5,   337,   321,   266,   267,   331,     7,     8,   342,   331,
     331,   338,   336,   342,   339,   341,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   332,
     337,   343,   354,   332,   332,   332,   332,   332,   332,   332,
     332,   334,   337,   343,   343,   342,   335,   337,   335,   335,
     342,   338,   338,   338,   338,   339,   268,   254,   255,     6,
     332,   322,   323,     5,     6,   256,   329,   330,   354,    10,
      10,   332,   332,   332,   332,   332,   332,   322,   322,   322,
       7,     9,   344,   345,   344,   346,   347,   349,   348,    10,
     350,   353,   354,     5,   348,     9,   350,     5,     5,   349,
     348,     5,     5,     5,     7,     5,     5,   349,   269,   322,
     322,   328,   329,   322,   322,   322,   322,   322,   329,   332,
       5,   332,   327,   329,   332,   328,   332,   332,   329,   332,
     329,   332,   332,   332,   332,   332,   332,   332,   333,   337,
     343,   343,   325,   326,   333,   325,   333,   325,   333,   325,
     333,   325,   333,   332,   342,   342,   342,   339,   339,   340,
     341,   340,   340,   269,     5,     6,   256,   324,   330,     5,
     258,   258,   259,   330,   329,   333,   329,   333,   254,   345,
     254,   348,   346,    10,   337,     5,   329,   333,     5,   333,
     327,   328,     5,   333,   329,   333,   329,   333,   329,   333,
     329,   333,   329,   333,   329,   333,   329,   333,   329,   333,
     343,   329,   343,   343,   343,   343,   343,   343,   343,   343,
     343,   340,   256,   258,   259,   337,   256,   258,     5,   330,
     330,   257,     5,     5,   337,   330,   330,   257,   337,   354,
     260,   257,   256,   256,   257,   260,   337,   337,     5,   257,
     257
};

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# if defined (__STDC__) || defined (__cplusplus)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# endif
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { 								\
      yyerror ("syntax error: cannot back up");\
      YYERROR;							\
    }								\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

/* YYLLOC_DEFAULT -- Compute the default location (before the actions
   are run).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)		\
   ((Current).first_line   = (Rhs)[1].first_line,	\
    (Current).first_column = (Rhs)[1].first_column,	\
    (Current).last_line    = (Rhs)[N].last_line,	\
    (Current).last_column  = (Rhs)[N].last_column)
#endif

/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (0)

# define YYDSYMPRINT(Args)			\
do {						\
  if (yydebug)					\
    yysymprint Args;				\
} while (0)

# define YYDSYMPRINTF(Title, Token, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr, 					\
                  Token, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short int *bottom, short int *top)
#else
static void
yy_stack_print (bottom, top)
    short int *bottom;
    short int *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %u), ",
             yyrule - 1, yylno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname [yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname [yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YYDSYMPRINT(Args)
# define YYDSYMPRINTF(Title, Token, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#if defined (YYMAXDEPTH) && YYMAXDEPTH == 0
# undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  register const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
{
  register char *yyd = yydest;
  register const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

#endif /* !YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (yytype < YYNTOKENS)
    {
      YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
# ifdef YYPRINT
      YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
    }
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yydestruct (int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yytype, yyvaluep)
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  switch (yytype)
    {

      default:
        break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  register int yystate;
  register int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short int yyssa[YYINITDEPTH];
  short int *yyss = yyssa;
  register short int *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  register YYSTYPE *yyvsp;



#define YYPOPSTACK   (yyvsp--, yyssp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;


  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short int *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyoverflowlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyoverflowlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	short int *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyoverflowlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YYDSYMPRINTF ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */
  YYDPRINTF ((stderr, "Shifting token %s, ", yytname[yytoken]));

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;


  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 383 "parser.y"
    {parse_error_occurred = 0; scanner_start_line (); }
    break;

  case 6:
#line 390 "parser.y"
    {
			   this_line_labels =
			     cons_label (record_label ((char*)yyvsp[-1].p,
						       text_dir
						       ? current_text_pc ()
						       : current_data_pc (),
						       0),
					 this_line_labels);
				if (yyvsp[-1].p) free(yyvsp[-1].p);
			 }
    break;

  case 7:
#line 402 "parser.y"
    {
		  label *l = record_label ((char*)yyvsp[-2].p, (mem_addr)yyvsp[0].i, 1);
		  if (yyvsp[-2].p) free(yyvsp[-2].p);

		  l->const_flag = 1;
		  clear_labels ();
		}
    break;

  case 8:
#line 413 "parser.y"
    {
		  clear_labels ();
		}
    break;

  case 10:
#line 419 "parser.y"
    {
		  clear_labels ();
		}
    break;

  case 13:
#line 429 "parser.y"
    {
			LINE_PARSE_DONE;
		}
    break;

  case 14:
#line 434 "parser.y"
    {
		  clear_labels ();
		  FILE_PARSE_DONE;
		}
    break;

  case 15:
#line 443 "parser.y"
    {
		  i_type_inst (yyvsp[-2].i == Y_LD_POP ? Y_LW_OP : yyvsp[-2].i,
			       yyvsp[-1].i,
			       addr_expr_reg ((addr_expr *)yyvsp[0].p),
			       addr_expr_imm ((addr_expr *)yyvsp[0].p));
		  if (yyvsp[-2].i == Y_LD_POP)
		    i_type_inst_free (Y_LW_OP,
				      yyvsp[-1].i + 1,
				      addr_expr_reg ((addr_expr *)yyvsp[0].p),
				      incr_expr_offset (addr_expr_imm ((addr_expr *)yyvsp[0].p),
							4));
		  free (((addr_expr *)yyvsp[0].p)->imm);
		  free ((addr_expr *)yyvsp[0].p);
		}
    break;

  case 16:
#line 459 "parser.y"
    {
		  i_type_inst (yyvsp[-2].i, yyvsp[-1].i, addr_expr_reg ((addr_expr *)yyvsp[0].p),
			       addr_expr_imm ((addr_expr *)yyvsp[0].p));
		  free (((addr_expr *)yyvsp[0].p)->imm);
		  free ((addr_expr *)yyvsp[0].p);
		}
    break;

  case 17:
#line 467 "parser.y"
    {
		  i_type_inst_free (yyvsp[-2].i, yyvsp[-1].i, 0, (imm_expr *)yyvsp[0].p);
		}
    break;

  case 18:
#line 473 "parser.y"
    {
		  if (addr_expr_reg ((addr_expr *)yyvsp[0].p))
		    i_type_inst (Y_ADDI_OP, yyvsp[-1].i,
				 addr_expr_reg ((addr_expr *)yyvsp[0].p),
				 addr_expr_imm ((addr_expr *)yyvsp[0].p));
		  else
		    i_type_inst (Y_ORI_OP, yyvsp[-1].i, 0,
				 addr_expr_imm ((addr_expr *)yyvsp[0].p));
		  free (((addr_expr *)yyvsp[0].p)->imm);
		  free ((addr_expr *)yyvsp[0].p);
		}
    break;

  case 19:
#line 487 "parser.y"
    {
		  i_type_inst_free (Y_ORI_OP, yyvsp[-1].i, 0, (imm_expr *)yyvsp[0].p);
		}
    break;

  case 20:
#line 493 "parser.y"
    {
		  int *x = (int *) yyvsp[0].p;

		  i_type_inst (Y_ORI_OP, 1, 0, const_imm_expr (*x));
		  r_type_inst (Y_MTC1_OP, yyvsp[-1].i, 0, 1);
		  i_type_inst (Y_ORI_OP, 1, 0, const_imm_expr (*(x+1)));
		  r_type_inst (Y_MTC1_OP, yyvsp[-1].i + 1, 0, 1);
		}
    break;

  case 21:
#line 504 "parser.y"
    {
		  float x = (float) *((double *) yyvsp[0].p);
		  int *y = (int *) &x;

		  i_type_inst (Y_ORI_OP, 1, 0, const_imm_expr (*y));
		  r_type_inst (Y_MTC1_OP, yyvsp[-1].i, 0, 1);
		}
    break;

  case 22:
#line 514 "parser.y"
    {
#ifdef BIGENDIAN
		  i_type_inst (Y_LWL_OP, yyvsp[-1].i,
			       addr_expr_reg ((addr_expr *)yyvsp[0].p),
			       addr_expr_imm ((addr_expr *)yyvsp[0].p));
		  i_type_inst_free (Y_LWR_OP, yyvsp[-1].i,
				    addr_expr_reg ((addr_expr *)yyvsp[0].p),
				    incr_expr_offset (addr_expr_imm ((addr_expr *)yyvsp[0].p),
						      3));
#else
		  i_type_inst_free (Y_LWL_OP, yyvsp[-1].i,
				    addr_expr_reg ((addr_expr *)yyvsp[0].p),
				    incr_expr_offset (addr_expr_imm ((addr_expr *)yyvsp[0].p),
						      3));
		  i_type_inst (Y_LWR_OP, yyvsp[-1].i,
			       addr_expr_reg ((addr_expr *)yyvsp[0].p),
			       addr_expr_imm ((addr_expr *)yyvsp[0].p));
#endif
		  free (((addr_expr *)yyvsp[0].p)->imm);
		  free ((addr_expr *)yyvsp[0].p);
		}
    break;

  case 23:
#line 538 "parser.y"
    {
#ifdef BIGENDIAN
		  i_type_inst ((yyvsp[-2].i == Y_ULH_POP ? Y_LB_OP : Y_LBU_OP),
			       yyvsp[-1].i,
			       addr_expr_reg ((addr_expr *)yyvsp[0].p),
			       addr_expr_imm ((addr_expr *)yyvsp[0].p));
		  i_type_inst_free (Y_LBU_OP, 1,
				    addr_expr_reg ((addr_expr *)yyvsp[0].p),
				    incr_expr_offset (addr_expr_imm ((addr_expr *)yyvsp[0].p),
						      1));
#else
		  i_type_inst_free ((yyvsp[-2].i == Y_ULH_POP ? Y_LB_OP : Y_LBU_OP),
				    yyvsp[-1].i,
				    addr_expr_reg ((addr_expr *)yyvsp[0].p),
				    incr_expr_offset (addr_expr_imm ((addr_expr *)yyvsp[0].p),
						      1));
		  i_type_inst (Y_LBU_OP, 1,
			       addr_expr_reg ((addr_expr *)yyvsp[0].p),
			       addr_expr_imm ((addr_expr *)yyvsp[0].p));
#endif
		  r_sh_type_inst (Y_SLL_OP, yyvsp[-1].i, yyvsp[-1].i, 8);
		  r_type_inst (Y_OR_OP, yyvsp[-1].i, yyvsp[-1].i, 1);
		  free (((addr_expr *)yyvsp[0].p)->imm);
		  free ((addr_expr *)yyvsp[0].p);
		}
    break;

  case 24:
#line 566 "parser.y"
    {
		  i_type_inst (Y_LWC1_OP, yyvsp[-1].i,
			       addr_expr_reg ((addr_expr *)yyvsp[0].p),
			       addr_expr_imm ((addr_expr *)yyvsp[0].p));
		  if (yyvsp[-2].i == Y_L_D_POP)
		    i_type_inst_free (Y_LWC1_OP, yyvsp[-1].i + 1,
				      addr_expr_reg ((addr_expr *)yyvsp[0].p),
				      incr_expr_offset (addr_expr_imm ((addr_expr *)yyvsp[0].p),
							4));
		  free (((addr_expr *)yyvsp[0].p)->imm);
		  free ((addr_expr *)yyvsp[0].p);
		}
    break;

  case 25:
#line 581 "parser.y"
    {
		  i_type_inst (yyvsp[-2].i == Y_SD_POP ? Y_SW_OP : yyvsp[-2].i,
			       yyvsp[-1].i,
			       addr_expr_reg ((addr_expr *)yyvsp[0].p),
			       addr_expr_imm ((addr_expr *)yyvsp[0].p));
		  if (yyvsp[-2].i == Y_SD_POP)
		    i_type_inst_free (Y_SW_OP, yyvsp[-1].i + 1,
				      addr_expr_reg ((addr_expr *)yyvsp[0].p),
				      incr_expr_offset (addr_expr_imm ((addr_expr *)yyvsp[0].p),
							4));
		  free (((addr_expr *)yyvsp[0].p)->imm);
		  free ((addr_expr *)yyvsp[0].p);
		}
    break;

  case 26:
#line 597 "parser.y"
    {
		  i_type_inst (yyvsp[-2].i, yyvsp[-1].i,
			       addr_expr_reg ((addr_expr *)yyvsp[0].p),
			       addr_expr_imm ((addr_expr *)yyvsp[0].p));
		  free (((addr_expr *)yyvsp[0].p)->imm);
		  free ((addr_expr *)yyvsp[0].p);
		}
    break;

  case 27:
#line 607 "parser.y"
    {
#ifdef BIGENDIAN
		  i_type_inst (Y_SWL_OP, yyvsp[-1].i,
			       addr_expr_reg ((addr_expr *)yyvsp[0].p),
			       addr_expr_imm ((addr_expr *)yyvsp[0].p));
		  i_type_inst_free (Y_SWR_OP, yyvsp[-1].i,
				    addr_expr_reg ((addr_expr *)yyvsp[0].p),
				    incr_expr_offset (addr_expr_imm ((addr_expr *)yyvsp[0].p),
						      3));
#else
		  i_type_inst_free (Y_SWL_OP, yyvsp[-1].i,
				    addr_expr_reg ((addr_expr *)yyvsp[0].p),
				    incr_expr_offset (addr_expr_imm ((addr_expr *)yyvsp[0].p),
						      3));
		  i_type_inst (Y_SWR_OP, yyvsp[-1].i,
			       addr_expr_reg ((addr_expr *)yyvsp[0].p),
			       addr_expr_imm ((addr_expr *)yyvsp[0].p));
#endif
		  free (((addr_expr *)yyvsp[0].p)->imm);
		  free ((addr_expr *)yyvsp[0].p);
		}
    break;

  case 28:
#line 631 "parser.y"
    {
		  i_type_inst (Y_SB_OP, yyvsp[-1].i,
			       addr_expr_reg ((addr_expr *)yyvsp[0].p),
			       addr_expr_imm ((addr_expr *)yyvsp[0].p));

		  /* ROL SRC, SRC, 8 */
		  r_sh_type_inst (Y_SLL_OP, 1, yyvsp[-1].i, 24);
		  r_sh_type_inst (Y_SRL_OP, yyvsp[-1].i, yyvsp[-1].i, 8);
		  r_type_inst (Y_OR_OP, yyvsp[-1].i, yyvsp[-1].i, 1);

		  i_type_inst_free (Y_SB_OP, yyvsp[-1].i,
				    addr_expr_reg ((addr_expr *)yyvsp[0].p),
				    incr_expr_offset (addr_expr_imm ((addr_expr *)yyvsp[0].p),
						      1));
		  /* ROR SRC, SRC, 8 */
		  r_sh_type_inst (Y_SRL_OP, 1, yyvsp[-1].i, 24);
		  r_sh_type_inst (Y_SLL_OP, yyvsp[-1].i, yyvsp[-1].i, 8);
		  r_type_inst (Y_OR_OP, yyvsp[-1].i, yyvsp[-1].i, 1);

		  free (((addr_expr *)yyvsp[0].p)->imm);
		  free ((addr_expr *)yyvsp[0].p);
		}
    break;

  case 29:
#line 656 "parser.y"
    {
		  i_type_inst (Y_SWC1_OP, yyvsp[-1].i,
			       addr_expr_reg ((addr_expr *)yyvsp[0].p),
			       addr_expr_imm ((addr_expr *)yyvsp[0].p));
		  if (yyvsp[-2].i == Y_S_D_POP)
		    i_type_inst_free (Y_SWC1_OP, yyvsp[-1].i + 1,
				      addr_expr_reg ((addr_expr *)yyvsp[0].p),
				      incr_expr_offset (addr_expr_imm ((addr_expr *)yyvsp[0].p),
							4));
		  free (((addr_expr *)yyvsp[0].p)->imm);
		  free ((addr_expr *)yyvsp[0].p);
		}
    break;

  case 30:
#line 671 "parser.y"
    {
		  r_type_inst (yyvsp[0].i, 0, 0, 0);
		}
    break;

  case 31:
#line 677 "parser.y"
    {
		  if (yyvsp[0].i == 1)
		    yyerror ("Breakpoint 1 is reserved for debugger");
		  r_type_inst (yyvsp[-1].i, yyvsp[0].i, 0, 0);
		}
    break;

  case 32:
#line 685 "parser.y"
    {
		  nop_inst ();
		}
    break;

  case 33:
#line 691 "parser.y"
    {
		  if (yyvsp[-1].i != yyvsp[0].i)
		    r_type_inst (Y_ADDU_OP, yyvsp[-1].i, 0, yyvsp[0].i);

		  i_type_inst_free (Y_BGEZ_OP, 0, yyvsp[0].i, branch_offset (2));
		  r_type_inst (Y_SUB_OP, yyvsp[-1].i, 0, yyvsp[0].i);
		}
    break;

  case 34:
#line 701 "parser.y"
    {
		  r_type_inst (Y_SUB_OP, yyvsp[-1].i, 0, yyvsp[0].i);
		}
    break;

  case 35:
#line 707 "parser.y"
    {
		  r_type_inst (Y_SUBU_OP, yyvsp[-1].i, 0, yyvsp[0].i);
		}
    break;

  case 36:
#line 713 "parser.y"
    {
		  r_type_inst (Y_NOR_OP, yyvsp[-1].i, yyvsp[0].i, 0);
		}
    break;

  case 37:
#line 719 "parser.y"
    {
		  r_type_inst (Y_ADDU_OP, yyvsp[-1].i, 0, yyvsp[0].i);
		}
    break;

  case 38:
#line 725 "parser.y"
    {
		  r_type_inst (yyvsp[-3].i, yyvsp[-2].i, yyvsp[-1].i, yyvsp[0].i);
		}
    break;

  case 39:
#line 731 "parser.y"
    {
		  i_type_inst_free (op_to_imm_op (yyvsp[-3].i), yyvsp[-2].i, yyvsp[-1].i,
				    (imm_expr *)yyvsp[0].p);
		}
    break;

  case 40:
#line 738 "parser.y"
    {
		  i_type_inst_free (op_to_imm_op (yyvsp[-2].i), yyvsp[-1].i, yyvsp[-1].i,
				    (imm_expr *)yyvsp[0].p);
		}
    break;

  case 41:
#line 745 "parser.y"
    {
		  r_type_inst (yyvsp[-3].i, yyvsp[-2].i, yyvsp[0].i, yyvsp[-1].i);
		}
    break;

  case 42:
#line 751 "parser.y"
    {
		  r_sh_type_inst (op_to_imm_op (yyvsp[-3].i), yyvsp[-2].i, yyvsp[-1].i, yyvsp[0].i);
		}
    break;

  case 43:
#line 757 "parser.y"
    {
		  r_sh_type_inst (op_to_imm_op (yyvsp[-2].i), yyvsp[-1].i, yyvsp[-1].i, yyvsp[0].i);
		}
    break;

  case 44:
#line 763 "parser.y"
    {
		  i_type_inst_free (yyvsp[-3].i, yyvsp[-2].i, yyvsp[-1].i, (imm_expr *)yyvsp[0].p);
		}
    break;

  case 45:
#line 769 "parser.y"
    {
		  i_type_inst_free (yyvsp[-2].i, yyvsp[-1].i, yyvsp[-1].i, (imm_expr *)yyvsp[0].p);
		}
    break;

  case 46:
#line 774 "parser.y"
    {
		  i_type_inst_free (yyvsp[-3].i, yyvsp[-2].i, yyvsp[-1].i, (imm_expr *)yyvsp[0].p);
		}
    break;

  case 47:
#line 780 "parser.y"
    {
		  i_type_inst_free (yyvsp[-2].i, yyvsp[-1].i, yyvsp[-1].i, (imm_expr *)yyvsp[0].p);
		}
    break;

  case 48:
#line 786 "parser.y"
    {
		  if ((yyvsp[0].i < 0) || (31 < yyvsp[0].i))
		    yywarn("Shift distance can only be in the range 0..31");
		  r_sh_type_inst (yyvsp[-3].i, yyvsp[-2].i, yyvsp[-1].i, yyvsp[0].i);
		}
    break;

  case 49:
#line 794 "parser.y"
    {
		  r_type_inst (imm_op_to_op (yyvsp[-3].i), yyvsp[-2].i, yyvsp[0].i, yyvsp[-1].i);
		}
    break;

  case 50:
#line 800 "parser.y"
    {
		  r_type_inst (yyvsp[-3].i, yyvsp[-2].i, yyvsp[-1].i, yyvsp[0].i);
		}
    break;

  case 51:
#line 806 "parser.y"
    {
		  if (bare_machine && !accept_pseudo_insts)
		    yyerror ("Immediate form not allowed in bare machine");
		  else
		    {
		      if (!zero_imm ((imm_expr *)yyvsp[0].p))
			/* Use $at */
			i_type_inst (Y_ORI_OP, 1, 0, (imm_expr *)yyvsp[0].p);
		      r_type_inst (yyvsp[-3].i,
				   yyvsp[-2].i,
				   yyvsp[-1].i,
				   (zero_imm ((imm_expr *)yyvsp[0].p) ? 0 : 1));
		    }
		  free ((imm_expr *)yyvsp[0].p);
		}
    break;

  case 52:
#line 824 "parser.y"
    {
		  check_uimm_range ((imm_expr *)yyvsp[0].p, UIMM_MIN, UIMM_MAX);
		  if (bare_machine && !accept_pseudo_insts)
		    yyerror ("Immediate form not allowed in bare machine");
		  else
		    {
		      if (!zero_imm ((imm_expr *)yyvsp[0].p))
			/* Use $at */
			i_type_inst (Y_ORI_OP, 1, 0, (imm_expr *)yyvsp[0].p);
		      r_type_inst (yyvsp[-2].i,
				   yyvsp[-1].i,
				   yyvsp[-1].i,
				   (zero_imm ((imm_expr *)yyvsp[0].p) ? 0 : 1));
		    }
		  free ((imm_expr *)yyvsp[0].p);
		}
    break;

  case 53:
#line 843 "parser.y"
    {
		  r_type_inst (yyvsp[-3].i, yyvsp[-2].i, yyvsp[-1].i, yyvsp[0].i);
		}
    break;

  case 54:
#line 849 "parser.y"
    {
		  int val = eval_imm_expr ((imm_expr *)yyvsp[0].p);

		  if (bare_machine && !accept_pseudo_insts)
		    yyerror ("Immediate form not allowed in bare machine");
		  else
		    i_type_inst (yyvsp[-3].i == Y_SUB_OP ? Y_ADDI_OP
				 : yyvsp[-3].i == Y_SUBU_OP ? Y_ADDIU_OP
				 : (fatal_error ("Bad SUB_OP\n"), 0),
				 yyvsp[-2].i,
				 yyvsp[-1].i,
				 make_imm_expr (-val, NULL, 0));
		  free ((imm_expr *)yyvsp[0].p);
		}
    break;

  case 55:
#line 866 "parser.y"
    {
		  int val = eval_imm_expr ((imm_expr *)yyvsp[0].p);

		  if (bare_machine && !accept_pseudo_insts)
		    yyerror ("Immediate form not allowed in bare machine");
		  else
		    i_type_inst (yyvsp[-2].i == Y_SUB_OP ? Y_ADDI_OP
				 : yyvsp[-2].i == Y_SUBU_OP ? Y_ADDIU_OP
				 : (fatal_error ("Bad SUB_OP\n"), 0),
				 yyvsp[-1].i,
				 yyvsp[-1].i,
				 make_imm_expr (-val, NULL, 0));
		  free ((imm_expr *)yyvsp[0].p);
		}
    break;

  case 56:
#line 883 "parser.y"
    {
		  /* The hardware divide operation (ignore 1st arg) */
		  if (yyvsp[-2].i != Y_DIV_OP && yyvsp[-2].i != Y_DIVU_OP)
		    yyerror ("REM requires 3 arguments");
		  else
		    r_type_inst (yyvsp[-2].i, 0, yyvsp[-1].i, yyvsp[0].i);
		}
    break;

  case 57:
#line 892 "parser.y"
    {
		  /* Pseudo divide operations */
		  div_inst (yyvsp[-3].i, yyvsp[-2].i, yyvsp[-1].i, yyvsp[0].i, 0);
		}
    break;

  case 58:
#line 898 "parser.y"
    {
		  if (zero_imm ((imm_expr *)yyvsp[0].p))
		    yyerror ("Divide by zero");
		  else
		    {
		      /* Use $at */
		      i_type_inst_free (Y_ORI_OP, 1, 0, (imm_expr *)yyvsp[0].p);
		      div_inst (yyvsp[-3].i, yyvsp[-2].i, yyvsp[-1].i, 1, 1);
		    }
		}
    break;

  case 59:
#line 911 "parser.y"
    {
		  mult_inst (yyvsp[-3].i, yyvsp[-2].i, yyvsp[-1].i, yyvsp[0].i);
		}
    break;

  case 60:
#line 916 "parser.y"
    {
		  if (zero_imm ((imm_expr *)yyvsp[0].p))
		    /* Optimize: n * 0 == 0 */
		    i_type_inst_free (Y_ORI_OP, yyvsp[-2].i, 0, (imm_expr *)yyvsp[0].p);
		  else
		    {
		      /* Use $at */
		      i_type_inst_free (Y_ORI_OP, 1, 0, (imm_expr *)yyvsp[0].p);
		      mult_inst (yyvsp[-3].i, yyvsp[-2].i, yyvsp[-1].i, 1);
		    }
		}
    break;

  case 61:
#line 930 "parser.y"
    {
		  r_type_inst (yyvsp[-2].i, 0, yyvsp[-1].i, yyvsp[0].i);
		}
    break;

  case 62:
#line 936 "parser.y"
    {
		  r_type_inst (Y_SUBU_OP, 1, 0, yyvsp[0].i);
		  r_type_inst (Y_SLLV_OP, 1, 1, yyvsp[-1].i);
		  r_type_inst (Y_SRLV_OP, yyvsp[-2].i, yyvsp[0].i, yyvsp[-1].i);
		  r_type_inst (Y_OR_OP, yyvsp[-2].i, yyvsp[-2].i, 1);
		}
    break;

  case 63:
#line 945 "parser.y"
    {
		  r_type_inst (Y_SUBU_OP, 1, 0, yyvsp[0].i);
		  r_type_inst (Y_SRLV_OP, 1, 1, yyvsp[-1].i);
		  r_type_inst (Y_SLLV_OP, yyvsp[-2].i, yyvsp[0].i, yyvsp[-1].i);
		  r_type_inst (Y_OR_OP, yyvsp[-2].i, yyvsp[-2].i, 1);
		}
    break;

  case 64:
#line 954 "parser.y"
    {
		  long dist = eval_imm_expr ((imm_expr *)yyvsp[0].p);

		  check_imm_range ((imm_expr *)yyvsp[0].p, 0, 31);
		  r_sh_type_inst (Y_SLL_OP, 1, yyvsp[-1].i, -dist);
		  r_sh_type_inst (Y_SRL_OP, yyvsp[-2].i, yyvsp[-1].i, dist);
		  r_type_inst (Y_OR_OP, yyvsp[-2].i, yyvsp[-2].i, 1);
		  free ((imm_expr *)yyvsp[0].p);
		}
    break;

  case 65:
#line 966 "parser.y"
    {
		  long dist = eval_imm_expr ((imm_expr *)yyvsp[0].p);

		  check_imm_range ((imm_expr *)yyvsp[0].p, 0, 31);
		  r_sh_type_inst (Y_SRL_OP, 1, yyvsp[-1].i, -dist);
		  r_sh_type_inst (Y_SLL_OP, yyvsp[-2].i, yyvsp[-1].i, dist);
		  r_type_inst (Y_OR_OP, yyvsp[-2].i, yyvsp[-2].i, 1);
		  free ((imm_expr *)yyvsp[0].p);
		}
    break;

  case 66:
#line 979 "parser.y"
    {
		  set_le_inst (yyvsp[-3].i, yyvsp[-2].i, yyvsp[-1].i, yyvsp[0].i);
		}
    break;

  case 67:
#line 984 "parser.y"
    {
		  if (!zero_imm ((imm_expr *)yyvsp[0].p))
		    /* Use $at */
		    i_type_inst (Y_ORI_OP, 1, 0, (imm_expr *)yyvsp[0].p);
		  set_le_inst (yyvsp[-3].i, yyvsp[-2].i, yyvsp[-1].i,
			       (zero_imm ((imm_expr *)yyvsp[0].p) ? 0 : 1));
		  free ((imm_expr *)yyvsp[0].p);
		}
    break;

  case 68:
#line 995 "parser.y"
    {
		  set_gt_inst (yyvsp[-3].i, yyvsp[-2].i, yyvsp[-1].i, yyvsp[0].i);
		}
    break;

  case 69:
#line 1000 "parser.y"
    {
		  if (!zero_imm ((imm_expr *)yyvsp[0].p))
		    /* Use $at */
		    i_type_inst (Y_ORI_OP, 1, 0, (imm_expr *)yyvsp[0].p);
		  set_gt_inst (yyvsp[-3].i, yyvsp[-2].i, yyvsp[-1].i,
			       (zero_imm ((imm_expr *)yyvsp[0].p) ? 0 : 1));
		  free ((imm_expr *)yyvsp[0].p);
		}
    break;

  case 70:
#line 1012 "parser.y"
    {
		  set_ge_inst (yyvsp[-3].i, yyvsp[-2].i, yyvsp[-1].i, yyvsp[0].i);
		}
    break;

  case 71:
#line 1017 "parser.y"
    {
		  if (!zero_imm ((imm_expr *)yyvsp[0].p))
		    /* Use $at */
		    i_type_inst (Y_ORI_OP, 1, 0, (imm_expr *)yyvsp[0].p);
		  set_ge_inst (yyvsp[-3].i, yyvsp[-2].i, yyvsp[-1].i,
			       (zero_imm ((imm_expr *)yyvsp[0].p) ? 0 : 1));
		  free ((imm_expr *)yyvsp[0].p);
		}
    break;

  case 72:
#line 1028 "parser.y"
    {
		  set_eq_inst (yyvsp[-3].i, yyvsp[-2].i, yyvsp[-1].i, yyvsp[0].i);
		}
    break;

  case 73:
#line 1033 "parser.y"
    {
		  if (!zero_imm ((imm_expr *)yyvsp[0].p))
		    /* Use $at */
		    i_type_inst (Y_ORI_OP, 1, 0, (imm_expr *)yyvsp[0].p);
		  set_eq_inst (yyvsp[-3].i, yyvsp[-2].i, yyvsp[-1].i,
			       (zero_imm ((imm_expr *)yyvsp[0].p) ? 0 : 1));
		  free ((imm_expr *)yyvsp[0].p);
		}
    break;

  case 74:
#line 1044 "parser.y"
    {
		  i_type_inst_free (yyvsp[-1].i, 0, 0, (imm_expr *)yyvsp[0].p);
		}
    break;

  case 75:
#line 1050 "parser.y"
    {
		  i_type_inst_free (yyvsp[-2].i, 0, yyvsp[-1].i, (imm_expr *)yyvsp[0].p);
		}
    break;

  case 76:
#line 1056 "parser.y"
    {
		  i_type_inst_free (yyvsp[-2].i == Y_BEQZ_POP ? Y_BEQ_OP : Y_BNE_OP,
			       0, yyvsp[-1].i, (imm_expr *)yyvsp[0].p);
		}
    break;

  case 77:
#line 1063 "parser.y"
    {
		  i_type_inst_free (yyvsp[-3].i, yyvsp[-1].i, yyvsp[-2].i, (imm_expr *)yyvsp[0].p);
		}
    break;

  case 78:
#line 1068 "parser.y"
    {
		  if (bare_machine && !accept_pseudo_insts)
		    yyerror ("Immediate form not allowed in bare machine");
		  else
		    {
		      if (zero_imm ((imm_expr *)yyvsp[-1].p))
			i_type_inst (yyvsp[-3].i, yyvsp[-2].i,
				     (zero_imm ((imm_expr *)yyvsp[-1].p) ? 0 : 1),
				     (imm_expr *)yyvsp[0].p);
		      else
			{
			  /* Use $at */
			  i_type_inst (Y_ORI_OP, 1, 0, (imm_expr *)yyvsp[-1].p);
			  i_type_inst (yyvsp[-3].i, yyvsp[-2].i,
				       (zero_imm ((imm_expr *)yyvsp[-1].p) ? 0 : 1),
				       (imm_expr *)yyvsp[0].p);
			}
		    }
		  free ((imm_expr *)yyvsp[-1].p);
		  free ((imm_expr *)yyvsp[0].p);
		}
    break;

  case 79:
#line 1092 "parser.y"
    {
		  r_type_inst (yyvsp[-3].i == Y_BGT_POP ? Y_SLT_OP : Y_SLTU_OP,
			       1, yyvsp[-1].i, yyvsp[-2].i); /* Use $at */
		  i_type_inst_free (Y_BNE_OP, 0, 1, (imm_expr *)yyvsp[0].p);
		}
    break;

  case 80:
#line 1099 "parser.y"
    {
		  if (yyvsp[-3].i == Y_BGT_POP)
		    {
		      /* Use $at */
		      i_type_inst_free (Y_SLTI_OP, 1, yyvsp[-2].i,
					incr_expr_offset ((imm_expr *)yyvsp[-1].p, 1));
		      i_type_inst (Y_BEQ_OP, 0, 1, (imm_expr *)yyvsp[0].p);
		    }
		  else
		    {
		      /* Use $at */
		      /* Can't add 1 to immediate since 0xffffffff+1 = 0 < 1 */
		      i_type_inst (Y_ORI_OP, 1, 0, (imm_expr *)yyvsp[-1].p);
		      i_type_inst_free (Y_BEQ_OP, yyvsp[-2].i, 1, branch_offset (3));
		      r_type_inst (Y_SLTU_OP, 1, yyvsp[-2].i, 1);
		      i_type_inst (Y_BEQ_OP, 0, 1, (imm_expr *)yyvsp[0].p);
		    }
		  free ((imm_expr *)yyvsp[-1].p);
		  free ((imm_expr *)yyvsp[0].p);
		}
    break;

  case 81:
#line 1122 "parser.y"
    {
		  r_type_inst (yyvsp[-3].i == Y_BGE_POP ? Y_SLT_OP : Y_SLTU_OP,
			       1, yyvsp[-2].i, yyvsp[-1].i); /* Use $at */
		  i_type_inst_free (Y_BEQ_OP, 0, 1, (imm_expr *)yyvsp[0].p);
		}
    break;

  case 82:
#line 1129 "parser.y"
    {
		  i_type_inst (yyvsp[-3].i == Y_BGE_POP ? Y_SLTI_OP : Y_SLTIU_OP,
			       1, yyvsp[-2].i, (imm_expr *)yyvsp[-1].p); /* Use $at */
		  i_type_inst_free (Y_BEQ_OP, 0, 1, (imm_expr *)yyvsp[0].p);
		  free ((imm_expr *)yyvsp[-1].p);
		}
    break;

  case 83:
#line 1138 "parser.y"
    {
		  r_type_inst (yyvsp[-3].i == Y_BLT_POP ? Y_SLT_OP : Y_SLTU_OP,
			       1, yyvsp[-2].i, yyvsp[-1].i); /* Use $at */
		  i_type_inst_free (Y_BNE_OP, 0, 1, (imm_expr *)yyvsp[0].p);
		}
    break;

  case 84:
#line 1145 "parser.y"
    {
		  i_type_inst (yyvsp[-3].i == Y_BLT_POP ? Y_SLTI_OP : Y_SLTIU_OP,
			       1, yyvsp[-2].i, (imm_expr *)yyvsp[-1].p); /* Use $at */
		  i_type_inst_free (Y_BNE_OP, 0, 1, (imm_expr *)yyvsp[0].p);
		  free ((imm_expr *)yyvsp[-1].p);
		}
    break;

  case 85:
#line 1154 "parser.y"
    {
		  r_type_inst (yyvsp[-3].i == Y_BLE_POP ? Y_SLT_OP : Y_SLTU_OP,
			       1, yyvsp[-1].i, yyvsp[-2].i); /* Use $at */
		  i_type_inst_free (Y_BEQ_OP, 0, 1, (imm_expr *)yyvsp[0].p);
		}
    break;

  case 86:
#line 1161 "parser.y"
    {
		  if (yyvsp[-3].i == Y_BLE_POP)
		    {
		      /* Use $at */
		      i_type_inst_free (Y_SLTI_OP, 1, yyvsp[-2].i,
					incr_expr_offset ((imm_expr *)yyvsp[-1].p, 1));
		      i_type_inst (Y_BNE_OP, 0, 1, (imm_expr *)yyvsp[0].p);
		    }
		  else
		    {
		      /* Use $at */
		      /* Can't add 1 to immediate since 0xffffffff+1 = 0 < 1 */
		      i_type_inst (Y_ORI_OP, 1, 0, (imm_expr *)yyvsp[-1].p);
		      i_type_inst (Y_BEQ_OP, yyvsp[-2].i, 1, (imm_expr *)yyvsp[0].p);
		      r_type_inst (Y_SLTU_OP, 1, yyvsp[-2].i, 1);
		      i_type_inst (Y_BNE_OP, 0, 1, (imm_expr *)yyvsp[0].p);
		    }
		  free ((imm_expr *)yyvsp[-1].p);
		  free ((imm_expr *)yyvsp[0].p);
		}
    break;

  case 87:
#line 1184 "parser.y"
    {
		  if ((yyvsp[-1].i == Y_J_OP) || (yyvsp[-1].i == Y_JR_OP))
		    j_type_inst (Y_J_OP, (imm_expr *)yyvsp[0].p);
		  else if ((yyvsp[-1].i == Y_JAL_OP) || (yyvsp[-1].i == Y_JALR_OP))
		    j_type_inst (Y_JAL_OP, (imm_expr *)yyvsp[0].p);
		  free ((imm_expr *)yyvsp[0].p);
		}
    break;

  case 88:
#line 1194 "parser.y"
    {
		  if ((yyvsp[-1].i == Y_J_OP) || (yyvsp[-1].i == Y_JR_OP))
		    r_type_inst (Y_JR_OP, 0, yyvsp[0].i, 0);
		  else if ((yyvsp[-1].i == Y_JAL_OP) || (yyvsp[-1].i == Y_JALR_OP))
		    r_type_inst (Y_JALR_OP, 31, yyvsp[0].i, 0);
		}
    break;

  case 89:
#line 1203 "parser.y"
    {
		  if ((yyvsp[-2].i == Y_J_OP) || (yyvsp[-2].i == Y_JR_OP))
		    r_type_inst (Y_JR_OP, 0, yyvsp[0].i, 0);
		  else if ((yyvsp[-2].i == Y_JAL_OP) || (yyvsp[-2].i == Y_JALR_OP))
		    r_type_inst (Y_JALR_OP, yyvsp[-1].i, yyvsp[0].i, 0);
		}
    break;

  case 90:
#line 1212 "parser.y"
    {
		  i_type_inst_free ((yyvsp[-1].i == Y_BAL_POP ? Y_BGEZAL_OP : Y_BGEZ_OP),
				    0, 0, (imm_expr *)yyvsp[0].p);
		}
    break;

  case 91:
#line 1220 "parser.y"
    {
		  r_type_inst (yyvsp[-2].i, yyvsp[-1].i, yyvsp[0].i, 0);
		}
    break;

  case 92:
#line 1226 "parser.y"
    {
		  r_type_inst (yyvsp[-1].i, yyvsp[0].i, 0, 0);
		}
    break;

  case 93:
#line 1232 "parser.y"
    {
		  r_type_inst (yyvsp[-1].i, 0, yyvsp[0].i, 0);
		}
    break;

  case 94:
#line 1238 "parser.y"
    {
		  if (yyvsp[-2].i == Y_MFC1_D_POP)
		    {
		      r_type_inst (Y_MFC1_OP, yyvsp[0].i, 0, yyvsp[-1].i);
		      r_type_inst (Y_MFC1_OP, yyvsp[0].i + 1, 0, yyvsp[-1].i + 1);
		    }
		  else if (yyvsp[-2].i == Y_MTC1_D_POP)
		    {
		      r_type_inst (Y_MTC1_OP, yyvsp[0].i, 0, yyvsp[-1].i);
		      r_type_inst (Y_MTC1_OP, yyvsp[0].i + 1, 0, yyvsp[-1].i + 1);
		    }
		  else
		    r_type_inst (yyvsp[-2].i, yyvsp[0].i, 0, yyvsp[-1].i);
		}
    break;

  case 95:
#line 1255 "parser.y"
    {
		  r_type_inst (yyvsp[-2].i, yyvsp[0].i, 0, yyvsp[-1].i);
		}
    break;

  case 96:
#line 1261 "parser.y"
    {
		  r_type_inst (yyvsp[-2].i, yyvsp[-1].i, yyvsp[0].i, 0);
		}
    break;

  case 97:
#line 1267 "parser.y"
    {
		  r_type_inst (yyvsp[-3].i, yyvsp[-2].i, yyvsp[-1].i, yyvsp[0].i);
		}
    break;

  case 98:
#line 1273 "parser.y"
    {
		  r_type_inst (yyvsp[-2].i, yyvsp[-1].i, yyvsp[0].i, 0);
		}
    break;

  case 99:
#line 1279 "parser.y"
    {
		  r_type_inst (yyvsp[-2].i, yyvsp[-1].i, yyvsp[0].i, 0);
		}
    break;

  case 100:
#line 1285 "parser.y"
    {
		  r_cond_type_inst (yyvsp[-2].i, yyvsp[-1].i, yyvsp[0].i);
		}
    break;

  case 280:
#line 1564 "parser.y"
    {
		  align_data (yyvsp[0].i);
		}
    break;

  case 281:
#line 1568 "parser.y"
    {null_term = 0;}
    break;

  case 282:
#line 1569 "parser.y"
    {
		  if (text_dir)
		    yyerror ("Can't put data in text segment");
		}
    break;

  case 283:
#line 1574 "parser.y"
    {null_term = 1;}
    break;

  case 284:
#line 1575 "parser.y"
    {
		  if (text_dir)
		    yyerror ("Can't put data in text segment");
		}
    break;

  case 287:
#line 1587 "parser.y"
    {store_op = (void (*)(void *))store_byte;}
    break;

  case 288:
#line 1589 "parser.y"
    {
		  if (text_dir)
		    yyerror ("Can't put data in text segment");
		}
    break;

  case 289:
#line 1596 "parser.y"
    {
		  align_data (2);
		  if (lookup_label ((char*)yyvsp[-1].p)->addr == 0)
		  {
		    record_label ((char*)yyvsp[-1].p, current_data_pc (), 1);
			if (yyvsp[-2].p) free(yyvsp[-2].p);
		  }
		  increment_data_pc (yyvsp[0].i);
		}
    break;

  case 290:
#line 1608 "parser.y"
    {
		  user_kernel_data_segment (0);
		  data_dir = 1; text_dir = 0;
		  enable_data_alignment ();
		}
    break;

  case 291:
#line 1615 "parser.y"
    {
		  user_kernel_data_segment (0);
		  data_dir = 1; text_dir = 0;
		  enable_data_alignment ();
		  set_data_pc (yyvsp[0].i);
		}
    break;

  case 292:
#line 1624 "parser.y"
    {
		  user_kernel_data_segment (1);
		  data_dir = 1; text_dir = 0;
		  enable_data_alignment ();
		}
    break;

  case 293:
#line 1631 "parser.y"
    {
		  user_kernel_data_segment (1);
		  data_dir = 1; text_dir = 0;
		  enable_data_alignment ();
		  set_data_pc (yyvsp[0].i);
		}
    break;

  case 294:
#line 1640 "parser.y"
    {
		  store_op = (void (*) (void*)) store_double;
		  if (data_dir) set_data_alignment(3);
		}
    break;

  case 295:
#line 1645 "parser.y"
    {
		  if (text_dir)
		    yyerror ("Can't put data in text segment");
		}
    break;

  case 301:
#line 1663 "parser.y"
    {
		  extern_directive ((char*)yyvsp[-1].p, yyvsp[0].i);
		}
    break;

  case 302:
#line 1669 "parser.y"
    {
		  fatal_error ("File contains an .err directive\n");
		}
    break;

  case 304:
#line 1678 "parser.y"
    {
		  store_op = (void (*) (void*))store_float;
		  if (data_dir) set_data_alignment (2);
		}
    break;

  case 305:
#line 1683 "parser.y"
    {
		  if (text_dir)
		    yyerror ("Can't put data in text segment");
		}
    break;

  case 308:
#line 1695 "parser.y"
    {
		  make_label_global ((char*)yyvsp[0].p);
		  if (yyvsp[0].p) free(yyvsp[0].p);
		}
    break;

  case 309:
#line 1702 "parser.y"
    {
		  store_op = (void (*)(void *))store_half;
		  if (data_dir) set_data_alignment (1);
		}
    break;

  case 310:
#line 1707 "parser.y"
    {
		  if (text_dir)
		    yyerror ("Can't put data in text segment");
		}
    break;

  case 311:
#line 1714 "parser.y"
    {
		  record_label ((char*)yyvsp[0].p,
				text_dir
				? current_text_pc ()
				: current_data_pc (),
				1);
		  if (yyvsp[-1].p) free(yyvsp[-1].p);
		}
    break;

  case 312:
#line 1725 "parser.y"
    {
		  lcomm_directive ((char*)yyvsp[-1].p, yyvsp[0].i);
		}
    break;

  case 318:
#line 1743 "parser.y"
    {
		  yyerror ("Warning: repeat directive ignored");
		}
    break;

  case 319:
#line 1749 "parser.y"
    {
		  user_kernel_data_segment (0);
		  data_dir = 1; text_dir = 0;
		  enable_data_alignment ();
		}
    break;

  case 320:
#line 1756 "parser.y"
    {
		  user_kernel_data_segment (0);
		  data_dir = 1; text_dir = 0;
		  enable_data_alignment ();
		  set_data_pc (yyvsp[0].i);
		}
    break;

  case 321:
#line 1765 "parser.y"
    {
		  user_kernel_data_segment (0);
		  data_dir = 1; text_dir = 0;
		  enable_data_alignment ();
		}
    break;

  case 322:
#line 1772 "parser.y"
    {
		  user_kernel_data_segment (0);
		  data_dir = 1; text_dir = 0;
		  enable_data_alignment ();
		  set_data_pc (yyvsp[0].i);
		}
    break;

  case 323:
#line 1781 "parser.y"
    {
		  if (streq ((char*)yyvsp[0].p, "noat"))
		    noat_flag = 1;
		  else if (streq ((char*)yyvsp[0].p, "at"))
		    noat_flag = 0;
		}
    break;

  case 324:
#line 1790 "parser.y"
    {
		  if (data_dir)
		    increment_data_pc (yyvsp[0].i);
		  else if (text_dir)
		    increment_text_pc (yyvsp[0].i);
		}
    break;

  case 325:
#line 1799 "parser.y"
    {
		  yyerror ("Warning: struct directive ignored");
		}
    break;

  case 326:
#line 1805 "parser.y"
    {
		  user_kernel_text_segment (0);
		  data_dir = 0; text_dir = 1;
		  enable_data_alignment ();
		}
    break;

  case 327:
#line 1812 "parser.y"
    {
		  user_kernel_text_segment (0);
		  data_dir = 0; text_dir = 1;
		  enable_data_alignment ();
		  set_text_pc (yyvsp[0].i);
		}
    break;

  case 328:
#line 1821 "parser.y"
    {
		  user_kernel_text_segment (1);
		  data_dir = 0; text_dir = 1;
		  enable_data_alignment ();
		}
    break;

  case 329:
#line 1828 "parser.y"
    {
		  user_kernel_text_segment (1);
		  data_dir = 0; text_dir = 1;
		  enable_data_alignment ();
		  set_text_pc (yyvsp[0].i);
		}
    break;

  case 332:
#line 1842 "parser.y"
    {
		  store_op = (void (*)(void *))store_word_data;
		  if (data_dir) set_data_alignment (2);
		}
    break;

  case 334:
#line 1852 "parser.y"
    {only_id = 1;}
    break;

  case 335:
#line 1852 "parser.y"
    {only_id = 0; yyval = yyvsp[0];}
    break;

  case 336:
#line 1855 "parser.y"
    {
		  yyval.p = make_addr_expr (0, NULL, yyvsp[-1].i);
		}
    break;

  case 337:
#line 1860 "parser.y"
    {
		  yyval.p = make_addr_expr (yyvsp[0].i, NULL, 0);
		}
    break;

  case 338:
#line 1865 "parser.y"
    {
		  yyval.p = make_addr_expr (yyvsp[-3].i, NULL, yyvsp[-1].i);
		}
    break;

  case 339:
#line 1870 "parser.y"
    {
		  yyval.p = make_addr_expr (0, (char*)yyvsp[0].p, 0);
		  if (yyvsp[0].p) free ((char*)yyvsp[0].p);
		}
    break;

  case 340:
#line 1876 "parser.y"
    {
		  yyval.p = make_addr_expr (0, (char*)yyvsp[-3].p, yyvsp[-1].i);
		  if (yyvsp[-3].p) free ((char*)yyvsp[-3].p);
		}
    break;

  case 341:
#line 1882 "parser.y"
    {
		  yyval.p = make_addr_expr (yyvsp[0].i, (char*)yyvsp[-2].p, 0);
		  if (yyvsp[-2].p) free ((char*)yyvsp[-2].p);
		}
    break;

  case 342:
#line 1888 "parser.y"
    {
		  yyval.p = make_addr_expr (yyvsp[-2].i, (char*)yyvsp[0].p, 0);
		}
    break;

  case 343:
#line 1893 "parser.y"
    {
		  yyval.p = make_addr_expr (- yyvsp[0].i, (char*)yyvsp[-2].p, 0);
		  if (yyvsp[-2].p) free ((char*)yyvsp[-2].p);
		}
    break;

  case 344:
#line 1899 "parser.y"
    {
		  yyval.p = make_addr_expr (yyvsp[-3].i, (char*)yyvsp[-5].p, yyvsp[-1].i);
		  if (yyvsp[-5].p) free ((char*)yyvsp[-5].p);
		}
    break;

  case 345:
#line 1905 "parser.y"
    {
		  yyval.p = make_addr_expr (- yyvsp[-3].i, (char*)yyvsp[-5].p, yyvsp[-1].i);
		  if (yyvsp[-5].p) free ((char*)yyvsp[-5].p);
		}
    break;

  case 346:
#line 1912 "parser.y"
    {only_id = 1;}
    break;

  case 347:
#line 1912 "parser.y"
    {only_id = 0; yyval = yyvsp[0];}
    break;

  case 348:
#line 1915 "parser.y"
    {
		  check_imm_range((imm_expr*)yyvsp[0].p, IMM_MIN, IMM_MAX);
		  yyval = yyvsp[0];
		}
    break;

  case 349:
#line 1921 "parser.y"
    {
		  check_uimm_range((imm_expr*)yyvsp[0].p, UIMM_MIN, UIMM_MAX);
		  yyval = yyvsp[0];
		}
    break;

  case 350:
#line 1928 "parser.y"
    {
		  yyval.p = make_imm_expr (yyvsp[0].i, NULL, 0);
		}
    break;

  case 351:
#line 1933 "parser.y"
    {
		  yyval.p = make_imm_expr (yyvsp[-4].i >> yyvsp[0].i, NULL, 0);
		}
    break;

  case 352:
#line 1938 "parser.y"
    {
		  yyval.p = make_imm_expr (0, (char*)yyvsp[0].p, 0);
		}
    break;

  case 353:
#line 1943 "parser.y"
    {
		  yyval.p = make_imm_expr (yyvsp[0].i, (char*)yyvsp[-2].p, 0);
		  free ((char*)yyvsp[-2].p);
		}
    break;

  case 354:
#line 1949 "parser.y"
    {
		  yyval.p = make_imm_expr (- yyvsp[0].i, (char*)yyvsp[-2].p, 0);
		  free ((char*)yyvsp[-2].p);
		}
    break;

  case 356:
#line 1959 "parser.y"
    {yyval.i = yyvsp[-2].i + yyvsp[0].i;}
    break;

  case 357:
#line 1962 "parser.y"
    {
		  /* Y_INT '-' Y_INT */
		  if (yyvsp[0].i >= 0)
		    yyerror ("Syntax error");
		  yyval.i = yyvsp[-1].i - yyvsp[0].i;
		}
    break;

  case 364:
#line 1983 "parser.y"
    {
		  if (yyvsp[0].i < 0 || yyvsp[0].i > 31)
		    yyerror ("Register number out of range");
		  if (yyvsp[0].i == 1 && !bare_machine && !noat_flag)
		    yyerror ("Register 1 is reserved for assembler");
		  yyval = yyvsp[0];
		}
    break;

  case 368:
#line 1998 "parser.y"
    {
		  if (yyvsp[0].i < 0 || yyvsp[0].i > 31)
		    yyerror ("FP register number out of range");
		  yyval = yyvsp[0];
		}
    break;

  case 371:
#line 2013 "parser.y"
    {
		  yyval.p = make_imm_expr (-(int)current_text_pc (), (char*)yyvsp[0].p, 1);
		}
    break;

  case 374:
#line 2024 "parser.y"
    {
		  store_string ((char*)yyvsp[0].p, y_str_length, null_term);
		  free ((char*)yyvsp[0].p);
		}
    break;

  case 375:
#line 2029 "parser.y"
    {
		  int i;

		  for (i = 0; i < yyvsp[0].i; i ++)
		    store_string ((char*)yyvsp[-2].p, y_str_length, null_term);
		  free ((char*)yyvsp[-2].p);
		}
    break;

  case 376:
#line 2039 "parser.y"
    {only_id = 1;}
    break;

  case 377:
#line 2039 "parser.y"
    {only_id = 0; yyval = yyvsp[0];}
    break;

  case 379:
#line 2044 "parser.y"
    {
		  label *l = lookup_label ((char*)yyvsp[0].p);

		  if (l->addr == 0)
		    {
		      record_data_uses_symbol (current_data_pc (), l);
		      yyval.p = NULL;
		    }
		  else
		    yyval.i = l->addr;
		}
    break;

  case 380:
#line 2058 "parser.y"
    {
		  store_op (yyvsp[0].p);
		}
    break;

  case 381:
#line 2062 "parser.y"
    {
		  store_op (yyvsp[0].p);
		}
    break;

  case 382:
#line 2066 "parser.y"
    {
		  int i;

		  for (i = 0; i < yyvsp[0].i; i ++)
		    store_op (yyvsp[-2].p);
		}
    break;

  case 383:
#line 2076 "parser.y"
    {
		  store_op (yyvsp[0].p);
		}
    break;

  case 384:
#line 2080 "parser.y"
    {
		  store_op (yyvsp[0].p);
		}
    break;

  case 385:
#line 2086 "parser.y"
    {only_id = 1;}
    break;

  case 386:
#line 2086 "parser.y"
    {only_id = 0; yyval = yyvsp[0];}
    break;

  case 388:
#line 2089 "parser.y"
    {yyval.p = (void*)NULL;}
    break;

  case 389:
#line 2093 "parser.y"
    {only_id = 1;}
    break;

  case 390:
#line 2093 "parser.y"
    {only_id = 0; yyval = yyvsp[0];}
    break;


    }

/* Line 1010 of yacc.c.  */
#line 3911 "y.tab.c"

  yyvsp -= yylen;
  yyssp -= yylen;


  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  YYSIZE_T yysize = 0;
	  int yytype = YYTRANSLATE (yychar);
	  const char* yyprefix;
	  char *yymsg;
	  int yyx;

	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  int yyxbegin = yyn < 0 ? -yyn : 0;

	  /* Stay within bounds of both yycheck and yytname.  */
	  int yychecklim = YYLAST - yyn;
	  int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
	  int yycount = 0;

	  yyprefix = ", expecting ";
	  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      {
		yysize += yystrlen (yyprefix) + yystrlen (yytname [yyx]);
		yycount += 1;
		if (yycount == 5)
		  {
		    yysize = 0;
		    break;
		  }
	      }
	  yysize += (sizeof ("syntax error, unexpected ")
		     + yystrlen (yytname[yytype]));
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "syntax error, unexpected ");
	      yyp = yystpcpy (yyp, yytname[yytype]);

	      if (yycount < 5)
		{
		  yyprefix = ", expecting ";
		  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
		    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
		      {
			yyp = yystpcpy (yyp, yyprefix);
			yyp = yystpcpy (yyp, yytname[yyx]);
			yyprefix = " or ";
		      }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    yyerror ("syntax error; also virtual memory exhausted");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror ("syntax error");
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* If at end of input, pop the error token,
	     then the rest of the stack, then return failure.  */
	  if (yychar == YYEOF)
	     for (;;)
	       {
		 YYPOPSTACK;
		 if (yyssp == yyss)
		   YYABORT;
		 YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
		 yydestruct (yystos[*yyssp], yyvsp);
	       }
        }
      else
	{
	  YYDSYMPRINTF ("Error: discarding", yytoken, &yylval, &yylloc);
	  yydestruct (yytoken, &yylval);
	  yychar = YYEMPTY;

	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

#ifdef __GNUC__
  /* Pacify GCC when the user code never invokes YYERROR and the label
     yyerrorlab therefore never appears in user code.  */
  if (0)
     goto yyerrorlab;
#endif

  yyvsp -= yylen;
  yyssp -= yylen;
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
      yydestruct (yystos[yystate], yyvsp);
      YYPOPSTACK;
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  YYDPRINTF ((stderr, "Shifting error token, "));

  *++yyvsp = yylval;


  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*----------------------------------------------.
| yyoverflowlab -- parser overflow comes here.  |
`----------------------------------------------*/
yyoverflowlab:
  yyerror ("parser stack overflow");
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}


#line 2096 "parser.y"


/* Maintain and update the address of labels for the current line. */

#ifdef __STDC__
void
fix_current_label_address (mem_addr new_addr)
#else
void
fix_current_label_address (new_addr)
     mem_addr new_addr;
#endif
{
  label_list *l;

  for (l = this_line_labels; l != NULL; l = l->tail)
    {
      l->head->addr = new_addr;
    }
  clear_labels ();
}


#ifdef __STDC__
static label_list *
cons_label (label *head, label_list *tail)
#else
static label_list *
cons_label (head, tail)
     label *head;
     label_list *tail;
#endif
{
  label_list *c = (label_list *) malloc (sizeof (label_list));

  c->head = head;
  c->tail = tail;
  return (c);
}


#ifdef __STDC__
static void
clear_labels (void)
#else
static void
clear_labels ()
#endif
{
  label_list *n;

  for ( ; this_line_labels != NULL; this_line_labels = n)
    {
      resolve_label_uses(this_line_labels->head);
      n = this_line_labels->tail;
      free (this_line_labels);
    }
}


/* Operations on op codes. */

#ifdef __STDC__
int
op_to_imm_op (int opcode)
#else
int
op_to_imm_op (opcode)
     int opcode;
#endif
{
  switch (opcode)
    {
    case Y_ADD_OP: return (Y_ADDI_OP);
    case Y_ADDU_OP: return (Y_ADDIU_OP);
    case Y_AND_OP: return (Y_ANDI_OP);
    case Y_OR_OP: return (Y_ORI_OP);
    case Y_XOR_OP: return (Y_XORI_OP);
    case Y_SLT_OP: return (Y_SLTI_OP);
    case Y_SLTU_OP: return (Y_SLTIU_OP);
    case Y_SLLV_OP: return (Y_SLL_OP);
    case Y_SRAV_OP: return (Y_SRA_OP);
    case Y_SRLV_OP: return (Y_SRL_OP);
    default: fatal_error ("Can't convert op to immediate op\n"); return (0);
    }
}


#ifdef __STDC__
int
imm_op_to_op (int opcode)
#else
int
imm_op_to_op (opcode)
     int opcode;
#endif
{
  switch (opcode)
    {
    case Y_ADDI_OP: return (Y_ADD_OP);
    case Y_ADDIU_OP: return (Y_ADDU_OP);
    case Y_ANDI_OP: return (Y_AND_OP);
    case Y_ORI_OP: return (Y_OR_OP);
    case Y_XORI_OP: return (Y_XOR_OP);
    case Y_SLTI_OP: return (Y_SLT_OP);
    case Y_SLTIU_OP: return (Y_SLTU_OP);
    case Y_J_OP: return (Y_JR_OP);
    case Y_LUI_OP: return (Y_ADDU_OP);
    case Y_SLL_OP: return (Y_SLLV_OP);
    case Y_SRA_OP: return (Y_SRAV_OP);
    case Y_SRL_OP: return (Y_SRLV_OP);
    default: fatal_error ("Can't convert immediate op to op\n"); return (0);
    }
}


#ifdef __STDC__
static void
nop_inst (void)
#else
static void
nop_inst ()
#endif
{
  r_type_inst (Y_SLL_OP, 0, 0, 0); /* = 0 */
}


#ifdef __STDC__
static void
trap_inst (void)
#else
static void
trap_inst ()
#endif
{
  r_type_inst (Y_BREAK_OP, 0, 0, 0);
}


#ifdef __STDC__
static imm_expr *
branch_offset (int n_inst)
#else
static imm_expr *
branch_offset (n_inst)
     int n_inst;
#endif
{
  return (const_imm_expr (n_inst << 2)); /* Later shifted right 2 places */
}


#ifdef __STDC__
static void
div_inst (int op, int rd, int rs, int rt, int const_divisor)
#else
static void
div_inst (op, rd, rs, rt, const_divisor)
     int op, rd, rs, rt, const_divisor;
#endif
{
  if (rd != 0 && !const_divisor)
    {
      i_type_inst_free (Y_BNE_OP, 0, rt, branch_offset (2));
      trap_inst ();
    }

  if (op == Y_DIV_OP || op == Y_REM_POP)
    r_type_inst (Y_DIV_OP, 0, rs, rt);
  else
    r_type_inst (Y_DIVU_OP, 0, rs, rt);

  if (rd != 0)
    {
      if (op == Y_DIV_OP || op == Y_DIVU_OP)
	/* Quotient */
	r_type_inst (Y_MFLO_OP, rd, 0, 0);
      else
	/* Remainder */
	r_type_inst (Y_MFHI_OP, rd, 0, 0);
    }
}


#ifdef __STDC__
static void
mult_inst (int op, int rd, int rs, int rt)
#else
static void
mult_inst (op, rd, rs, rt)
     int op, rd, rs, rt;
#endif
{
  if (op == Y_MULOU_POP)
    r_type_inst (Y_MULTU_OP, 0, rs, rt);
  else
    r_type_inst (Y_MULT_OP, 0, rs, rt);
  if (op == Y_MULOU_POP && rd != 0)
    {
      r_type_inst (Y_MFHI_OP, 1, 0, 0);	/* Use $at */
      i_type_inst_free (Y_BEQ_OP, 0, 1, branch_offset (2));
      trap_inst ();
    }
  else if (op == Y_MULO_POP && rd != 0)
    {
      r_type_inst (Y_MFHI_OP, 1, 0, 0); /* use $at */
      r_type_inst (Y_MFLO_OP, rd, 0, 0);
      r_sh_type_inst (Y_SRA_OP, rd, rd, 31);
      i_type_inst_free (Y_BEQ_OP, rd, 1, branch_offset (2));
      trap_inst ();
    }
  if (rd != 0)
    r_type_inst (Y_MFLO_OP, rd, 0, 0);
}


#ifdef __STDC__
static void
set_le_inst (int op, int rd, int rs, int rt)
#else
static void
set_le_inst (op, rd, rs, rt)
     int op, rd, rs, rt;
#endif
{
  i_type_inst_free (Y_BNE_OP, rs, rt, branch_offset (3));
  i_type_inst_free (Y_ORI_OP, rd, 0, const_imm_expr (1));
  i_type_inst_free (Y_BEQ_OP, 0, 0, branch_offset (2));
  r_type_inst ((op == Y_SLE_POP ? Y_SLT_OP : Y_SLTU_OP), rd, rs, rt);
}


#ifdef __STDC__
static void
set_gt_inst (int op, int rd, int rs, int rt)
#else
static void
set_gt_inst (op, rd, rs, rt)
     int op, rd, rs, rt;
#endif
{
  r_type_inst (op == Y_SGT_POP ? Y_SLT_OP : Y_SLTU_OP, rd, rt, rs);
}


#ifdef __STDC__
static void
set_ge_inst (int op, int rd, int rs, int rt)
#else
static void
set_ge_inst (op, rd, rs, rt)
     int op, rd, rs, rt;
#endif
{
  i_type_inst_free (Y_BNE_OP, rs, rt, branch_offset (3));
  i_type_inst_free (Y_ORI_OP, rd, 0, const_imm_expr (1));
  i_type_inst_free (Y_BEQ_OP, 0, 0, branch_offset (2));
  r_type_inst (op == Y_SGE_POP ? Y_SLT_OP : Y_SLTU_OP, rd, rt, rs);
}


#ifdef __STDC__
static void
set_eq_inst (int op, int rd, int rs, int rt)
#else
static void
set_eq_inst (op, rd, rs, rt)
     int op, rd, rs, rt;
#endif
{
  imm_expr *if_eq, *if_neq;

  if (op == Y_SEQ_POP)
    if_eq = const_imm_expr (1), if_neq = const_imm_expr (0);
  else
    if_eq = const_imm_expr (0), if_neq = const_imm_expr (1);

  i_type_inst_free (Y_BEQ_OP, rs, rt, branch_offset (3));
  /* RD <- 0 (if not equal) */
  i_type_inst_free (Y_ORI_OP, rd, 0, if_neq);
  i_type_inst_free (Y_BEQ_OP, 0, 0, branch_offset (2)); /* Branch always */
  /* RD <- 1 */
  i_type_inst_free (Y_ORI_OP, rd, 0, if_eq);
}


/* Store the value either as a datum or instruction. */

#ifdef __STDC__
static void
store_word_data (int value)
#else
static void
store_word_data (value)
     int value;
#endif
{
  if (data_dir)
    store_word (value);
  else if (text_dir)
    store_instruction (inst_decode (value));
}



#ifdef __STDC__
void
initialize_parser (char *file_name)
#else
void
initialize_parser (file_name)
     char *file_name;
#endif
{
  input_file_name = file_name;
  only_id = 0;
  data_dir = 0;
  text_dir = 1;
}


#ifdef __STDC__
static void
check_imm_range(imm_expr* expr, int32 min, int32 max)
#else
static void
check_imm_range()
     imm_expr* expr;
     int32 min;
     int32 max;
#endif
{
  if (expr->symbol == NULL || SYMBOL_IS_DEFINED (expr->symbol))
    {
      /* If expression can be evaluated, compare its value against the limits
	 and complain if the value is out of bounds. */
      int32 value = eval_imm_expr (expr);

      if (value < min || max < value)
	{
	  char str[200];
	  sprintf (str, "immediate value (%d) out of range (%d .. %d)",
		   value, min, max);
	  yywarn (str);
	}
    }
}


#ifdef __STDC__
static void
check_uimm_range(imm_expr* expr, uint32 min, uint32 max)
#else
static void
check_uimm_range()^
     imm_expr* expr;
     int32 umin;
     int32 umax;
#endif
{
  if (expr->symbol == NULL || SYMBOL_IS_DEFINED (expr->symbol))
    {
      /* If expression can be evaluated, compare its value against the limits
	     and complain if the value is out of bounds. */
      uint32 value = eval_imm_expr (expr);

      if (value < min || max < value)
	{
	  char str[200];
	  sprintf (str, "immediate value (%d) out of range (%d .. %d)",
		   value, min, max);
	  yywarn (str);
	}
    }
}

#ifdef __STDC__
void
yyerror (char const *s)
#else
void
yyerror (s)
     char const *s;
#endif
{
  parse_error_occurred = 1;
  yywarn (s);
}


#ifdef __STDC__
void
yywarn (char const *s)
#else
void
yywarn (s)
     char const *s;
#endif
{
  error ("spim: (parser) %s on line %d of file %s\n", s, line_no, input_file_name);
  print_erroneous_line ();
}

