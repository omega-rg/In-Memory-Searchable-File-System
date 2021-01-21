/*
Initialises the data structure. Defines a root node as well 
*/

#include "tree.h"

void initialise_imsfs(){
    printf("Initialise imsfs\n");

    root = (imsfs_tree_node *)malloc(sizeof(imsfs_tree_node)); // Malloc the root. Now we can enter data.
    printf("Root node at location %p\n", root);

    root -> isfile = 0;

    root -> name = (char *) malloc(sizeof(char) + 1);
    strcpy(root -> name, "/"); // Root is also named '/'

    root -> path = (char *) malloc(sizeof(char) + 1);
    strcpy(root -> path, "/");

    root -> parent = NULL;
    root -> children = NULL;
    root -> end_of_children = 0;
    root -> mex = 0;

    root -> data = NULL;
    root -> data_len = 0;
    root -> permissions = 0777;
    
    root->access_time = time(NULL);
    root->modification_time = time(NULL);
    root->change_time = time(NULL);
}

