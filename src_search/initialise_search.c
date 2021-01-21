/*

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


void initialise_search(){

    //search prefix
    int len_search = strlen("FIND");
    SEARCH_KEYWORD = (char *)malloc(sizeof(char)*len_search+1);
    strcpy(SEARCH_KEYWORD, "FIND");

    //use prefix
    int len_use = strlen("USE");
    USE_KEYWORD = (char *)malloc(sizeof(char)*len_use+1);
    strcpy(USE_KEYWORD, "USE");

    //supported tags
    supported_tags = (char**)malloc(sizeof(char*) * NUM_SUPPORTED_TAGS);
    
    for (int i=0; i<NUM_SUPPORTED_TAGS; i++){
        supported_tags[i] = (char*)malloc(sizeof(char) * (MAX_TAG_LENGTH+1));
    }

    // specify tags here manually
    strcpy(supported_tags[0],"PREFIX");
    strcpy(supported_tags[1],"SUBSTR");

    //search buffer
    search_buffer = NULL;
    num_search_buffer_entries = 0;

}
