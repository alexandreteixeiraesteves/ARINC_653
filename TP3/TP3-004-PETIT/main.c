#include <stdio.h>
#include "twiddle.h"
#include "twiddle_init.h"
int main() {
	Complex__complex* o;
	init_twiddle1024(o);
	printf("%f + i %f\n", o[2].re, o[2].im);
	return 0;
}
