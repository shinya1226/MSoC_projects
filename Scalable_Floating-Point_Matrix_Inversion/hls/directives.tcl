############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
############################################################
set_directive_pipeline -II 1 "luinv_lup/load_data"
set_directive_pipeline -II 1 "luinv_lup/luinv_lu_label4"
set_directive_loop_tripcount -min 1 -max 20 "luinv_lup/seek_max"
set_directive_loop_tripcount -min 1 -max 19 "luinv_lup/luinv_lu_label3"
set_directive_loop_tripcount -min 1 -max 20 "luinv_lup/luinv_lu_label4"
set_directive_loop_tripcount -min 1 -max 19 "luinv_lup/luinv_lu_label5"
set_directive_pipeline -II 1 "luinv_inv/luinv_inv_label0"
set_directive_pipeline -II 2 "luinv_inv/luinv_inv_label1"
set_directive_pipeline -II 2 "luinv_inv/luinv_inv_label2"
set_directive_pipeline -II 2 "luinv_inv/luinv_inv_label3"
set_directive_loop_tripcount -min 1 -max 19 "luinv_inv/luinv_inv_label0"
set_directive_loop_tripcount -min 1 -max 18 "luinv_inv/loop_column"
set_directive_loop_tripcount -min 1 -max 18 "luinv_inv/luinv_inv_label1"
set_directive_loop_tripcount -min 1 -max 19 "luinv_inv/luinv_inv_label2"
set_directive_loop_tripcount -min 1 -max 19 "luinv_inv/luinv_inv_label3"
set_directive_pipeline -II 1 "luinv_mul/luinv_mul_label0"
set_directive_pipeline -II 1 "luinv_mul/luinv_mul_label1"
set_directive_pipeline -II 1 "luinv_mul/luinv_mul_label2"
set_directive_pipeline -II 1 "luinv_mul/luinv_mul_label3"
set_directive_pipeline -II 1 "luinv_mul/luinv_mul_label4"
set_directive_pipeline -II 1 "luinv_mul/luinv_mul_label7"
set_directive_pipeline -II 1 "luinv_mul/save_data"
set_directive_loop_tripcount -min 1 -max 19 "luinv_mul/luinv_mul_label0"
set_directive_loop_tripcount -min 1 -max 19 "luinv_mul/luinv_mul_label1"
set_directive_loop_tripcount -min 1 -max 19 "luinv_mul/luinv_mul_label2"
set_directive_loop_tripcount -min 1 -max 20 "luinv_mul/luinv_mul_label3"
set_directive_loop_tripcount -min 1 -max 20 "luinv_mul/luinv_mul_label4"
set_directive_loop_tripcount -min 1 -max 20 "luinv_mul/luinv_mul_label5"
set_directive_loop_tripcount -min 1 -max 19 "luinv_mul/luinv_mul_label6"
set_directive_loop_tripcount -min 1 -max 20 "luinv_mul/luinv_mul_label7"
set_directive_loop_tripcount -min 1 -max 19 "luinv_mul/luinv_mul_label8"
set_directive_interface -mode m_axi -depth 1024 -latency 3 -offset slave "luinv" A->real
set_directive_interface -mode m_axi -depth 1024 -latency 3 -offset slave "luinv" A->imag
set_directive_interface -mode m_axi -depth 1024 -latency 3 -offset slave "luinv" Ainv->real
set_directive_interface -mode m_axi -depth 1024 -latency 3 -offset slave "luinv" Ainv->imag
set_directive_interface -mode s_axilite "luinv"
set_directive_loop_tripcount -min 1 -max 19 "luinv_lup/luinv_lu_label0"
set_directive_pipeline -II 1 "luinv_mul/luinv_mul_label5"
set_directive_pipeline -II 1 "luinv_lup/luinv_lu_label2"
set_directive_pipeline -rewind "luinv_mul/luinv_mul_label8"
set_directive_pipeline -rewind "luinv_lup/luinv_lu_label5"
set_directive_dataflow "luinv"
