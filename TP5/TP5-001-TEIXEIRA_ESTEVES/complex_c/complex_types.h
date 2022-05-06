/* --- Generated the 6/5/2022 at 17:19 --- */
/* --- heptagon compiler, version 1.05.00 (compiled wed. mar. 30 19:47:23 CET 2022) --- */
/* --- Command line: /home/teabis/.opam/default/bin/heptc -target c complex.ept --- */

#ifndef COMPLEX_TYPES_H
#define COMPLEX_TYPES_H

#include "stdbool.h"
#include "assert.h"
#include "pervasives.h"
static const float Complex__pi = 3.141593;

typedef struct Complex__complex {
  float re;
  float im;
} Complex__complex;

#endif // COMPLEX_TYPES_H
