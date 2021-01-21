/*
This file contains helper functions for 
tree related functions
*/

#ifndef IMSFS_TREE_H
#define IMSFS_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include <stdarg.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdbool.h>
#include <fuse.h>

#define DIR_PERM (0777) //Default permissions for directories
#define FILE_PERM (0777) //Default permissions for files

#define MAX_NAME_SIZE 256 //Maximum length of name of a file/directory
#define MAX_PATH_DEPTH 20 //Maximum depth in the tree of a file/directory node

//Node structure in the tree
typedef struct imsfs_tree_node {

    bool isfile;                        //the node is a file or directory
    char *name;                         //name of node, file/directory
    char *path;                         //full path of node, stored as an array of directories
    
    struct imsfs_tree_node *parent;     //link to parent
    struct imsfs_tree_node **children;  //links to children
    int end_of_children;                //number of children
    int mex;                            // lowest unfilled location

    char *data;						    //data for read and write
    unsigned long int data_len;

    unsigned int permissions;		    // Permissions

    long access_time;                   // Time of last access
    long modification_time;             // Time of last modification
    long change_time;                   // Time of last status change


} imsfs_tree_node;

// Root of the tree
imsfs_tree_node *root;

// Initialise imsfs
void initialise_imsfs();

//Prints error messages
void error_msg(const char *msg, const char *reason); 

void print_node_data(imsfs_tree_node *node);
imsfs_tree_node *get_node(const char *path);
imsfs_tree_node *add_file_node(const char *parent_path, const char *name);
imsfs_tree_node *add_dir_node(const char *parent_path, const char *name);
char *name_from_path(const char *path);
char *parent_from_path(const char *path);
imsfs_tree_node *parent_node_from_path(const char *path);
imsfs_tree_node* get_file_node(const char *path);
imsfs_tree_node* get_dir_node(const char *path);
int remove_file_node(const char *path);
int remove_empty_dir(const char *path);
int free_file_node(imsfs_tree_node *file_node);
int free_dir_node_recursive(imsfs_tree_node *dir_node);
int find_pos(imsfs_tree_node *child, imsfs_tree_node *parent);
void assign_mex(imsfs_tree_node *parent_node);
bool check_leaf(imsfs_tree_node *cur);
int change_node_location(const char *oldpath, const char *newpath);
int rename_node(const char *old_path, const char *new_path);
int recursive_path_update(char *parent_path, imsfs_tree_node *cur_node);

#endif
