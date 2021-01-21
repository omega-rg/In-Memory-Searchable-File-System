/*
Extracts name from entire path 
*/

#include "tree.h"

char *name_from_path(const char *path){
    printf("call to function: NAME_FROM_PATH, parent_path: %s\n",path);

    if(strcmp(path, "/") == 0)
        return NULL;

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
    
    i++;
    int name_len = pathlen - i;
    char *name = (char *)malloc(sizeof(char) * name_len + 1);
    int j = 0;
    while(i < pathlen){
        name[j] = path[i];
        j++;
        i++;
    }

    name[name_len]='\0';
    printf("Extracted name: %s\n",name);
    printf("Returning from NAME_FROM_PATH\n");

    return name;
}

