/*
Returns parent node from the given path
*/

#include "tree.h"

imsfs_tree_node *parent_node_from_path(const char *path){
    char *parent_path = parent_from_path(path);
    if(!parent_path){
        error_msg("parent_from_path()", "Invalid Path");
        return NULL;
    }
    return get_node(parent_path);
}

