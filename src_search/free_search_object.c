/*
Clears the search object and deallocates its memory.
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

void free_search_object(imsfs_searchobj* searcher){

    //take care of order (same as order of arguments)
    free(searcher->prefix);
    searcher->prefix = NULL;

    free(searcher);
    
}