/*
Removes the file requested using 
the use query
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
#include "imsfs_operations.h"
#include "imsfs_operations_search_use.h"

int imsfs_unlink_use(const char *path){

    printf("imsfs_unlink_use called at path: %s\n",path);
    
    char* file_name = get_file_name_use(path);
    printf("extracted file name: %s\n", file_name);

    if (!file_name) return -ENOENT;
    
    imsfs_tree_node* cur_node = get_node_from_search_buffer(file_name);
    
    if (!cur_node){
        free(file_name);    
        return -ENOENT;
    }

    free_file_node(cur_node);
    
    free(file_name);
    return 0;

}