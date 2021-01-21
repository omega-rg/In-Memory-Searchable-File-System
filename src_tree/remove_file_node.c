/*
If the node is a file node, the node gets removed by this function.
*/

#include "tree.h"

int remove_file_node(const char *path){
    imsfs_tree_node *cur = get_node(path);

    if(!cur){
        return -1;
    }

    if(cur -> isfile == false){
        return -2;
    }

    return free_file_node(cur);
}

