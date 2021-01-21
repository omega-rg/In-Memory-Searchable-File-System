/*
Add the given node into the search buffer that has been defined in the search directory
*/


#include <fuse.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>
#include "tree.h"
#include "search_use_query.h"

void add_to_search_buffer(imsfs_tree_node* node){

    if (!node) return;
    
    if (search_buffer == NULL){        
        search_buffer = (imsfs_tree_node**)malloc(sizeof(imsfs_tree_node*));
    }
    else{
        search_buffer = (imsfs_tree_node**)realloc(search_buffer, sizeof(imsfs_tree_node*)*(num_search_buffer_entries+1));
    }

    num_search_buffer_entries ++;
    search_buffer[num_search_buffer_entries-1] = node;

}