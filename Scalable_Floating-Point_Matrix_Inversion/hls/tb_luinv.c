///////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2016 Xilinx, Inc.
// All Rights Reserved
///////////////////////////////////////////////////////////////////////////////
//   ____  ____
//  /   /\/   /
// /___/  \  /    Vendor: Xilinx
// \   \   \/     Version: 1.0
//  \   \         Application : Vivado HLS
//  /   /         Filename: tb_luinv.c
// /___/   /\     Timestamp: Fri Aug 19 8:08:10 PST 2016
// \   \  /  \
//  \___\/\___\
//
//Command: N/A
//Device:  Xilinx Kintex-7, US, US+; Zynq-7000, US+
//Design Name: LUInv
//Purpose:
//    This is the testbench for LU matrix inversion function
//Reference:
//    XAPP1317
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include "luinv.h"

//---------------------------------
// downlink filter chain
//---------------------------------
int main(){

	cfloat_t din[NL*NL];
	cfloat_t dout[NL*NL];
		
	FILE *fpi;
	FILE *fpo;
	
	int   m, n;
	float tmp1, tmp2;
	int errcnt       = 0;
	int linecnt      = 0;
	int fileend=0;
	unsigned char stat;
	int stat_gold;
	
	FILE* fp=NULL;
	fp=fopen("luinv_in.txt", "rt");
	if(NULL==fp){
		printf("Error Opening Input Test Vector!\n");
		return(1);
	}
	
	FILE* fp_gold=NULL;
	fp_gold=fopen("luinv_gold.txt", "rt");
	if(NULL==fp_gold){
		printf("Error Opening Golden Output Test Vector!\n");
		return(1);
	}
	
	while(1){
		
		// read the data in
		for(n=0;n<NL*NL;n++){

				int scnt = fscanf(fp, "%e %e", &tmp1, &tmp2);
				din[n].real=tmp1; din[n].imag=tmp2;

				if (scnt < 0) {
					fileend = 1;
					break;
				}
		}
		
		// quit the loop at the file end
		if(fileend) break;
		linecnt++;
		
		// process the data
		stat = luinv(din, dout);

		// read data from golden test vector
		unsigned char this_is_err=0;
		char stat_g;
		fscanf(fp_gold, "%d", &stat_gold);
		stat_g = stat_gold;
								
		if (stat != stat_g){
			this_is_err=1;
			if(errcnt<=5) printf("[Err %3d] line %d\n", errcnt, linecnt);
		}
		errcnt+=this_is_err;	

		
		for(n=0;n<NL*NL;n++){
				
				fscanf(fp_gold, "%e %e", &tmp1, &tmp2);
								
				if ((dout[n].real != tmp1)||(dout[n].imag != tmp2)) {
					this_is_err=1;
					if(errcnt<=5) printf("[Err %3d] line %d\n", errcnt, linecnt);
				}
				errcnt+=this_is_err;	
		}
					
	}
	
	fclose(fp);
	fclose(fp_gold);

	printf("Total %d Test Vectors, Err Count = %d.\n", linecnt, errcnt);

	if (errcnt) printf("Test Failed!\n");
	else printf("Test Passed!\n");

	return(errcnt);
	

}
