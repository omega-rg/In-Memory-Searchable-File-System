/*
Flush out all node-entries from the search buffer, deallocate/free up it’s memory
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

void free_search_buffer(){
    
    for (int i=0; i<num_search_buffer_entries; i++){
        search_buffer[i] = NULL; //only nullify as they point to tree nodes, don't free
    }
    
    free(search_buffer);
    search_buffer = NULL;
    
    num_search_buffer_entries = 0;
}
