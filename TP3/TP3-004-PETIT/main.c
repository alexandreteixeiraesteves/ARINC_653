#include <stdio.h>
#include "twiddle.h"
#include "twiddle_init.h"
#include "twiddle_c/twiddle.h"
#include "complex_io_types.h"
#include "complex_c/complex.h"
int main() {
	Complex__complex c[1024];
	init_twiddle1024(c);
	fft_test();
	return 0;
}
