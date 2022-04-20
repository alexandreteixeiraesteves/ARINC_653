CC= gcc
CFLAGS= -I `heptc -where`/c     # options de compilation pour les sources C

#src=

main= main.c

#src_obj=

main_obj= $(main:.c=.o)

all:
	heptc -I `heptc -where`/c complex.ept
	heptc -I `heptc -where`/c -target c complex.ept
	$(CC) -I$(PWD) $(CFLAGS) -c complex_c/complex_types.c complex_c/complex.c
	heptc -c complex_io.epi
	$(CC) -I$(PWD) $(CFLAGS) -c complex_io_types.c complex_io.c 		
	heptc -c complex_vec_io.epi
	$(CC) -I$(PWD) $(CFLAGS) -c complex_vec_io_types.c complex_vec_io.c 
	heptc -I `heptc -where`/c complex_vec.ept
	heptc -I `heptc -where`/c -target c complex_vec.ept
	$(CC) -I$(PWD) $(CFLAGS) -c complex_vec_c/complex_vec_types.c complex_vec_c/complex_vec.c
	
	heptc -I `heptc -where`/c complex_vectors.ept
	heptc -I `heptc -where`/c -target c complex_vectors.ept
#	$(CC) -I$(PWD) $(CFLAGS) -c complex_vectors_c/complex_vectors_types.c complex_vectors_c/complex_vectors.c

##	$(CC) -I$(PWD) $(CFLAGS) -c $(src)
##	$(CC) -I$(PWD) $(CFLAGS) -c $(main)
##	$(CC) -I$(PWD) $(src_obj) $(main_obj) -o main

clean: 
	rm -rf $(src_obj) $(main_obj) complex_c complex_vec_c main *.o *.log *.obc *.mls *.epci

