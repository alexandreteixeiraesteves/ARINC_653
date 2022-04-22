CC= gcc
CFLAGS= -std=c99 -I'build' # options de compilation pour les sources C
LDFLAGS = -lm -lc -lgcc
#pre_src= complex_c/complex.c #complex_io.c
src= complex_c/complex_types.c complex_c/complex.c complex_io_types.c complex_io.c complexes_c/complexes_types.c complexes_c/complexes.c

main= main.c

src_obj= complex_types.o complex.o complex_io_types.o complex_io.o complexes_types.o complexes.o twiddle_init.o twiddle.o 

main_obj= $(main:.c=.o)

#-I'complex_c' -I'complexes_c'

all:
	heptc -target c complex.ept
	heptc -c complex_io.epi
	heptc -target c complexes.ept
	heptc -target c twiddle.epi
	cp complex_io_types.h complexes_c/.
	cp -r complex_c/ complexes_c/.
	cp complex_io.h complexes_c/.
	mkdir build/
	cp `heptc -where`/c/pervasives.h build/.
	gcc $(CFLAGS) -c complex_c/complex_types.c complex_c/complex.c $(LDFLAGS)
	gcc $(CFLAGS) -c complex_io_types.c complex_io.c $(LDFLAGS)
	gcc $(CFLAGS) -I'complex_c' -c complexes_c/complexes_types.c complexes_c/complexes.c $(LDFLAGS)
	gcc $(CFLAGS) -I'complex_c' -c twiddle_init.c twiddle.c $(LDFLAGS)
	gcc $(CFLAGS) -I'complex_c' -c $(main) $(LDFLAGS)
	gcc $(CFLAGS) $(src_obj) $(main_obj) -o main $(LDFLAGS)

clean: 
	rm -rf $(src_obj) $(main_obj) complex_c complexes_c main complexes_types.o complexes.o *.log *.obc *.mls *.epci build

