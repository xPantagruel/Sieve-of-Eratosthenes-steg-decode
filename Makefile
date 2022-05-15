#makefile
#Řešení IJC-DU1, příklad a),b)
#Autor: Matej Macek, FIT
#Datum: 20.03.2022

#promene
GCC = gcc -g -std=c11 -pedantic -Wall -Wextra -O2


all: primes primes-i steg-decode

run: primes primes-i
	./primes
	./primes-i


primes: eratosthenes.o primes.o error.o
				$(GCC)  error.o primes.o  eratosthenes.o -o primes  -lm

primes-i: eratosthenes-i.o primes-i.o error.o
				$(GCC)  error.o primes-i.o  eratosthenes-i.o -o primes-i -lm

steg-decode: steg-decode.o eratosthenes.o ppm.o error.o
				$(GCC) error.o steg-decode.o eratosthenes.o ppm.o -o steg-decode -lm


eratosthenes.o: eratosthenes.c
				$(GCC)  -c eratosthenes.c -o eratosthenes.o

eratosthenes-i.o: eratosthenes.c
				$(GCC)    -DUSE_INLINE -c eratosthenes.c -o eratosthenes-i.o

primes.o: primes.c
				$(GCC)  -c primes.c -o primes.o

primes-i.o: primes.c
				$(GCC)  -DUSE_INLINE -c primes.c -o primes-i.o

steg-decode.o: steg-decode.c
				$(GCC)  -c steg-decode.c -o steg-decode.o
ppm.o: ppm.c
			$(GCC) -c ppm.c -o ppm.o

error.o:error.c
			$(GCC) -c error.c -o error.o


clean: clear

clear:
	rm *.o primes primes-i steg-decode
