#ifndef MYMATH_H
#define MYMATH_H

struct out_float { float o; } ;

typedef struct out_float Mymath__asin_out;
typedef struct out_float Mymath__acos_out;
typedef struct out_float Mymath__atan2_out;
typedef struct out_float Mymath__round_out;
typedef struct out_float Mymath__sqrt_out;
typedef struct out_float Mymath__sin_out;
typedef struct out_float Mymath__cos_out;
typedef struct out_float Mymath__int2float_out;
typedef struct out_float Mymath__pow_out;

typedef struct { int o; } Mymath__float2int_out;
typedef struct { int o; } Mymath__int_is_odd_out;

void Mymath__asin_step (float,       Mymath__asin_out  *_out) ;
void Mymath__acos_step (float,       Mymath__acos_out  *_out) ;
void Mymath__atan2_step(float,float, Mymath__atan2_out *_out) ;
void Mymath__round_step(float,       Mymath__round_out *_out) ;
void Mymath__sqrt_step (float,       Mymath__sqrt_out  *_out) ;
void Mymath__sin_step  (float,       Mymath__sin_out   *_out) ;
void Mymath__cos_step  (float,       Mymath__cos_out   *_out) ;
void Mymath__int2float_step  (int,   Mymath__int2float_out   *_out) ;
void Mymath__pow_step  (float,float, Mymath__pow_out   *_out) ;

void Mymath__float2int_step  (float, Mymath__float2int_out   *_out) ;
void Mymath__int_is_odd_step (int,   Mymath__int_is_odd_out  *_out) ;

#endif
