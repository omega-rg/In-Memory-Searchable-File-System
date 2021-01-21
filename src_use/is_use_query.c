/*
Returns true if the command typed is for making use of the search buffer, 
that is, if the command has the following format- <command> ./USE/…
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

int is_use_query(const char *path){

    printf("is_use_query called at path: %s\n",path);

    int len_search = strlen(USE_KEYWORD);

    if (path[0]!='/') return 0;

    int ret_val = 1; 

    for (int i=0; i<len_search; i++){
        if (path[i+1] != USE_KEYWORD[i]){
            ret_val = 0;
            break;
        }
    }

    printf("returning from is_use_query, return value: %d\n",ret_val);
    return ret_val;
}

