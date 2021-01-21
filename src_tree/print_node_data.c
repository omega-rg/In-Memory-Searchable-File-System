/*
Prints all data stored in the node
*/

#include "tree.h"

void print_node_data(imsfs_tree_node *node){

    printf("Name of file: %s\n", node -> name);

    printf("Path relative to mountpoint: %s\n", node -> path);

    if(node -> isfile){
        printf("FILE\n");
    }
    else{
        printf("DIRECTORY\n");
    }

    printf("Parent: %p\n", node -> parent);

    printf("Number of children: %d\n", node -> end_of_children);

    printf("MEX: %d\n", node -> mex);

    for(int i = 0; i < node -> end_of_children; i++){
        printf("Child number %d: %p\n", i + 1, node -> children[i]);
    }
    printf("\n");

    printf("Size of file in bytes: %ld\n", node -> data_len);

    printf("Permissions of the node: %u\n",node->permissions);

    printf("\n");
}
