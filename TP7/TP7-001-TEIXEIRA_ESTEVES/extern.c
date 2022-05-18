#include <stdio.h>
#include "extern.h"
void Extern__f_step(int i, Extern_f_out* _out){
	_out->o = i + 5;
	printf("%d + 5 = %d\n", i, _out->o);
}

void Extern__g_step(int i, Extern_g_out* _out){
	_out->o = i + 1;
	printf("%d + 1 = %d\n", i, _out->o);
}
