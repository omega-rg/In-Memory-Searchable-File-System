/*
Exposes the directories in the search-query
command as empty directories
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

int imsfs_getattr_search(const char *path, struct stat *s){

    printf("imsfs_getattr_search called at path: %s\n",path);
    s->st_nlink = 2; //"." and ".."
    s->st_size=0;
    s->st_mode= S_IFDIR | DIR_PERM;

    return 0;
}