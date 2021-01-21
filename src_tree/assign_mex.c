/*
find the smallest whole number position at which a pointer to a child node has not been defined, 
and assigns a pointer to point to the child directory in question
*/

#include "tree.h"

void assign_mex(imsfs_tree_node *parent_node){
    int i = 0;
    while(i < (parent_node -> end_of_children)){
        if((parent_node -> children[i]) == NULL){
            break;
        }
        i++;
    }
    parent_node -> mex = i;
}

