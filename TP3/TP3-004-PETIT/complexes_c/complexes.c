/* --- Generated the 27/4/2022 at 14:25 --- */
/* --- heptagon compiler, version 1.05.00 (compiled wed. mar. 30 9:55:52 CET 2022) --- */
/* --- Command line: /home/ubuntu/.opam/default/bin/heptc -target c complexes.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "complexes.h"

void Complexes__complexes_step(Complexes__complexes_out* _out) {
  Complex__complex_add_out Complex__complex_add_out_st;
  Complex__complex_sub_out Complex__complex_sub_out_st;
  Complex__complex_mul_out Complex__complex_mul_out_st;
  Complex_io__read_complex_out Complex_io__read_complex_out_st;
  Complex_io__print_complex_out Complex_io__print_complex_out_st;
  
  Complex__complex o;
  Complex__complex p;
  Complex__complex q;
  Complex__complex r;
  Complex__complex s;
  Complex_io__read_complex_step(&Complex_io__read_complex_out_st);
  p = Complex_io__read_complex_out_st.o;
  Complex_io__print_complex_step(p, &Complex_io__print_complex_out_st);
  Complex_io__read_complex_step(&Complex_io__read_complex_out_st);
  o = Complex_io__read_complex_out_st.o;
  Complex_io__print_complex_step(o, &Complex_io__print_complex_out_st);
  Complex__complex_mul_step(o, p, &Complex__complex_mul_out_st);
  s = Complex__complex_mul_out_st.o;
  Complex_io__print_complex_step(s, &Complex_io__print_complex_out_st);
  Complex__complex_sub_step(o, p, &Complex__complex_sub_out_st);
  r = Complex__complex_sub_out_st.o;
  Complex_io__print_complex_step(r, &Complex_io__print_complex_out_st);
  Complex__complex_add_step(o, p, &Complex__complex_add_out_st);
  q = Complex__complex_add_out_st.o;
  Complex_io__print_complex_step(q, &Complex_io__print_complex_out_st);;
}

