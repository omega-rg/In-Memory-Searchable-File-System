/*
Searches for file which match the metadata 
specified in the search query
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
#include "imsfs_operations.h"
#include "imsfs_operations_search_use.h"



int imsfs_readdir_search(const char *path, void *buffer, fuse_fill_dir_t filler, off_t offset, struct fuse_file_info *fi){
    
    printf("imsfs_readdir_search called at path: %s\n",path);
    
    imsfs_searchobj* searcher = get_search_object(path);
    printf("search object created at: %p\n",searcher);

    if (!searcher) return -ENOTDIR; //invalid search path

    tree_search_fill(filler, buffer, searcher);

    return 0;
}
