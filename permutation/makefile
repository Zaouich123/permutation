opt = -c -Wall -Wextra

permutation.exe : test_permutation.o p_base.o p_permutation.o
	gcc -o test_permutation.exe test_permutation.o p_base.o p_permutation.o

p_base.o : p_base.c p_base.h
	gcc ${opt} p_base.c

p_permutation.o : p_permutation.c p_permutation.h
	gcc ${opt} p_permutation.c

clean :
	rm *.o
	rm *.exe
	rm *.txt