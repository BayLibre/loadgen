#pragma GCC diagnostic ignored "-Wimplicit-int"
#pragma GCC diagnostic ignored "-Wimplicit-function-declaration"
#define strcpy _strcpy
char *_strcpy(char *s1, const char *s2)
{
    char *s = s1;
    while ((*s++ = *s2++) != 0)
	;
    return (s1);
}

/*
 *
 * @Component			CPULOADGEN
 * @Filename			cpuloadgen.c
 * @Description			Programmable CPU Load Generator,
 *					based on Dhrystone loops
 * @Author			Patrick Titiano (p-titiano@ti.com)
 * @Date			2010
 * @Copyright			Texas Instruments Incorporated
 *
 *
 * Copyright (C) 2010 Texas Instruments Incorporated - http://www.ti.com/
 *
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "dhry.h"
#include <sys/time.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#define __USE_GNU
#include <sched.h>
#include <signal.h>
#include <errno.h>
#include <pthread.h>

#include "dhrystone.h"

#ifndef ROPT
#define REG
#else
#define REG register
#endif

/* Global Variables: */



Enumeration     Func_1();
/* forward declaration necessary since Enumeration may not simply be int */

void dhryStone(unsigned int iterations)
{
	Rec_Pointer Ptr_Glob, Next_Ptr_Glob;
	int Int_Glob;
	Boolean Bool_Glob;
	char Ch_1_Glob, Ch_2_Glob;
	int Arr_1_Glob [50];
	int Arr_2_Glob [50][50];
	One_Fifty Int_1_Loc;
	REG One_Fifty Int_2_Loc;
	One_Fifty Int_3_Loc;
	REG char Ch_Index;
	Enumeration Enum_Loc;
	Str_30 Str_1_Loc;
	Str_30 Str_2_Loc;
	REG int Run_Index;
	REG int Number_Of_Runs;

	FILE *Ap;
	unsigned int mrcData;

	Next_Ptr_Glob = (Rec_Pointer) malloc(sizeof(Rec_Type));
	Ptr_Glob = (Rec_Pointer) malloc(sizeof (Rec_Type));

	Ptr_Glob->Ptr_Comp = Next_Ptr_Glob;
	Ptr_Glob->Discr = Ident_1;
	Ptr_Glob->variant.var_1.Enum_Comp = Ident_3;
	Ptr_Glob->variant.var_1.Int_Comp = 40;
	strcpy (Ptr_Glob->variant.var_1.Str_Comp,
	"DHRYSTONE PROGRAM, SOME STRING");
	strcpy (Str_1_Loc, "DHRYSTONE PROGRAM, 1'ST STRING");

	Arr_2_Glob [8][7] = 10;
    /* Was missing in published program. Without this statement,
    Arr_2_Glob [8][7] would have an undefined value.
    Warning: With 16-Bit processors and Number_Of_Runs > 32000,
    overflow may occur for this array element. */

    Number_Of_Runs = iterations;
	for (Run_Index = 1; Run_Index <= Number_Of_Runs; ++Run_Index) {
		Proc_5(&Bool_Glob, &Ch_1_Glob);
		Proc_4(&Bool_Glob, Ch_1_Glob, &Ch_2_Glob);
		/* Ch_1_Glob == 'A', Ch_2_Glob == 'B', Bool_Glob == true */
		Int_1_Loc = 2;
		Int_2_Loc = 3;
		strcpy (Str_2_Loc, "DHRYSTONE PROGRAM, 2'ND STRING");
		Enum_Loc = Ident_2;
		Bool_Glob = ! Func_2 (Str_1_Loc, Str_2_Loc, &Ch_1_Glob);
		/* Bool_Glob == 1 */
		while (Int_1_Loc < Int_2_Loc) { /* loop body executed once */
			Int_3_Loc = 5 * Int_1_Loc - Int_2_Loc;
			/* Int_3_Loc == 7 */
			Proc_7 (Int_1_Loc, Int_2_Loc, &Int_3_Loc);
			/* Int_3_Loc == 7 */
			Int_1_Loc += 1;
		}
		/* Int_1_Loc == 3, Int_2_Loc == 3, Int_3_Loc == 7 */
		Proc_8 (Arr_1_Glob, Arr_2_Glob, Int_1_Loc, Int_3_Loc, &Int_Glob);
		/* Int_Glob == 5 */
		Proc_1 (Ptr_Glob, Int_Glob);
		for (Ch_Index = 'A'; Ch_Index <= Ch_2_Glob; ++Ch_Index) {
		/* loop body executed twice */
			if (Enum_Loc == Func_1 (Ch_Index, 'C')) {
				/* then, not executed */
				Proc_6 (Ident_1, &Enum_Loc, Int_Glob);
				strcpy (Str_2_Loc,
					"DHRYSTONE PROGRAM, 3'RD STRING");
				Int_2_Loc = Run_Index;
				Int_Glob = Run_Index;
			}
		}
		/* Int_1_Loc == 3, Int_2_Loc == 3, Int_3_Loc == 7 */
		Int_2_Loc = Int_2_Loc * Int_1_Loc;
		Int_1_Loc = Int_2_Loc / Int_3_Loc;
		Int_2_Loc = 7 * (Int_2_Loc - Int_3_Loc) - Int_1_Loc;
		/* Int_1_Loc == 1, Int_2_Loc == 13, Int_3_Loc == 7 */
		Proc_2 (&Int_1_Loc, Int_Glob, Ch_1_Glob);
		/* Int_1_Loc == 5 */
	}
}


