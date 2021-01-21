/*
Remove the given node from the search buffer
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

void remove_node_from_search_buffer(imsfs_tree_node* file_node){

    if (!search_buffer || !file_node) return;

    for (int i=0; i<num_search_buffer_entries; i++){
        
        if (search_buffer[i] == file_node){
            
            search_buffer[i] = NULL;

        }
    }

}