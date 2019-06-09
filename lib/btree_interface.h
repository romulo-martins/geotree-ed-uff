#ifndef BTREE_INTERFACE_H
#define BTREE_INTERFACE_H

#include "gentree.h"
#include "btree.h"

BTree* btree_cmds(BTree* bt);
int is_bt_cmd(char* cmd);

#endif