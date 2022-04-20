#include "complex_vec_io.h"

void Complex_io__read_complex_vector_step(Complex_io__read_complex_vector_out*_out){
	struct Complex__complex complex_vec[3];
	for( size_t i = 0 ; i < 3 ; i++){
		struct Complex__complex tmp;
		scanf("%f",&tmp.re) ;
        	scanf("%f",&tmp.im) ;
		complex_vec[i] = tmp;
	}
	_out->o = complex_vec;
}

void Complex_io__print_complex_vector_step(struct Complex__complex* c,Complex_io__print_complex_vector_out*_out){
	
	for( size_t i = 0 ; i < 3 ; i++){
		struct Complex__complex tmp = c[i];
		printf(" %f + i %f \n", c->re, c->im);
	}
}
