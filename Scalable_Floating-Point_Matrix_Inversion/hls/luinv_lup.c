///////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2016 Xilinx, Inc.
// All Rights Reserved
///////////////////////////////////////////////////////////////////////////////
//   ____  ____
//  /   /\/   /
// /___/  \  /    Vendor: Xilinx
// \   \   \/     Version: 1.0
//  \   \         Application : Vivado HLS
//  /   /         Filename: luinv_lup.c
// /___/   /\     Timestamp: Fri Aug 19 8:08:10 PST 2016
// \   \  /  \
//  \___\/\___\
//
//Command: N/A
//Device:  Xilinx Kintex-7, US, US+; Zynq-7000, US+
//Design Name: LUInv
//Purpose:
//    This file contains the LU decomposition function with pivoting 
//Reference:
//    XAPP1317
///////////////////////////////////////////////////////////////////////////////
#include "luinv.h"

void luinv_lup(cfloat_t A[NL*NL], cfloat_t B[NL][NL], char P[NL+1]){

	char i, j, k;
	
	cfloat_t C[NL][NL];
	cfloat_t u[NL];
	cfloat_t l[NL];
	cfloat_t v[NL];
	char stat = 0;
	unsigned short addr=0;

	// copy computed results.
	load_data: for(i=0;i<NL;i++)  for(j=0;j<NL;j++) C[j][i] = A[addr++];
	
	// loop for submatrix
	for(k=0; k<NL; k++){
		
		float big=-1.0;
		float pwr;
		char pos;
		cfloat_t invx;
		
		//pivoting
		seek_max: for(i=k;i<NL;i++){
			cfloat_t tmp;
			float pwrr, pwri;
			tmp = C[i][k];
			pwrr = tmp.real*tmp.real;
			pwri = tmp.imag*tmp.imag;
			pwr = pwrr+pwri;
			
			if(pwr>big){
				pos = i;
				big = pwr;
			}
			
		}
		float tmp_big;
		// check weather big is 0
		if(big==0.0){
			pos=k;
			tmp_big=1.0;
			stat=-1;
		}else{

			// swap the rows if needed
			
			tmp_big = 1./big;
			if (pos!=k){
				// swap pos and k
				for(i=0;i<NL;i++){
					cfloat_t tmp=C[pos][i];
					C[pos][i] = C[k][i];
					C[k][i] = tmp;
				}
			}

		}
		big = tmp_big;
		// write down the shift
		P[k]=pos;
		
		// inv
		invx.real = C[k][k].real*big;
		invx.imag = -C[k][k].imag*big;
		

		// extract the vectors u and l first
		luinv_lu_label0:for(i=k+1;i<NL;i++){
			cfloat_t tmp = C[k][i];
			u[i] = tmp;
			v[i] = mul(invx,  tmp);
			
			tmp  = mul(invx, C[i][k]);
			l[i] = tmp;
			C[i][k] = tmp;
		}


		// write out the kth row
		luinv_lu_label2:for(i=0;i<NL;i++){
			B[k][i] = (i<k)? C[k][i] : (i==k)? invx : v[i];
		}

		// start processing the (19-k)x(19-k) sub-matrix
		// column by column
		luinv_lu_label3:for(i=k+1;i<NL;i++){
			
			cfloat_t w[NL];

			luinv_lu_label4:for(j=k+1;j<NL;j++){
				cfloat_t tmp = mul(l[j], u[i]);
				w[j] = sub(C[j][i], tmp);
			}

			// below is direct pass through
			luinv_lu_label5:for(j=k+1;j<NL;j++) C[j][i]=w[j];
			
		}
		
		
		 
	}// end of loop for sub-matrix
	
	// write out status
	P[NL]=stat;

}



