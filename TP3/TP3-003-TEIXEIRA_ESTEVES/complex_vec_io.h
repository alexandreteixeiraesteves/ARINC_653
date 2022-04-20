#ifndef COMPLEX_VEC_IO_H
#define COMPLEX_VEC_IO_H

#include <stdio.h>
#include <stdlib.h>

#include "complex_c/complex.h"

typedef struct { struct Complex__complex* o; } Complex_io__read_complex_vector_out ;
typedef struct { } Complex_io__print_complex_vector_out ;

void Complex_io__read_complex_vector_step(Complex_io__read_complex_vector_out*_out) ;
void Complex_io__print_complex_vector_step(struct Complex__complex* c,Complex_io__print_complex_vector_out*_out) ;

#endif // COMPLEX_VEC_IO_H
