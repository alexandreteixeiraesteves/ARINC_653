/* --- Generated the 27/4/2022 at 17:19 --- */
/* --- heptagon compiler, version 1.05.00 (compiled wed. mar. 30 9:55:52 CET 2022) --- */
/* --- Command line: /home/ubuntu/.opam/default/bin/heptc -target c fft_test.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fft_test.h"

void Fft_test__fft8_step(Fft_test__fft8_out* _out) {
  Complex_vec_io__print_complex_vector_out Complex_vec_io__print_complex_vector_out_st;
  Fft__fft8_out Fft__fft8_out_st;
  
  Complex__complex v_1[8];
  Complex__complex v[8];
  Complex__complex o[8];
  Complex__complex o1[8];
  v_1[0].im = 0.000000;
  v_1[0].re = 0.000000;
  v_1[1].im = 0.000000;
  v_1[1].re = 1.000000;
  v_1[2].im = 0.000000;
  v_1[2].re = 0.000000;
  v_1[3].im = 0.000000;
  v_1[3].re = 0.000000;
  v_1[4].im = 0.000000;
  v_1[4].re = 0.000000;
  v_1[5].im = 0.000000;
  v_1[5].re = 0.000000;
  v_1[6].im = 0.000000;
  v_1[6].re = 0.000000;
  v_1[7].im = 0.000000;
  v_1[7].re = 0.000000;
  Fft__fft8_step(v_1, &Fft__fft8_out_st);
  {
    int _1;
    for (_1 = 0; _1 < 8; ++_1) {
      o1[_1] = Fft__fft8_out_st.out[_1];
    }
  };
  Complex_vec_io__print_complex_vector_step(o1,
                                            &Complex_vec_io__print_complex_vector_out_st);
  v[0].im = 0.000000;
  v[0].re = 1.000000;
  v[1].im = 0.000000;
  v[1].re = 0.000000;
  v[2].im = 0.000000;
  v[2].re = 0.000000;
  v[3].im = 0.000000;
  v[3].re = 0.000000;
  v[4].im = 0.000000;
  v[4].re = 0.000000;
  v[5].im = 0.000000;
  v[5].re = 0.000000;
  v[6].im = 0.000000;
  v[6].re = 0.000000;
  v[7].im = 0.000000;
  v[7].re = 0.000000;
  Fft__fft8_step(v, &Fft__fft8_out_st);
  {
    int _2;
    for (_2 = 0; _2 < 8; ++_2) {
      o[_2] = Fft__fft8_out_st.out[_2];
    }
  };
  Complex_vec_io__print_complex_vector_step(o,
                                            &Complex_vec_io__print_complex_vector_out_st);;
}

