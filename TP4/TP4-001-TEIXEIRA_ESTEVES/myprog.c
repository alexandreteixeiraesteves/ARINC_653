#include "myprog.h"


void Myprog__myread_step(int size, Myprog__myread_out*_out){
	float tmp[size];
	Sndlib__read_samples_step(&size,tmp);
	_out->samples = tmp;
}

void Myprog__mywrite_step(int size, float *samples , Myprog__mywrite_out*_out){
	Sndlib__write_samples_step(&size,samples) ; 
}
