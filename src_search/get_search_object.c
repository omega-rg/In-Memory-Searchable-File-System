/*
From the search command typed, create the search object with the prefix pointers 
and the substring pointers pointing to the appropriate keywords
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
#include "search_use_query.h"


imsfs_searchobj* get_search_object(const char *path){

    printf("get_search_obj called at path: %s\n",path);

    if (!path) return NULL;
    else if (!is_search_query(path)) return NULL;

    imsfs_searchobj *searcher = create_search_object();
    printf("created new search object at location: %p\n",searcher);

    if (strcmp(path,"/FIND") == 0) return searcher;

    int search_prefix_len = strlen(SEARCH_KEYWORD);
    int cur = search_prefix_len + 2;

    int path_len = strlen(path);

    int tag = 1; //indicates if next portion in path must be tag or metadata
    char* data = NULL;
    char** cur_tag_ptr = NULL; //holds address of the current tag pointer in the object

    int counter = 0;
    
    while(cur < path_len){

        printf("Iteration no: %d\n",counter); counter+=1;
        printf("are we looking for tag: %d\n",tag);
        printf("current position in path: %d\n",cur);
        
        int next = cur;
        while(next<path_len && path[next] != '/') next++;

        //todo: if end reached, handle

        int data_len = next-cur;
        data = malloc(sizeof(char)*(data_len+1));
        
        for (int i=cur; i<next; i++){
            data[i-cur] = path[i];
        }
        data[data_len] = '\0';
        
        printf("extracted data from path: %s\n",data);


        if (tag){
            if (check_tag(data) == 0){
                free_search_object(searcher);
                free(data);
                data = NULL;
                return NULL;
            }
            else{
                cur_tag_ptr = get_tag_ptr(searcher, data); //search and get pointer to field in object
                // printf("tag_pointer is located at: %p\n",cur_tag_ptr);
                // printf("location of searcher prefix: %p\n",(void*)(&searcher->prefix));
            }            
        }
        else{

            char* metadata = NULL;
            metadata = malloc(sizeof(char)*(strlen(data)+1));
            strcpy(metadata, data);
            *cur_tag_ptr = metadata;
            metadata = NULL;
            // printf("assigning metadata to tag: %s\n",*cur_tag_ptr);
        }

        // next iteration
        // printf("Next iteration...\n");
        tag = tag ^ 1; //flip tag
        cur = next + 1;
        free (data);
        data = NULL;

    }

    printf("Search object has the following parameters:\n");
    printf("prefix: %s\n", searcher->prefix);
    printf("substr: %s\n", searcher -> substr);

    printf ("returning from get_search_object\n");
    return searcher;
}
