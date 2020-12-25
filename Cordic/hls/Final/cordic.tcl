############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 2012 Xilinx Inc. All rights reserved.
############################################################
open_project cordic
set_top cordic
add_files cordic.h
add_files cordic.cpp
add_files -tb cordic_test.cpp
open_solution "solution1"
set_part  {xc7z020clg484-1}
create_clock -period 10

source "./directives.tcl"
csim_design
csynth_design
cosim_design -trace_level all -tool xsim
export_design -rtl verilog -format ip_catalog

exit