/*
Changes timestamps of a file
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

int imsfs_utimens (const char *path, const struct timespec tv[2]){

    imsfs_tree_node* cur_node = get_node(path);

    if (!cur_node){
        return -ENOENT;
    }

    cur_node -> access_time = tv[0].tv_sec;
    cur_node -> modification_time = tv[1].tv_sec;
    cur_node -> change_time = tv[1].tv_sec;

    return 0;
}