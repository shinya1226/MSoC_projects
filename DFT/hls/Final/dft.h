

typedef float DTYPE;
//typedef hls::stream<DTYPE> stream_t;
#define SIZE 256 		/* SIZE OF DFT */
void dft(volatile DTYPE* XX_R,volatile DTYPE* XX_I,volatile DTYPE* out_r,volatile DTYPE* out_i);


