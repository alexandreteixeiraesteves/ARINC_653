#ifndef FFTC_H
#define FFTC_H

#include <constants_types.h>
#include <complex_types.h>

void Fftc__init_fft_step(void) ;
typedef struct { float o; } Fftc__hann_out;
typedef struct { Complex__complex o; } Fftc__twiddle_out;
void Fftc__hann_step(int i,Fftc__hann_out*_out) ;
void Fftc__twiddle_step(int i,Fftc__twiddle_out*_out) ;

typedef struct { Complex__complex o[8]; } Fftc__bitrev8_out;
void Fftc__bitrev8_step(Complex__complex* i,Fftc__bitrev8_out*_out) ;
typedef struct { Complex__complex o[Constants__fft_size]; } Fftc__bitrev_out;
void Fftc__bitrev_step(Complex__complex* i,Fftc__bitrev_out*_out) ;


#endif
