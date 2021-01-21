/*
This object contains the data that will be used to filter out the files to our search buffer.
For eg, it contains either the prefix, substring or both.
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

imsfs_searchobj* create_search_object(){

    imsfs_searchobj* searcher = malloc(sizeof(imsfs_searchobj));

    //Initialise members
    searcher -> prefix = NULL;
    searcher -> substr = NULL;

    return searcher;
}
