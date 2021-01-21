/*
Extracts parent address from entire path 
*/

#include "tree.h"

char *parent_from_path(const char *path){
    printf("call to function: PARENT_FROM_PATH, path: %s\n",path);

    char *dir = (char *)malloc(sizeof(char) + 1);
    if(strcmp(path, "/") == 0)
        return dir; // Root is the special case

    int pathlen = strlen(path);
    bool found = false;
    int i;
    for(i = pathlen - 1; i >= 0; i--){
        if(path[i] == '/'){
            found = true;
            break;
        }
    }
    if(!found){
        error_msg("name_from_path()", "Invalid path");
        return NULL;
    }
    
    //Special case -> "/file.txt", extracted parent should be "/"

    int dir_len = i;
    if (dir_len==0){
        strcpy(dir,"/");
    }
    else{
        dir = (char *)realloc(dir, sizeof(char) * dir_len + 1);
        int j = 0;
        while(j < dir_len){
            dir[j] = path[j];
            j++;
        }
        dir[dir_len] = '\0';
    }

    printf("Extracted parent: %s\n",dir);
    printf("Returning from PARENT_FROM_PATH\n");

    return dir;
}

