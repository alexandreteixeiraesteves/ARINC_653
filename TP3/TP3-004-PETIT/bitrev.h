#ifndef BITREV_H
#define BITREV_H
#include "bitrev_types.h"
#include "complex_c/complex.h"

typedef struct { struct Complex__complex o; } Fftc__bitrev16_out ;
typedef struct { struct Complex__complex o; } Fftc__bitrev8_out ;

void Fftc__bitrev16_step(Complex__complex*i,Complex__complex*o);
void Fftc__bitrev8_step(Complex__complex*i,Complex__complex*o);

#endif
