# Makefile para realizar a compilação
gentree_test: tests/gentree_test.c lib/gentree.c lib/gentree.h
	gcc -o gentree_test.out tests/gentree_test.c lib/gentree.c lib/figuras.c -lm

gentree_w_figs_test: tests/gentree_w_figs_test.c lib/gentree.c lib/gentree.h lib/figuras.h
	gcc -o gentree_w_figs_test.out tests/gentree_w_figs_test.c lib/gentree.c lib/figuras.c -lm