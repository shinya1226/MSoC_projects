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
//    This is the top-level design of LU INV.
//Reference:
//    XAPP1317
///////////////////////////////////////////////////////////////////////////////

#include "luinv.h"

// top-level of HLS design
char luinv(cfloat_t A[NL*NL], cfloat_t Ainv[NL*NL]){

	 // to save LU decomposition result
	 cfloat_t LU[NL][NL];
	 
	 // to save the inverse of the matrix
	 cfloat_t LUinv[NL][NL];
	 
	 // row permutation vector
	 char  P[NL+1];
	 
	 // adjusted permutation vector
	 char  Padj[NL+1];
	 
	 // flag whether the matrix is ill-conditioned
	 char  stat;

	 // LU decomposition with Pivoting
	 luinv_lup(A,     LU,    P);
	
	 // Inverse the triangular matrices L and U
	 luinv_inv(LU,    LUinv, P,    Padj);
	
	 // Multiply the inverse of triangular matrices
	 stat = luinv_mul(LUinv, Ainv, Padj);
	
	 // stat=-1 for ill-conditioned matrix
	 return(stat);

}

