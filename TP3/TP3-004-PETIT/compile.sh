#!/bin/bash
heptc -target c complex.ept
heptc -c complex_io.epi
heptc -target c complexes.ept
heptc -target c twiddle.epi
heptc -c fft.ept
heptc -c bitrev.epi
heptc -c complex_vec_io.epi
heptc -target c fft_test.ept

cp complex_io_types.h complexes_c/.
cp -r complex_c/ complexes_c/.
cp complex_io.h complexes_c/.


if [ ! -d "build" ];then
mkdir build/
fi



cp `heptc -where`/c/pervasives.h build/.
gcc -std=c99 -I'build' -c complex_c/complex_types.c complex_c/complex.c -lm -lc -lgcc
gcc -std=c99 -I'build' -c complex_io_types.c complex_io.c -lm -lc -lgcc
gcc -std=c99 -I'build' -I'complex_c' -c complexes_c/complexes_types.c complexes_c/complexes.c -lm -lc -lgcc
gcc -std=c99 -I'build' -I'complex_c' -c twiddle_init.c twiddle.c -lm -lc -lgcc
gcc -std=c99 -I'build' -c bitrev.c complex_vec_io.c -lm -lc -lgcc

gcc -std=c99 -I'build' -I'complex_c' -c main.c -lm -lc -lgcc
gcc -std=c99 -I'build' complex_types.o complex.o complex_io_types.o complex_io.o complexes_types.o complexes.o twiddle_init.o twiddle.o main.o -o main -lm -lc -lgcc

