CC= gcc
CFLAGS= -I `heptc -where`/c     # options de compilation pour les sources C

main= main.c

main_obj= $(main:.c=.o)

all:
	$(CC) -I$(PWD) $(CFLAGS) -c sndlib.c
	heptc -c myprog.epi
	$(CC) -I$(PWD) $(CFLAGS) -c myprog.c
	$(CC) -I$(PWD) $(CFLAGS) -c main.c
	
	$(CC) -I$(PWD) sndlib.o myprog.o main.o -o main

run:
	rec -t raw -r 44100 -e signed -b 16 -c 2 - | ./main | play -t raw -r 44100 -e signed -b 16 -c 2 -

clean: 
	rm -rf main *.epci *.o 



#	heptc -I `heptc -where`/c complex.ept
#	heptc -I `heptc -where`/c -target c complex.ept
#	$(CC) -I$(PWD) $(CFLAGS) -c complex_c/complex_types.c complex_c/complex.c
#	heptc -c complex_io.epi
#	$(CC) -I$(PWD) $(CFLAGS) -c complex_io_types.c complex_io.c 		
