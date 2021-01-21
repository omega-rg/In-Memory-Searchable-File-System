/*
Creates node for a directory in the tree. Used when mkdir command is executed.
*/

#include "tree.h"


imsfs_tree_node *add_dir_node(const char *parent_path, const char *name){

    imsfs_tree_node *parent_node = get_node(parent_path);
    if(!parent_node){
        error_msg("NULL returned by get_node()", "Invalid Path");
        return NULL;
    }
    // We will add the directory on this node

    int pathlen = strlen(parent_path) + strlen(name) + 2;
    char *fullpath = (char *)malloc(sizeof(char) * pathlen + 1);
    if(!fullpath){
        free(fullpath);
        fullpath = NULL;
        perror("Malloc():");
    }
    strcat(fullpath, parent_path);
    strcat(fullpath, "/");
    strcat(fullpath, name);
    if(get_node(fullpath)){
        error_msg("get_node()", "Path already exists.");
        return NULL;
    }

    imsfs_tree_node *new_node = (imsfs_tree_node *)malloc(sizeof(imsfs_tree_node) + 1);
    
    int cur_mex = parent_node -> mex;
    if(cur_mex == parent_node -> end_of_children){
        parent_node -> end_of_children++;
        parent_node -> children = realloc(parent_node -> children, sizeof(imsfs_tree_node *) * parent_node -> end_of_children);
    }
    parent_node -> children[cur_mex] = new_node;
    assign_mex(parent_node);

    new_node -> isfile = 0;
    new_node -> name = (char *)malloc(strlen(name) + 1);
    strcpy(new_node -> name, name);
    new_node -> path = (char *)malloc(pathlen);
    strcpy(new_node -> path, fullpath);
    new_node -> parent = parent_node;
    new_node -> children = NULL;
    new_node -> end_of_children = 0;
    new_node -> mex = 0;
    new_node -> data = NULL;
    new_node -> data_len = 0;
    new_node -> permissions = DIR_PERM;
    new_node -> access_time = time(NULL);
    new_node -> modification_time = time(NULL);
    new_node -> change_time = time(NULL);

    free(fullpath);
    fullpath = NULL;

    return new_node;
}

