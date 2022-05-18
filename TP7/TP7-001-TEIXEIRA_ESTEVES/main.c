#include <stdio.h>
#include "extern.h"
#include "extern_types.h"

int main() {
	Extern__f_out* _outf = NULL;
	Extern__g_out* _outg = NULL;
	int z = 0;
	for (;;) {
		if (_outg == NULL) {
			z = 123;
		}
		else {
			z = _outg->o;
		}
		_outf = Extern__f_step(z);
		_outg = Extern__g_step(_outf->o);
		sleep(1);	
	}	  
	return 0  ;
}
