#include <stdio.h>
#include "twiddle.h"
#include <math.h>
void Twiddle__twiddle_step(int k, int n, Twiddle__twiddle_out* _out){
	_out->o = Twiddle__twiddle[k+(n/2)];
	printf("%f + i%f\n\n", _out->o.re, _out->o.im);
}

