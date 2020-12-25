///////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2016 Xilinx, Inc.
// All Rights Reserved
///////////////////////////////////////////////////////////////////////////////
//   ____  ____
//  /   /\/   /
// /___/  \  /    Vendor: Xilinx
// \   \   \/     Version: 1.0
//  \   \         Application : Vivado HLS
//  /   /         Filename: luinv_inv.c
// /___/   /\     Timestamp: Fri Aug 19 8:08:10 PST 2016
// \   \  /  \
//  \___\/\___\
//
//Command: N/A
//Device:  Xilinx Kintex-7, US, US+; Zynq-7000, US+
//Design Name: LUInv
//Purpose:
//    This function performs inversion of triangular matrices L and U
//Reference:
//    XAPP1317
///////////////////////////////////////////////////////////////////////////////

#include "luinv.h"

void luinv_inv(cfloat_t A[NL][NL], cfloat_t B[NL][NL], char P_in[NL+1], char P_out[NL+1]){

	char i, j, k;
	
	cfloat_t sl[NL-1];
	cfloat_t su[NL-1];
	cfloat_t slr[NL-1];
	cfloat_t sur[NL-1];
	char p[NL];
	//const unsigned char k=0;
	
	for(k=0;k<NL-1;k++){
	
		// copy the row to s
		luinv_inv_label0:for(i=k;i<NL-1;i++){
			sl[i]=neg(A[i+1][k]);
			su[i]=neg(A[k][i+1]);
		} 
	
		//iteratively update s
		loop_column: for(i=k+1;i<NL-1;i++){
		
			cfloat_t this_sl = neg(sl[i-1]);
			cfloat_t this_su = neg(su[i-1]);

			luinv_inv_label1:for(j=i;j<NL-1;j++){
				cfloat_t l=mul(this_sl, A[j+1][i]);
				cfloat_t u=mul(this_su, A[i][j+1]);
				slr[j] = add(sl[j], l);
				sur[j] = add(su[j], u);
			}

			luinv_inv_label2:for(j=i;j<NL-1;j++){
				sl[j]=slr[j];
				su[j]=sur[j];
			}
		}
		
		luinv_inv_label3:for(i=k;i<NL-1;i++){
			B[i+1][k] = sl[i];
			B[k][i+1] = su[i];
		}	
	}
	
	// copy B to A
	for(i=0;i<NL;i++) B[i][i] = A[i][i];
	
	// permute p and output
	for(i=0;i<NL;i++) p[i]=i;
	for(i=0;i<NL;i++){
		// exchange positions
		char m = P_in[i];
		char q = p[i];
		p[i] = p[m];
		p[m] = q;
		P_out[p[i]]=i;
	}
	P_out[NL] = P_in[NL];

}

