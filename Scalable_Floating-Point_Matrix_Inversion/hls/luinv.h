///////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2016 Xilinx, Inc.
// All Rights Reserved
///////////////////////////////////////////////////////////////////////////////
//   ____  ____
//  /   /\/   /
// /___/  \  /    Vendor: Xilinx
// \   \   \/     Version: 1.0
//  \   \         Application : Vivado HLS
//  /   /         Filename: luinv.c
// /___/   /\     Timestamp: Fri Aug 19 8:08:10 PST 2016
// \   \  /  \
//  \___\/\___\
//
//Command: N/A
//Device:  Xilinx Kintex-7, US, US+; Zynq-7000, US+
//Design Name: LUInv
//Purpose:
//    This is the header file of LU INV.
//Reference:
//    XAPP1317
///////////////////////////////////////////////////////////////////////////////

#ifndef _LUINV_H
#define _LUINV_H

#include <math.h>

// number of layers, or matrix size
#define NL 32 
//#define NL 4 

// floating point complex data type
typedef struct complex_float {
  float real;
  float imag;
} cfloat_t;


// complex square
float csqu(cfloat_t x);
// complex neg
cfloat_t neg(cfloat_t x);
// complex add
cfloat_t add(cfloat_t x, cfloat_t y);
// complex sub
cfloat_t sub(cfloat_t x, cfloat_t y);
// complex inv
cfloat_t inv(cfloat_t x);
// complex multiply
cfloat_t mul(cfloat_t x, cfloat_t y);

// LU decomposition with pivoting
void luinv_lup(cfloat_t A[NL*NL], cfloat_t B[NL][NL], char P[NL+1]);
void luinv_inv(cfloat_t A[NL][NL], cfloat_t B[NL][NL], char P[NL+1], char P_out[NL+1]);
char luinv_mul(cfloat_t A[NL][NL], cfloat_t B[NL*NL], char P[NL+1]);

// The main function
char luinv(cfloat_t A[NL*NL],  cfloat_t Ainv[NL*NL]);

#endif
