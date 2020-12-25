############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
############################################################
open_project INV
set_top luinv
add_files basic_math.c
add_files luinv_lup.c
add_files luinv_mul.c
add_files luinv_inv.c
add_files luinv.c
add_files -tb luinv_in.txt -cflags "-Wno-unknown-pragmas -Wno-unknown-pragmas -Wno-unknown-pragmas"
add_files -tb luinv_gold.txt -cflags "-Wno-unknown-pragmas -Wno-unknown-pragmas -Wno-unknown-pragmas"
add_files -tb tb_luinv.c -cflags "-Wno-unknown-pragmas -Wno-unknown-pragmas -Wno-unknown-pragmas"
open_solution "solution1"
set_part {xc7z020clg484-1}
create_clock -period 6 -name default
config_dataflow -default_channel pingpong -fifo_depth 0 -strict_mode warning
source "./directives.tcl"
csim_design
csynth_design
cosim_design
export_design -rtl verilog -format ip_catalog

exit