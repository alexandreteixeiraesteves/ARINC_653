/* --- Generated the 27/4/2022 at 14:25 --- */
/* --- heptagon compiler, version 1.05.00 (compiled wed. mar. 30 9:55:52 CET 2022) --- */
/* --- Command line: /home/ubuntu/.opam/default/bin/heptc -target c complex.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "complex.h"

void Complex__complex_add_step(Complex__complex i1, Complex__complex i2,
                               Complex__complex_add_out* _out) {
  
  float v_1;
  float v;
  v_1 = (i1.im+i2.im);
  v = (i1.re+i2.re);
  _out->o.re = v;
  _out->o.im = v_1;;
}

void Complex__complex_sub_step(Complex__complex i1, Complex__complex i2,
                               Complex__complex_sub_out* _out) {
  
  float v_2;
  float v;
  v_2 = (i1.im-i2.im);
  v = (i1.re-i2.re);
  _out->o.re = v;
  _out->o.im = v_2;;
}

void Complex__complex_mul_step(Complex__complex i1, Complex__complex i2,
                               Complex__complex_mul_out* _out) {
  
  float v_7;
  float v_6;
  float v_5;
  float v_4;
  float v_3;
  float v;
  v_6 = (i1.im*i2.re);
  v_5 = (i1.re*i2.im);
  v_7 = (v_5+v_6);
  v_3 = (i1.im*i2.im);
  v = (i1.re*i2.re);
  v_4 = (v-v_3);
  _out->o.re = v_4;
  _out->o.im = v_7;;
}

