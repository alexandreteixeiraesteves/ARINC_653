#include "myprog.h"

void main() {
	myread_out read_out;
	mywrite_out write_out;
	for(;;) {
		myread_step(256, &read_out);
		float *tmp;
		tmp = read_out.samples;
		for(int i = 0; i < 256; i++)
			tmp[i] = tmp[i] / (float)2;
		mywrite_step(256, tmp, &write_out);
	}
}
