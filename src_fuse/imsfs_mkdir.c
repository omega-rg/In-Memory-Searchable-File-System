/*
Creates a new directory in the file system
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

int imsfs_mkdir (const char *path, mode_t mode){

    printf("******************\n");
    printf("CREATE DIRECTORY\n");
    printf("Create directory called with path: %s\n",path);

    imsfs_tree_node* existing_node = get_node(path);

    //printf("existing node pointer check: %p\n",existing_node);

    if (existing_node != NULL) return -EEXIST;

    //printf("Node doesn't exist, creating new\n");

    imsfs_tree_node* added_directory_node = add_dir_node(parent_from_path(path), name_from_path(path));

    //printf("new node pointer check: %p\n",added_directory_node);

    if (!added_directory_node) return -ENOENT;

    printf("Returning from mkdir\n");
    printf("******************\n");
 
    return 0;
}