/*
Reads the children of a directory
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

int imsfs_readdir(const char *path, void *buffer, fuse_fill_dir_t filler, off_t offset, struct fuse_file_info *fi ){

    printf("******************\n");
    printf("READ DIRECTORY\n");
    printf("imsfs_readdir called at path: %s\n",path);

    if (is_search_query(path)) return imsfs_readdir_search(path, buffer, filler, offset, fi);

    imsfs_tree_node* dir_node = get_node(path);
    
    if (!dir_node) return -ENOENT; // path invalid
    else if (dir_node->isfile) return -ENOTDIR;

    filler(buffer,".",NULL,0);
    filler(buffer,"..",NULL,0);

    for (int i=0; i<(dir_node->end_of_children); i++){
        if (dir_node->children[i]!=NULL){
            filler(buffer,dir_node->children[i]->name,NULL,0);
        }
    }

    //Update times
    dir_node -> access_time = time(NULL);
    printf("******************\n");
    
    return 0;
}   