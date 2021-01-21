/*
Find out whether the given node matches the criteria of the search object
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

int KMP(char *text, char *pat, int n, int m, int lps[]){
    int i = 0; // text pointer
    int j = 0; // pattern pointer

    while(i<n){
        if(text[i] == pat[j]){
            i++;
            j++;
        
            if(j==m){
                return 1;
            }

        }
        
        else{

            if(j == 0){
                i++;
            }
            else{
                j = lps[j-1];
            }
        }

    }
    return 0;
}


int match_node(imsfs_tree_node *node, imsfs_searchobj *searcher, int m, int lps[]){
    
    int match = 1; //indicated whether current node is a successfull match, need to check all constraints

    //prefix matching
    if (searcher->prefix != NULL){
        
        if (strlen(node->name) < strlen(searcher->prefix)) return 0;
        
        for (int i=0; i<strlen(searcher->prefix); i++){
            if (node->name[i] != searcher->prefix[i]) return 0;
        }
    }

    if(((searcher -> substr) != NULL) && (m > 0)){

        if(strlen(node -> name) < m)
            return 0;

        if(!KMP(node -> name, searcher -> substr, strlen(node -> name), m, lps))
            return 0;
    }

    return match;
}

