/*
Creates node for a file in the tree. Used when touch command is executed.
*/


#include "tree.h"

imsfs_tree_node *add_file_node(const char *parent_path, const char *name){
    printf("call to function: ADD_FILE_NODE, parent_path: %s, child_name: %s\n",parent_path, name);

    imsfs_tree_node *parent_node = get_node(parent_path);
    if(!parent_node){
        error_msg("NULL returned by get_node()", "Invalid Path");
        return NULL;
    }
    // We will add the file/directory on this node

    int pathlen = strlen(parent_path) + strlen(name) + 2; //no of bytes allocated to full path
    
    
    // char *fullpath = (char *)malloc(sizeof(char) * pathlen + 1);
    char *fullpath = (char *)malloc(sizeof(char) * pathlen);
    fullpath[0]='\0';

    if(!fullpath){
        perror("Malloc():");
    }
    strcat(fullpath, parent_path);

    if (strcmp(parent_path,"/") != 0){
        strcat(fullpath, "/");
    }

    strcat(fullpath, name);
    if(get_node(fullpath)){
        free(fullpath);
        fullpath = NULL;
        error_msg("get_node()", "Path already exists.");
        return NULL;
    }

    imsfs_tree_node *new_node = (imsfs_tree_node *)malloc(sizeof(imsfs_tree_node));
    
    int cur_mex = parent_node -> mex;
    if(cur_mex == (parent_node -> end_of_children)){
        parent_node -> end_of_children++;
        parent_node -> children = realloc(parent_node -> children, sizeof(imsfs_tree_node *) * parent_node -> end_of_children);
    }
    parent_node -> children[cur_mex] = new_node;
    assign_mex(parent_node);

    new_node -> isfile = 1;
    new_node -> name = (char *)malloc(strlen(name) + 1);
    strcpy(new_node -> name, name);
    new_node -> path = (char *)malloc(pathlen);
    strcpy(new_node -> path, fullpath);
    new_node -> parent = parent_node;
    new_node -> children = NULL;
    new_node -> end_of_children = 0;
    new_node -> mex = -1;
    new_node -> data = NULL;
    new_node -> data_len = 0;
    new_node -> permissions = FILE_PERM;
    new_node -> access_time = time(NULL);
    new_node -> modification_time = time(NULL);
    new_node -> change_time = time(NULL);

    free(fullpath);
    fullpath = NULL;

    printf("New file node pointer: %p\n",new_node);
    printf("Returning from ADD_FILE_NODE\n");

    return new_node;
}