Proc_1 (Ptr_Val_Par, Int_Glob)
/******************/

REG Rec_Pointer Ptr_Val_Par;
    /* executed once */
int Int_Glob;
{
  REG Rec_Pointer Next_Record = Ptr_Val_Par->Ptr_Comp;
                                        /* == Ptr_Glob_Next */
  /* Local variable, initialized with Ptr_Val_Par->Ptr_Comp,    */
  /* corresponds to "rename" in Ada, "with" in Pascal           */

  structassign (*Ptr_Val_Par->Ptr_Comp, *Ptr_Val_Par);
  Ptr_Val_Par->variant.var_1.Int_Comp = 5;
  Next_Record->variant.var_1.Int_Comp
        = Ptr_Val_Par->variant.var_1.Int_Comp;
  Next_Record->Ptr_Comp = Ptr_Val_Par->Ptr_Comp;
  Proc_3 (&Next_Record->Ptr_Comp, Ptr_Val_Par, Int_Glob);
    /* Ptr_Val_Par->Ptr_Comp->Ptr_Comp
                        == Ptr_Glob->Ptr_Comp */
  if (Next_Record->Discr == Ident_1)
    /* then, executed */
  {
    Next_Record->variant.var_1.Int_Comp = 6;
    Proc_6 (Ptr_Val_Par->variant.var_1.Enum_Comp,
           &Next_Record->variant.var_1.Enum_Comp, Int_Glob);
    Next_Record->Ptr_Comp = Ptr_Val_Par->Ptr_Comp;
    Proc_7 (Next_Record->variant.var_1.Int_Comp, 10,
           &Next_Record->variant.var_1.Int_Comp);
  }
  else /* not executed */
    structassign (*Ptr_Val_Par, *Ptr_Val_Par->Ptr_Comp);
} /* Proc_1 */

Proc_2 (Int_Par_Ref, Int_Glob, Ch_1_Glob)
/******************/
    /* executed once */
    /* *Int_Par_Ref == 1, becomes 4 */

One_Fifty   *Int_Par_Ref;
int Int_Glob;
char Ch_1_Glob;
{
  One_Fifty  Int_Loc;
  Enumeration   Enum_Loc;

  Int_Loc = *Int_Par_Ref + 10;
  do /* executed once */
    if (Ch_1_Glob == 'A')
      /* then, executed */
    {
      Int_Loc -= 1;
      *Int_Par_Ref = Int_Loc - Int_Glob;
      Enum_Loc = Ident_1;
    } /* if */
  while (Enum_Loc != Ident_1); /* true */
} /* Proc_2 */


Proc_3 (Ptr_Ref_Par, Ptr_Glob, Int_Glob)
/******************/
    /* executed once */
    /* Ptr_Ref_Par becomes Ptr_Glob */

Rec_Pointer *Ptr_Ref_Par;
Rec_Pointer Ptr_Glob;
int Int_Glob;
{
  if (Ptr_Glob != Null)
    /* then, executed */
    *Ptr_Ref_Par = Ptr_Glob->Ptr_Comp;
  Proc_7 (10, Int_Glob, &Ptr_Glob->variant.var_1.Int_Comp);
} /* Proc_3 */


Proc_4 (Bool_Glob, Ch_1_Glob, Ch_2_Glob) /* without parameters */
/*******/
    /* executed once */
int *Bool_Glob;
char Ch_1_Glob;
char *Ch_2_Glob;
{
  Boolean Bool_Loc;

  Bool_Loc = Ch_1_Glob == 'A';
  *Bool_Glob = Bool_Loc | *Bool_Glob;
  *Ch_2_Glob = 'B';
} /* Proc_4 */


Proc_5 (Bool_Glob, Ch_1_Glob) /* without parameters */
/*******/
    /* executed once */
int *Bool_Glob;
char *Ch_1_Glob;
{
  *Ch_1_Glob = 'A';
  *Bool_Glob = false;
} /* Proc_5 */

#pragma GCC diagnostic pop