#ifndef TWIDDLE_V_H
#define TWIDDLE_V_H
#include "complex_c/complex.h"
#include "complex_io_types.h"

typedef struct { struct Complex__complex o; } Twiddle_out ;


void twiddle(int k, int n, Twiddle_out* _out) ;

#endif
