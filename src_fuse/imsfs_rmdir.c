/*
Removes an emoty directory
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

int imsfs_rmdir (const char *path){

    printf("******************\n");
    printf("REMOVE DIRECTORY\n");
    printf("Path to be removed: %s\n", path);

    int ret = remove_empty_dir(path);
    switch(ret){
        case -2:
            return -ENOTDIR;
            break;
        case -1:
            return -ENOENT;
            break;
        case 0:
            return -ENOTEMPTY;
            break;
        case 1:
            return 0;
            break;
    }
    printf("******************\n");
    return 0;
}
