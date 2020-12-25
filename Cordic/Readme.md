
Intro: Thsi project is for Cordic, uses in calculate the Trigonometric function of sin and cos, by rotating signal.

Built up: Source the tcl in hls\Final, by vivado_hls -f cordic.tcl 

Algorithm: Basic algorithm is to rotate the signal for a defined iteration to make it approach the desired value. In the original code, it has some uses in multiply that cause the cost of DSP, but these could be calculate with MUX and shifter. So, modify the coding style to improve the utilization. 

Reference: https://github.com/KastnerRG/pp4fpgas/tree/master/examples