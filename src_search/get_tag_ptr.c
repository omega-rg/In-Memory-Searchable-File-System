/*
Get the pointer for tag depending on the input string
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
#include <ctype.h>
#include "tree.h"
#include "search_use_query.h"

char** get_tag_ptr(imsfs_searchobj* searcher, const char* tag){
    
    printf("get_tag_ptr called for object: %p and path: %s\n",searcher,tag);

    int found = 0;

    for(int i=0; i<NUM_SUPPORTED_TAGS; i++){
        if (strcmp(tag, supported_tags[i]) == 0){
            found = 1;       
        }
    }
    if (!found) return NULL;

    printf("is tag valid: %d\n",found);

    char* curtag = malloc(sizeof(char)*(strlen(tag)+1));
    strcpy(curtag, tag);
    for (int i=0;i<strlen(curtag);i++){
        curtag[i] = tolower(curtag[i]);
    }
    curtag[strlen(tag)] = '\0';

    printf("tag lowercased: %s\n", curtag);

    //switch for tag, can't use switch for strings
    if (strcmp("prefix",curtag) == 0) {printf("returning prefix from get_tag_ptr\n"); return (&searcher->prefix);}
    else if(strcmp("substr", curtag) == 0){
        printf("returning substr from get_tag_ptr\n");
        return &(searcher -> substr);
    }
    else{
        free(curtag);
        curtag = NULL;
        return NULL;
    }

}
