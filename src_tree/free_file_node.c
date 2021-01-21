/*
Unlikes and frees up memory for a file node
*/


#include "tree.h"
#include "search_use_query.h"

int free_file_node(imsfs_tree_node *file_node){
    if(!file_node){
        return -1;
    }

    if(file_node -> isfile == false){
        return -2;
    }

    // If parent originally had greater mex, it now has new mex equal to this position
    imsfs_tree_node *parent_node = file_node -> parent;
    int pos = find_pos(file_node, parent_node);
    parent_node -> children[pos] = NULL;
    // Very important, no deallocation takes place here
    // The pointer to the imsfs_tree_node structure still occupies its 8 bytes
    // However it points to NULL
    // This is so that we have no problems in freeing up memory later
    // free() on NULL is a safe "no-op"
    
    if((parent_node -> mex) > pos){
        parent_node -> mex = pos;
    }

    //Remove file from search buffer if it exists there
    remove_node_from_search_buffer(file_node);

    // Freeing up starts here
    // Only free up malloc'd or realloc'd variables
    // Free up in reverse order of assignment
    free(file_node -> data);
    file_node -> data = NULL;
    free(file_node -> path);
    file_node -> path = NULL;
    free(file_node -> name);
    file_node -> name = NULL;
    free(file_node);
    file_node = NULL;

    return 1; // success
}

