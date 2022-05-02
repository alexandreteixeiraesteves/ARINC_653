#include "myprog.h"

void main() {
	Myprog__myread_out read_out;
	Myprog__mywrite_out write_out;
	for(;;) {
		Myprog__myread_step(256, &read_out);
		float *tmp;
		tmp = read_out.samples;
		for(int i = 0; i < 256; i++)
			tmp[i] = tmp[i] / (float)2;
		Myprog__mywrite_step(256, tmp, &write_out);
	}
}
