#!/bin/bash
heptc -target c complex.ept
heptc -target c complex_io.epi
heptc -target c complexes.ept
heptc -c twiddle.epi
heptc -target c bitrev.epi
heptc -target c fft.ept
heptc -target c complex_vec_io.epi
heptc complex_vec_io.epi
heptc -target c fft_test.ept

cp complex_c/complex_types.h complexes_c/.
cp complex_io_types.h complexes_c/.
cp complex_io.h complexes_c/.
cp -r complex_c/ complexes_c/.
cp bitrev_types.h fft_c/.
cp bitrev.h fft_c/.
cp complex_c/complex_types.h fft_c/.
cp -r complex_c/ fft_c/.
cp complex_c/complex_types.h fft_test_c/.
cp complex_vec_io_types.h fft_test_c/.
cp fft_c/fft_types.h fft_test_c/.

cp bitrev_types.h fft_test_c/.
cp bitrev.h fft_test_c/.
cp bitrev_types.c fft_test_c/.
cp bitrev.c fft_test_c/.
cp complex_c/complex_types.h fft_test_c/.
cp complex_c/complex_types.c fft_test_c/.
cp -r complex_c/ fft_test_c/.
cp complex_vec_io.h fft_test_c/.
cp fft_c/fft.h fft_test_c/.
cp complex_vec_io.c fft_test_c/.
cp fft_c/fft.c fft_test_c/.
cp complex_io_types.h fft_test_c/.
cp complex_io_types.c fft_test_c/.

echo "Entrée"

if [ ! -d "build" ];then
mkdir build/
fi

cp `heptc -where`/c/pervasives.h build/.

gcc -std=c99 -I'build' -c complex_c/complex_types.c complex_c/complex.c -lm -lc -lgcc
gcc -std=c99 -I'build' -c complex_io_types.c complex_io.c -lm -lc -lgcc
gcc -std=c99 -I'build' -c complexes_c/complexes_types.c complexes_c/complexes.c -lm -lc -lgcc
gcc -std=c99 -I'build' -I'complex_c' -c twiddle_init.c twiddle.c -lm -lc -lgcc
gcc -std=c99 -I'build' -c bitrev.c complex_vec_io.c -lm -lc -lgcc
gcc -std=c99 -I'build' -c fft_c/fft.c fft_c/fft_types.c -lm -lc -lgcc
gcc -std=c99 -I'build' -I'bitrev_c' -c fft_test_c/fft_test.c fft_test_c/fft_test_types.c -lm -lc -lgcc
gcc -std=c99 -I'build' -I'complex_c' -I'fft_c' -I'bitrev_c' -c main.c -lm -lc -lgcc

gcc -std=c99 -I'build' complex_types.o complex.o complex_io_types.o complex_io.o complexes_types.o complexes.o twiddle_init.o twiddle.o main.o -o main -lm -lc -lgcc

