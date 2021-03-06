/*
Reads the file requested using 
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
#include "imsfs_operations.h"
#include "imsfs_operations_search_use.h"

//data_len -> length of string (excluding NULL character)

int imsfs_read_use (const char *path, char *buf, size_t size, off_t offset, struct fuse_file_info *fi){

    printf("READ USE FILE\n");

    char* file_name = get_file_name_use(path);

    if (!file_name) return -ENOENT;

    imsfs_tree_node* cur_node = get_node_from_search_buffer(file_name);
    
    if (!cur_node){
        free(file_name);    
        return -ENOENT;
    }

    cur_node -> access_time = time(NULL);

    unsigned long int data_len = cur_node->data_len;

    long int num_chars = (long int)size;

    if (offset >= data_len) return 0;
    else if (offset + (int)size > data_len){
        num_chars = data_len - offset;
    }

    strncpy(buf, cur_node->data, num_chars);
    buf[num_chars] = '\0';

    free(file_name);
    return num_chars;
    
}