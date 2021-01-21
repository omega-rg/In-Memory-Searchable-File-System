/*
Once a directory’s location is changed, we have to change the locations of all the nodes in the subtree 
*/


#include "tree.h"

int recursive_path_update(char *parent_path, imsfs_tree_node *cur_node){
    free(cur_node -> path);
    cur_node -> path = NULL;

    int parent_len = strlen(parent_path);
    int name_len = strlen(cur_node -> name);

    cur_node -> path = malloc(sizeof(char) * (parent_len + 1 + name_len + 1)); // For '/' and '\0'
    strcpy(cur_node -> path, parent_path);
    strcpy(cur_node -> path, "/");
    strcpy(cur_node -> path, cur_node -> name);
    cur_node -> path[parent_len + 1 + name_len] = '\0';
    // Path of cur_node fixed
    // Now on to fix path of all children

    int ret = 1;
    if(cur_node -> isfile);
    else{
       for(int i = 0; i < (cur_node -> end_of_children); i++){
           imsfs_tree_node *child = cur_node -> children[i];
           if(child){
               ret &= recursive_path_update(cur_node -> path, child);
           }
       }
    }
    return ret;
}

