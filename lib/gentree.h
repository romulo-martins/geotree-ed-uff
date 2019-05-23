#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct gentree GenTree;
GenTree* new_gt(void);
GenTree* insert_gt(GenTree* t, int cod_geo, int cod_parent, char* type, void* geofig);
GenTree* search_gt(GenTree* t, int cod);
GenTree* remove_gt(GenTree* t, int cod);
void print_gt(GenTree *t);
void free_gt(GenTree* t);