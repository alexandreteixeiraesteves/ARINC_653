/* --- Generated the 27/4/2022 at 14:25 --- */
/* --- heptagon compiler, version 1.05.00 (compiled wed. mar. 30 9:55:52 CET 2022) --- */
/* --- Command line: /home/ubuntu/.opam/default/bin/heptc -target c complex.ept --- */

#ifndef COMPLEX_H
#define COMPLEX_H

#include "complex_types.h"
typedef struct Complex__complex_add_out {
  Complex__complex o;
} Complex__complex_add_out;

void Complex__complex_add_step(Complex__complex i1, Complex__complex i2,
                               Complex__complex_add_out* _out);

typedef struct Complex__complex_sub_out {
  Complex__complex o;
} Complex__complex_sub_out;

void Complex__complex_sub_step(Complex__complex i1, Complex__complex i2,
                               Complex__complex_sub_out* _out);

typedef struct Complex__complex_mul_out {
  Complex__complex o;
} Complex__complex_mul_out;

void Complex__complex_mul_step(Complex__complex i1, Complex__complex i2,
                               Complex__complex_mul_out* _out);

#endif // COMPLEX_H
