/*
If the node is a directory node and it has no children, the node gets removed by this function.
*/

#include "tree.h"

int remove_empty_dir(const char *path){
    printf("Empty directory path %s\n", path);
    imsfs_tree_node *cur = get_node(path);

    if(!cur){
        return -1;
    }

    if(cur -> isfile == true){
        return -2;
    }

    if(!check_leaf(cur)){ // If the directory is not empty (no leaves)
        return 0;
    }

    return free_dir_node_recursive(cur);
}

