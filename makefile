# Makefile para realizar a compilação
gentree_test: tests/gentree_test.c lib/gentree.c lib/gentree.h
	gcc -o gentree_test.out tests/gentree_test.c lib/gentree.c lib/figuras.c -lm

gentree_wfigs_test: tests/gentree_wfigs_test.c lib/gentree.c lib/gentree.h lib/figuras.h
	gcc -o gentree_wfigs_test.out tests/gentree_wfigs_test.c lib/gentree.c lib/figuras.c -lm