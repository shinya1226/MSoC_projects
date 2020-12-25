############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
############################################################
open_project proj_memory_porting_and_ii
set_top matrixmul
add_files matrixmul.cpp
add_files -tb matrixmul_test.cpp -cflags "-DHW_COSIM -Wno-unknown-pragmas"
open_solution "origin"
set_part {xc7z020clg484-1}
create_clock -period 10 -name default

set_directive_pipeline  "matrixmul/J_LOOP"

csim_design
csynth_design
cosim_design

close_project


##step1
open_project proj_memory_porting_and_ii
set_top matrixmul
add_files matrixmul.cpp
add_files -tb matrixmul_test.cpp -cflags "-DHW_COSIM -Wno-unknown-pragmas"
open_solution "step1"
set_part {xc7z020clg484-1}
create_clock -period 10 -name default

set_directive_pipeline  "matrixmul/J_LOOP"
set_directive_array_partition -type complete -dim 2 "matrixmul" a
set_directive_array_partition -type complete -dim 1 "matrixmul" b

csim_design
csynth_design
cosim_design

close_project


##step2
open_project proj_memory_porting_and_ii
set_top matrixmul
add_files matrixmul.cpp
add_files -tb matrixmul_test.cpp -cflags "-DHW_COSIM -Wno-unknown-pragmas"
open_solution "step2"
set_part {xc7z020clg484-1}
create_clock -period 10 -name default

set_directive_pipeline  "matrixmul/I_LOOP"
set_directive_pipeline  "matrixmul/J_LOOP"
set_directive_array_partition -type complete -dim 2 "matrixmul" a
set_directive_array_partition -type complete -dim 1 "matrixmul" b

csim_design
csynth_design
cosim_design

close_project


##step3
open_project proj_memory_porting_and_ii
set_top matrixmul
add_files matrixmul.cpp
add_files -tb matrixmul_test.cpp -cflags "-DHW_COSIM -Wno-unknown-pragmas"
open_solution "step3"
set_part {xc7z020clg484-1}
create_clock -period 10 -name default

set_directive_pipeline  "matrixmul/I_LOOP"
set_directive_pipeline  "matrixmul/J_LOOP"
set_directive_array_partition -type complete -dim 2 "matrixmul" a
set_directive_array_partition -type complete -dim 1 "matrixmul" a
set_directive_array_partition -type complete -dim 1 "matrixmul" b
set_directive_array_partition -type complete -dim 2 "matrixmul" b
set_directive_array_partition -type complete -dim 2 "matrixmul" res


csim_design
csynth_design
cosim_design

close_project


##step4
open_project proj_memory_porting_and_ii
set_top matrixmul
add_files matrixmul.cpp
add_files -tb matrixmul_test.cpp -cflags "-DHW_COSIM -Wno-unknown-pragmas"
open_solution "step4"
set_part {xc7z020clg484-1}
create_clock -period 10 -name default

set_directive_pipeline -rewind "matrixmul/J_LOOP"
set_directive_pipeline -rewind "matrixmul/I_LOOP"
set_directive_array_partition -type complete -dim 2 "matrixmul" a
set_directive_array_partition -type complete -dim 1 "matrixmul" a
set_directive_array_partition -type complete -dim 1 "matrixmul" b
set_directive_array_partition -type complete -dim 2 "matrixmul" b
set_directive_array_partition -type complete -dim 2 "matrixmul" res


csim_design
csynth_design
cosim_design

close_project


##onboard
open_project proj_memory_porting_and_ii
set_top matrixmul
add_files matrixmul.cpp
add_files -tb matrixmul_test.cpp -cflags "-DHW_COSIM -Wno-unknown-pragmas"
open_solution "onboard"
set_part {xc7z020clg484-1}
create_clock -period 10 -name default

set_directive_pipeline -rewind "matrixmul/J_LOOP"
set_directive_pipeline -rewind "matrixmul/I_LOOP"
set_directive_array_partition -type complete -dim 2 "matrixmul" a
set_directive_array_partition -type complete -dim 1 "matrixmul" a
set_directive_array_partition -type complete -dim 1 "matrixmul" b
set_directive_array_partition -type complete -dim 2 "matrixmul" b
set_directive_array_partition -type complete -dim 1 "matrixmul" res
set_directive_array_partition -type complete -dim 2 "matrixmul" res
set_directive_interface -mode s_axilite "matrixmul"
set_directive_interface -mode s_axilite "matrixmul" a
set_directive_interface -mode s_axilite "matrixmul" res
set_directive_interface -mode s_axilite "matrixmul" b

csim_design
csynth_design
cosim_design

close_project

exit
