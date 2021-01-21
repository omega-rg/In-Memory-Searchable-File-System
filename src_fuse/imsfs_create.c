/*
Creates a new file in the file system
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

int imsfs_create (const char * path, mode_t mode, struct fuse_file_info *fi){

    printf("******************\n");
    printf("CREATE FILE\n");
    printf("create file called at path: %s\n",path);

    imsfs_tree_node* existing_node = get_node(path); //checking if entry already exists

    if (existing_node!=NULL) return -EEXIST; 

    imsfs_tree_node* added_file_node=add_file_node(parent_from_path(path),name_from_path(path));

    if (!added_file_node) return -ENOENT; //parent path invalid
    
    printf("returning from create file\n");
    printf("******************\n");
    
    return 0;
}