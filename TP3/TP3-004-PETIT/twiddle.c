#include <stdio.h>
#include "twiddle.h"
#include "twiddle_init.h"
#include <math.h>
void twiddle(int k, int n, Twiddle_out* _out){
	Complex__complex c[n];
	init_twiddle1024(c);
	_out->o = c;
}

