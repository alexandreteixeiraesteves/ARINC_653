#include <stdio.h>
#include "twiddle_c/twiddle.h"
#include "twiddle.h"
#include <math.h>
void twiddle(int k, int n, Twiddle_out* _out){
	_out->o = Twiddle__c[k];
}

