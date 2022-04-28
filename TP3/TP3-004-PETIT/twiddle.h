#ifndef TWIDDLE_V_H
#define TWIDDLE_V_H
#include "complex_c/complex.h"
#include "complex_io_types.h"

typedef struct { struct Complex__complex o; } Twiddle__twiddle_out ;


void Twiddle__twiddle_step(int k, int n, Twiddle__twiddle_out* _out) ;

#endif
