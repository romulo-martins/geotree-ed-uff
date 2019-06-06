# Makefile para realizar a compilação
gentree_test: tests/gentree_test.c lib/gentree.h
	gcc -o gentree_test.out tests/gentree_test.c lib/gentree.c lib/figuras.c lib/areas.c -lm

gentree_figs_test: tests/gentree_figs_test.c lib/gentree.h lib/figuras.h lib/areas.h
	gcc -o gentree_figs_test.out tests/gentree_figs_test.c lib/gentree.c lib/figuras.c lib/areas.c -lm

gentree_load_test: tests/gentree_load_test.c lib/gentree.h lib/figuras.h lib/areas.h
	gcc -o gentree_load_test.out tests/gentree_load_test.c lib/gentree.c lib/figuras.c lib/areas.c -lm

main: main.c lib/gentree.h lib/figuras.h lib/areas.h
	gcc -o main.out main.c lib/gentree.c lib/figuras.c lib/areas.c -lm

gentree_wfigs_test: tests/gentree_wfigs_test.c lib/gentree.c lib/gentree.h lib/figuras.h
	gcc -o gentree_wfigs_test.out tests/gentree_wfigs_test.c lib/gentree.c lib/figuras.c -lm

avl_test: tests/avl_test.c lib/avl.c lib/avl.h
	gcc -o avl_test.out tests/avl_test.c lib/avl.c lib/figuras.c -lm