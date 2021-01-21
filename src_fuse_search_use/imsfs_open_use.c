/*
Opens the file requested using 
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
#include "tree.h"
#include "imsfs_operations.h"
#include "imsfs_operations_search_use.h"


int imsfs_open_use (const char *path, struct fuse_file_info *fi){
    
    printf("OPEN USE FILE\n");
    printf("open use file called at path: %s\n",path);

    char* file_name = get_file_name_use(path);

    if (!file_name) return -ENOENT;

    imsfs_tree_node* cur_node = get_node_from_search_buffer(file_name);
    
    if (!cur_node){
        free(file_name);    
        return -ENOENT;
    }

    cur_node->access_time = time(NULL);

    // printf("Returning from imsfs_open with return value: %d\n",ret_val);
    
    free(file_name);
    return 0;
}