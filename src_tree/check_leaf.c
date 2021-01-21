/*
Checks if the specified node is a leaf node or not
*/

#include "tree.h"

bool check_leaf(imsfs_tree_node *cur){
    if(!cur){
        return false;
    }

    if(cur -> isfile){
        return true;
    }

    for(int i = 0; i < (cur -> end_of_children); i++){
        imsfs_tree_node *child = cur -> children[i];
        if(child != NULL){
            return false;
        }
    }
    return true;
}

