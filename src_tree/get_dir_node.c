/*
Takes path as argument and return the pointer to the node only if it is a directory node
*/

#include "tree.h"

imsfs_tree_node *get_dir_node(const char *path){
    imsfs_tree_node *cur = get_node(path);
    if(!cur)
        return NULL;

    if(cur -> isfile == 1)
        return NULL;

    return cur;
}

