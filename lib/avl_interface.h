#ifndef AVL_INTERFACE_H
#define AVL_INTERFACE_H

#include "gentree.h"
#include "avl.h"

AVL* avl_cmds(GenTree* gt, AVL* at);
int is_avl_cmd(char* cmd);

#endif