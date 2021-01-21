/*
Removes a file
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

/** Remove a file **/

int imsfs_unlink (const char *path){
    
    printf("******************\n");
    printf("REMOVE FILE\n");

    //Use query
    int use_query = is_use_query(path);
    printf("Is path a use query: %d\n",use_query);
    if (use_query) return imsfs_unlink_use(path);
    
    int ret = remove_file_node(path);

    switch (ret){
        case -2:
            return -EISDIR;
            break;
        case -1:
            return -ENOENT;
            break;
        case 1:
            return 0;
            break;
    }
    printf("******************\n");
    return 0;
}