/*
Opens a file
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


int imsfs_open (const char *path, struct fuse_file_info *fi){

    printf("******************\n");
    printf("OPEN FILE\n");
    printf("open file called at path: %s\n",path);

    //Use query
    int use_query = is_use_query(path);
    printf("Is path a use query: %d\n",use_query);
    if (use_query) return imsfs_open_use(path, fi);

    imsfs_tree_node* cur_node = get_node(path);

    printf("pointer to the node: %p\n", cur_node);

    int ret_val; //return value
    if (!cur_node) ret_val = -ENOENT;
    else if (cur_node->isfile == 0){
        ret_val = -EISDIR;
    }
    else{
        ret_val = 0;
        cur_node -> access_time = time(NULL);
    }

    printf("Returning from imsfs_open with return value: %d\n",ret_val);
    printf("******************\n");
    return ret_val;
}