#ifndef MYPROG_H
#define MYPROG_H

#include <stdio.h>
#include <stdlib.h>

#include "sndlib.h"

typedef struct { float *samples; } myread_out ;
typedef struct { } mywrite_out ;

void myread_step(int size, myread_out*_out) ;
void mywrite_step(int size, float *samples ,mywrite_out*_out) ;

#endif // MYPROG_H
