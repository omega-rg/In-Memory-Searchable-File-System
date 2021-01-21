/*
Finds the position of child with respect to the parent node
*/

#include "tree.h"

int find_pos(imsfs_tree_node *child, imsfs_tree_node *parent_node){
    if(!child){
        return -1;
    }

    char *child_name = child -> name;

    int i = 0;
    while(i < (parent_node -> end_of_children)){
        imsfs_tree_node *cur_child = parent_node -> children[i];
        if(!cur_child){
            i++;
            continue;
        }
        char *curname = cur_child -> name;
        if(strcmp(curname, child_name) == 0){
            // i++;
            return i;
        }
        i++;
    }
    return -1;
}

