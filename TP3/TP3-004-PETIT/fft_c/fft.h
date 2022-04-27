/* --- Generated the 27/4/2022 at 17:19 --- */
/* --- heptagon compiler, version 1.05.00 (compiled wed. mar. 30 9:55:52 CET 2022) --- */
/* --- Command line: /home/ubuntu/.opam/default/bin/heptc -target c fft.ept --- */

#ifndef FFT_H
#define FFT_H

#include "fft_types.h"
#include "bitrev.h"
#include "complex.h"
typedef struct Fft__butterfly_params_2__out {
  Complex__complex o[2];
} Fft__butterfly_params_2__out;

void Fft__butterfly_params_2__step(Complex__complex i1[1],
                                   Complex__complex i2[1],
                                   Fft__butterfly_params_2__out* _out);

typedef struct Fft__bf_params_2__out {
  Complex__complex o[2];
} Fft__bf_params_2__out;

void Fft__bf_params_2__step(Complex__complex i[2],
                            Fft__bf_params_2__out* _out);

typedef struct Fft__fft_aux2_out {
  Complex__complex o[2];
} Fft__fft_aux2_out;

void Fft__fft_aux2_step(Complex__complex i[2], Fft__fft_aux2_out* _out);

typedef struct Fft__fft_aux4_out {
  Complex__complex out[4];
} Fft__fft_aux4_out;

void Fft__fft_aux4_step(Complex__complex i[4], Fft__fft_aux4_out* _out);

typedef struct Fft__fft_aux8_out {
  Complex__complex out[8];
} Fft__fft_aux8_out;

void Fft__fft_aux8_step(Complex__complex i[8], Fft__fft_aux8_out* _out);

typedef struct Fft__fft_aux16_out {
  Complex__complex out[16];
} Fft__fft_aux16_out;

void Fft__fft_aux16_step(Complex__complex i[16], Fft__fft_aux16_out* _out);

typedef struct Fft__fft8_out {
  Complex__complex out[8];
} Fft__fft8_out;

void Fft__fft8_step(Complex__complex i[8], Fft__fft8_out* _out);

typedef struct Fft__fft16_out {
  Complex__complex out[16];
} Fft__fft16_out;

void Fft__fft16_step(Complex__complex i[16], Fft__fft16_out* _out);

#endif // FFT_H
