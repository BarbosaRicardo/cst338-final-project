all: threadHello_step1 threadHello_step2_fixed matrix_multiply

threadHello_step1: threadHello_step1.c 
	gcc -o threadHello_step1 threadHello_step1.c -Wall -pthread

matrix_multiply: matrix_multiply.c
	gcc -o matrix_multiply matrix_multiply.c -Wall -pthread

threadHello_step2_fixed: threadHello_step2_fixed.c
	gcc -o threadHello_step2_fixed threadHello_step2_fixed.c -Wall -pthread

clean:
	rm -f *.o threadHello_step1 threadHello_step2_fixed matrix_multiply