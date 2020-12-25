///////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2016 Xilinx, Inc.
// All Rights Reserved
///////////////////////////////////////////////////////////////////////////////
//   ____  ____
//  /   /\/   /
// /___/  \  /    Vendor: Xilinx
// \   \   \/     Version: 2.0
//  \   \         Application : Vivado HLS
//  /   /         Filename: luinv_mul.c
// /___/   /\     Timestamp: Fri Aug 19 8:08:10 PST 2016
// \   \  /  \
//  \___\/\___\
//
//Command: N/A
//Device:  Xilinx Kintex-7, US, US+; Zynq-7000, US+
//Design Name: LUInv
//Purpose:
//    This function multiplies two triangular matrices in L and U
//Reference:
//    XAPP1317
///////////////////////////////////////////////////////////////////////////////

#include "luinv.h"

//matrix multiply
char luinv_mul(cfloat_t A[NL][NL], cfloat_t B[NL*NL], char P[NL+1]){

	char i, j, k;
	cfloat_t C[NL][NL];
	unsigned short addr=0;
	
	// invU * invD	
	for(i=0;i<NL;i++){
		
		cfloat_t x = A[i][i];
		
		C[i][i] = x;
		
		luinv_mul_label2:for(j=0;j<i;j++)
			C[j][i] = mul(x, A[j][i]);

	}
		
	// * invL
	for(i=0;i<NL;i++){
		
		cfloat_t z[NL];
		cfloat_t s[NL];
		cfloat_t sr[NL];
		
		cfloat_t zz[NL];
		cfloat_t ss[NL];
		cfloat_t ssr[NL];

		// compute A(1, :)*B
		luinv_mul_label5:for(j=i;j<NL;j++)  s[j]=z[j]=C[i][j];
		
		luinv_mul_label8:for(j=1;j<NL-i;j++){
			
			luinv_mul_label0:for(k=i;k<NL-j;k++){
				
				cfloat_t this_s = mul(z[j+k], A[j+k][k]);
				sr[k] = add(s[k], this_s);
				
			}
			
			// assign it back to s
			luinv_mul_label3:for(k=i;k<NL-j;k++) s[k]=sr[k];
			
		}
		
		// write it out
		luinv_mul_label4:for(j=i;j<NL;j++) C[i][j] = s[j];
		
		// compute A*B(:, 1)
		luinv_mul_label6:for(j=i+1;j<NL;j++){
			zz[j]=A[j][i];
			ss[j].real=0;
			ss[j].imag=0;
		}
		
		for(j=0;j<NL-i;j++){
			
			luinv_mul_label1:for(k=i+1;k<NL-j;k++){
				cfloat_t this_s = mul(C[k][j+k], zz[j+k]);
				ssr[k] = add(ss[k], this_s);
			}
			
			// assign it back to s
			luinv_mul_label7:for(k=i+1;k<NL-j;k++) ss[k]=ssr[k];
		}
		
		for(j=i+1;j<NL;j++) C[j][i] = ss[j];
		
	}
	
	// write out B
	save_data: for(i=0;i<NL;i++) for(j=0;j<NL;j++) B[addr++] = C[j][P[i]];
	
	// return status
	return(P[NL]);
		
}
