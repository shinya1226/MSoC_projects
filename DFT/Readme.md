
Intro: Thsi project is DFT, uses for converting signal in frequency domain and time domain.

Built up: Source the tcl in hls\Final, by vivado_hls -f DFT.tcl 

Algorithm: The basic algorithm is to mutiply cos and sin with Complex number. Because cos and sin are calculate with C library's function, it may cost a lot for hardware design. The improved way used LUT for cos and sin to reduce using of DSP. Besides, due to the symmetric of sin and cos, we can fold the dut table to only 1/4 for sin and cos. 

Reference: https://github.com/KastnerRG/pp4fpgas/tree/master/examples