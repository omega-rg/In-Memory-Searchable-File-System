/*
This file contains helper functions for 
search/use queries
*/

#ifndef SEARCH_USE_QUERY_H
#define SEARCH_USE_QUERY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdarg.h>

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

#include <fuse.h>
#include "tree.h"

#define MAX_TAG_LENGTH 20 //Maximum length of search tag
#define NUM_SUPPORTED_TAGS 2 //Number of tags supported currently

//Struct containing metadata from search query
//used for obtaining nodes which match the search query 
typedef struct imsfs_searchobj{
    char* prefix;
    char *substr;
} imsfs_searchobj;

char* SEARCH_KEYWORD; //Search keyword, hardcoded to FIND
char* USE_KEYWORD; //Use keyword, hardcoded to FIND

char** supported_tags; //Array of names of supported search tags

 //Array of nodes matching the most recent search query
imsfs_tree_node** search_buffer;

//index marking the end of buffer
int num_search_buffer_entries; 


/* Function Definitions */

//Helper functions for Search Queries
int check_tag(char* tag);
imsfs_searchobj* create_search_object();
void free_search_object(imsfs_searchobj* searcher);
imsfs_searchobj* get_search_object(const char *path);
char** get_tag_ptr(imsfs_searchobj* searcher, const char* tag);
void initialise_search();
int is_search_query(const char *path);
int match_node(imsfs_tree_node *node, imsfs_searchobj *searcher, int m, int lps[]);
void tree_search_fill(fuse_fill_dir_t filler, void *buffer, imsfs_searchobj* searcher);

//Helper functions for Use Queries
void add_to_search_buffer(imsfs_tree_node* node);
void free_search_buffer();
char* get_file_name_use(const char* path);
imsfs_tree_node* get_node_from_search_buffer(char* file);
int is_use_query(const char *path);
void remove_node_from_search_buffer(imsfs_tree_node* file_node);

#endif
