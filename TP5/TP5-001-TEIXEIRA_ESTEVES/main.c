#include "myprog.h"
#include "main_prog_c/main_prog.h"
#include "twiddle.h"
void main() {
	Main__main_prog_mem s;
	Main__main_prog_out _out;
	Main__main_prog_reset(&s);
	init_twiddle1024(Twiddle__twiddle);	
	for(;;) {
		Main__main_prog_step(&_out,&s);
	}
}
