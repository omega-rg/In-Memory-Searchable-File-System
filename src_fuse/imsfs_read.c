/*
Reads data from a file and writes it to the buffer 
provided by FUSE
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

//data_len -> length of string (excluding NULL character)

int imsfs_read (const char *path, char *buf, size_t size, off_t offset, struct fuse_file_info *fi){

    printf("******************\n");
    printf("READ FILE\n");

    //Use query
    int use_query = is_use_query(path);
    printf("Is path a use query: %d\n",use_query);
    if (use_query) return imsfs_read_use(path, buf, size, offset, fi);

    imsfs_tree_node* cur_node = get_node(path);
    
    if (!cur_node) return -ENOENT; // path invalid
    else if (cur_node->isfile == 0) return -EISDIR; // is a directory

    unsigned long int data_len = cur_node->data_len;

    long int num_chars = (long int)size;

    if (offset >= data_len) return 0;
    else if (offset + (int)size > data_len){
        num_chars = data_len - offset;
    }

    strncpy(buf, cur_node->data, num_chars);
    buf[num_chars] = '\0';

    //Update times
    cur_node -> access_time = time(NULL);

    printf("******************\n");
    return num_chars;
    
    
}
