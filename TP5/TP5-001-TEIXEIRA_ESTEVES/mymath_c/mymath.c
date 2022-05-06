#include <math.h>
#include "mymath.h"

void Mymath__asin_step(float i, Mymath__asin_out  *_out) {
  _out->o = asinf(i) ;
}
void Mymath__acos_step(float i, Mymath__acos_out  *_out) {
  _out->o = acosf(i) ;
}
void Mymath__atan2_step(float im,float re, Mymath__atan2_out  *_out) {
  _out->o = atan2(im,re) ;
}
void Mymath__round_step(float i, Mymath__round_out  *_out) {
  _out->o = roundf(i) ;
}
void Mymath__sqrt_step(float i, Mymath__sqrt_out  *_out) {
  _out->o = sqrtf(i) ;
}
void Mymath__sin_step(float i, Mymath__sin_out  *_out) {
  _out->o = sinf(i) ;
}
void Mymath__cos_step(float i, Mymath__cos_out  *_out) {
  _out->o = cosf(i) ;
}
void Mymath__int2float_step(int i, Mymath__int2float_out  *_out) {
  _out->o = (float)i ;
}
void Mymath__float2int_step(float i, Mymath__float2int_out  *_out) {
  _out->o = (int)i ;
}
void Mymath__pow_step(float i1,float i2, Mymath__pow_out  *_out) {
  _out->o = pow(i1,i2) ;
}
void Mymath__int_is_odd_step(int i, Mymath__int_is_odd_out  *_out) {
  _out->o = i&1 ;
}
