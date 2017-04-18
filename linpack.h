#ifndef __LINPACK_H__
#define __LINPACK_H__

#define DP

#ifdef SP
#define ZERO        0.0
#define ONE         1.0
#define PREC        "Single"
#define BASE10DIG   FLT_DIG

typedef float   REAL;
#endif

#ifdef DP
#define ZERO        0.0e0
#define ONE         1.0e0
#define PREC        "Double"
#define BASE10DIG   DBL_DIG

typedef double  REAL;
#endif

#define ARSIZE 40

extern REAL linpack(long nreps,int arsize, void *mempool);

#endif /* __LINPACK_H__ */


