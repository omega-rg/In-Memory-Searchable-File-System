/*
Search through the buffer to get the node referred to by the filename
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

imsfs_tree_node* get_node_from_search_buffer(char* file){
    
    printf("get_node_from_search_buffer called for file name: %s\n",file);

    if (!file || !search_buffer) return NULL;
    
    printf("Total number of entries in buffer: %d\n",num_search_buffer_entries);
    
    for (int i=0; i<num_search_buffer_entries; i++){

        // printf("Entry %d: %s\n",i+1,search_buffer[i]->name);
        // printf("Entry %d pointer: %p\n",i+1,search_buffer[i]);
        
        if (search_buffer[i] != NULL && search_buffer[i]->isfile == 1 && strcmp(search_buffer[i]->name, file) == 0){
            
            printf("Match found with entry %d\n", i + 1);
            return search_buffer[i];

        }

    }

    return NULL;
}
