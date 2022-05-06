#!/bin/bash

set -x

heptc -target c complex.ept
heptc -target c constants.ept
heptc float.epi
heptc fftc.epi

gcc -I`heptc -where`/c -c complex_c/complex.c
gcc -I`heptc -where`/c -c constants_c/constants.c
gcc -c -I./mymath_c/ mymath_c/mymath.c
gcc -I`heptc -where`/c -I ./constants_c/ -I ./complex_c/ -c fftc_c/fftc.c
