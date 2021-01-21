/*
Extract the filename from a “USE” command
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

char* get_file_name_use(const char* path){

    if (strcmp(path, "/USE") == 0){
        return NULL;
    }
    
    int cur = strlen(USE_KEYWORD) + 2;
    
    int next = cur;
    while(next<strlen(path) && path[next]!='/') next++;

    if (next != strlen(path)) return NULL;

    char* file_name;
    int file_name_len = next-cur;
    file_name = (char*)malloc(sizeof(char)*(file_name_len+1));
    
    for (int i=cur;i<next;i++){
        file_name[i-cur] = path[i];
    }
    file_name[file_name_len] = '\0';

    return file_name;
}
