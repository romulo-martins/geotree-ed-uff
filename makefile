# Makefile para realizar a compilação
gentree_test: tests/gentree_test.c lib/gentree.h
	gcc -o gentree_test.out tests/gentree_test.c lib/gentree.c lib/figuras.c lib/areas.c -lm

gentree_figs_test: tests/gentree_figs_test.c lib/gentree.h lib/figuras.h lib/areas.h
	gcc -o gentree_figs_test.out tests/gentree_figs_test.c lib/gentree.c lib/figuras.c lib/areas.c -lm

gentree_load_test: tests/gentree_load_test.c lib/gentree.h lib/figuras.h lib/areas.h
	gcc -o gentree_load_test.out tests/gentree_load_test.c lib/gentree.c lib/figuras.c lib/areas.c -lm

gentree_wfigs_test: tests/gentree_wfigs_test.c lib/gentree.c lib/gentree.h lib/figuras.h
	gcc -o gentree_wfigs_test.out tests/gentree_wfigs_test.c lib/gentree.c lib/figuras.c -lm

avl_test: tests/avl_test.c lib/avl.c lib/avl.h lib/figuras.h lib/areas.h
	gcc -o avl_test.out tests/avl_test.c lib/avl.c lib/figuras.c lib/areas.c -lm

btree_test: tests/btree_test.c lib/btree.h lib/gentree.h lib/figuras.h lib/areas.h
	gcc -o btree_test.out tests/btree_test.c lib/btree.c lib/gentree.c lib/figuras.c lib/areas.c -lm

main: main.c lib/gentree.h lib/gentree_interface.h lib/figuras.h lib/areas.h lib/btree_interface.h lib/btree.h lib/avl_interface.h lib/avl.h
	gcc -o main.out main.c lib/gentree.c lib/gentree_interface.c lib/figuras.c lib/areas.c lib/btree_interface.c lib/btree.c lib/avl_interface.c lib/avl.c -lm
