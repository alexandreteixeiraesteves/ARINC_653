#include <stdio.h>
#include "twiddle_c/twiddle.h"
#include "twiddle.h"
#include <math.h>
void Twiddle__twiddle_step(int k, int n, Twiddle__twiddle_out* _out){
	_out->o = Twiddle__c[k];
}

