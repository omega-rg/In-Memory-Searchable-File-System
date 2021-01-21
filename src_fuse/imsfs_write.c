/*
Writes data to a file
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

int imsfs_write (const char *path, const char *buf, size_t size, off_t offset, struct fuse_file_info *fi){

    printf("***************************************\n");
    printf("WRITE TO FILE\n");

    printf("path passed to imsfs_write: %s\n",path);

    //Use query
    int use_query = is_use_query(path);
    printf("Is path a use query: %d\n",use_query);
    if (use_query) return imsfs_write_use(path, buf, size, offset, fi);

    imsfs_tree_node* cur_node = get_node(path);

    if (!cur_node) return -ENOENT;
    else if (cur_node->isfile == 0) return -EISDIR; //is a directory

    printf("data length of file before write: %lu\n",cur_node->data_len);
    
    unsigned long int data_len = cur_node->data_len;

    long int end = offset + (long int)size;
    
    if (end>data_len){
        cur_node->data = realloc (cur_node->data, sizeof(char)*end + 1);
        if (!cur_node->data) return -ENOMEM;
        else{
            cur_node->data_len=end;
        }
    }

    strncpy(cur_node->data + offset, buf, size);
    cur_node->data[end]='\0';

    //Update times
    cur_node -> access_time = time(NULL);
    cur_node -> modification_time = time(NULL);
    cur_node -> change_time = time(NULL);

    printf("data length of file after write: %lu\n",cur_node->data_len);
    int ret_val = size;
    printf("returning from imsfs_write with return value: %d\n",ret_val);

    printf("***************************************\n");
    return size;
}