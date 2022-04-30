#include "myprog.h"


void myread_step(int size, myread_out*_out){
	
	//for(int i = 0 ; i < 256 ; i++) {
	float tmp[size];
	Sndlib__read_samples_step(&size,tmp);
	_out->samples = tmp;
	//}
}

void mywrite_step(int size, float *samples , mywrite_out*_out){
	
	//for(int i = 0 ; i < 256 ; i++) {
        //float tmp[size];
        //tmp = samples ;
	Sndlib__write_samples_step(&size,samples) ;
        //}
}
