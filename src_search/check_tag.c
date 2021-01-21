/*
Checks if the search keyword is supported or not(currently, “PREFIX” or “SUBSTR”).
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

int check_tag(char* tag){
    
    for(int i=0; i<NUM_SUPPORTED_TAGS; i++){
        if (strcmp(tag, supported_tags[i]) == 0){
            return 1;
        }
    }

    return 0;
}