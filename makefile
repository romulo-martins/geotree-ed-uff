# Makefile para realizar a compilação
gentree_test: tests/gentree_test.c lib/gentree.c lib/gentree.h
	gcc -o gentree_test.out tests/gentree_test.c lib/gentree.c