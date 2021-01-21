/*
Unlinks and frees up memory for a leaf directory node.
*/

#include "tree.h"

// Only the base case works, that is, the case in which the directory is empty
int free_dir_node_recursive(imsfs_tree_node *dir_node){
    if(!dir_node){
        return -1;
    }

    if((dir_node -> isfile) == true){
        return -2;
    }

    // If parent originally had greater mex, it now has new mex equal to this position
    imsfs_tree_node *parent_node = dir_node -> parent;
    int pos = find_pos(dir_node, parent_node);
    parent_node -> children[pos] = NULL;
    // Very important, no deallocation takes place here
    // The pointer to the imsfs_tree_node structure still occupies its 8 bytes
    // However it points to NULL
    // This is so that we have no problems in freeing up memory later
    // free() on NULL is a safe "no-op"
    
    if((parent_node -> mex) > pos){
        parent_node -> mex = pos;
    }

    // Freeing up starts here
    // Only free up malloc'd or realloc'd variables
    // Free up in reverse order of assignment
    free(dir_node -> data);
    dir_node -> data = NULL;
    free(dir_node -> children); //addition
    dir_node -> children = NULL;
    free(dir_node -> path);
    dir_node -> path = NULL;
    free(dir_node -> name);
    dir_node -> name = NULL;
    free(dir_node);
    dir_node = NULL;

    return 1; // success
}

