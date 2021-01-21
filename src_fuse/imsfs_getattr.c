/*
Fills a stat structure with the file/directory attributes
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

int imsfs_getattr (const char *path, struct stat *s){
    printf("******************\n");
    printf("GETATTR\n");
    printf("getattr called at path: %s\n",path);


    //Search query
    int search_query = is_search_query(path);
    printf("Is path a search query: %d\n",search_query);
    if (search_query) return imsfs_getattr_search(path, s);

    //Use query
    int use_query = is_use_query(path);
    printf("Is path a use query: %d\n",use_query);
    if (use_query) return imsfs_getattr_use(path, s);

    imsfs_tree_node* cur_node = get_node(path);
    
    printf("%p\n",cur_node);
    printf("Get node no problem\n");
    
    if (!cur_node) return -ENOENT;
    
    if (cur_node->isfile){
        s->st_nlink=1;
        s->st_size=(cur_node->data_len);
        s->st_mode= S_IFREG | cur_node->permissions;
    }
    else{
        int child_dir=0;
        for (int i=0;i<(cur_node->end_of_children);i++){
            if (cur_node->children[i]!=NULL && cur_node->children[i]->isfile == 0) child_dir++;
        }
        s->st_nlink=child_dir+2; //"." and ".."
        s->st_size = 0;
        s->st_mode= S_IFDIR | cur_node->permissions;
    }

    s->st_atim.tv_sec=cur_node->access_time;
    s->st_mtim.tv_sec=cur_node->modification_time;
    s->st_ctim.tv_sec=cur_node->change_time;

    //Update time
    cur_node -> access_time = time(NULL);

    // print_node_data(cur_node);

    printf("Returning from getattr\n");
    printf("******************\n");
    return 0;
}
