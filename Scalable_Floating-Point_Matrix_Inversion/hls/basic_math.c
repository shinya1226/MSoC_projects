///////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2016 Xilinx, Inc.
// All Rights Reserved
///////////////////////////////////////////////////////////////////////////////
//   ____  ____
//  /   /\/   /
// /___/  \  /    Vendor: Xilinx
// \   \   \/     Version: 1.0
//  \   \         Application : Vivado HLS
//  /   /         Filename: basic_math.c
// /___/   /\     Timestamp: Fri Aug 19 8:08:10 PST 2016
// \   \  /  \
//  \___\/\___\
//
//Command: N/A
//Device:  Xilinx Kintex-7, US, US+; Zynq-7000, US+
//Design Name: LUInv
//Purpose:
//    This file contains basic math functions, e.g., square, add, minus, etc.
//Reference:
//    XAPP1317
///////////////////////////////////////////////////////////////////////////////

#include "luinv.h"

//------------------
// complex square
// z = |x|^2
//------------------
float csqu(cfloat_t x){
	float z = x.real*x.real;
	z+= x.imag*x.imag;
	return(z);
}

//------------------
// complex neg
// z = -x
//------------------
cfloat_t neg(cfloat_t x){
	cfloat_t z;
	z.real = -x.real;
	z.imag = -x.imag;
	return(z);
}

//------------------
// complex add
// z = x + y
//------------------
cfloat_t add(cfloat_t x, cfloat_t y){
	cfloat_t z;
	z.real = x.real + y.real;
	z.imag = x.imag + y.imag;
	return(z);
}

//------------------
// complex subtraction
// z = x - y
//------------------
cfloat_t sub(cfloat_t x, cfloat_t y){
	cfloat_t z;
	z.real = x.real - y.real;
	z.imag = x.imag - y.imag;
	return(z);
}

//------------------
// complex multiply
// z = x * y
//------------------
cfloat_t mul(cfloat_t x, cfloat_t y){
	cfloat_t z;
	z.real = x.real*y.real - x.imag*y.imag;
	z.imag = x.real*y.imag + x.imag*y.real;
	return(z);
}



//------------------
// complex inv
// z = 1./x
//------------------
//cfloat_t inv(cfloat_t x){
//	cfloat_t z;
//	float x2 = x.real*x.real + x.imag*x.imag;
//	double invx2 = 1./x2;
//	// multiply x*
//	z.real = invx2*x.real;
//	z.imag = -invx2*x.imag;
//	return(z);
//}

