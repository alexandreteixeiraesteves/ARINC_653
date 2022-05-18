#ifndef EXTERN_H
#define EXTERN_H
#include "extern_types.h"

typedef struct { int o; } Extern_f_out ;
typedef struct { int o; } Extern_g_out ;

void Extern__f_step(int i, Extern_f_out* _out);
void Extern__g_step(int i, Extern_g_out* _out);

#endif
