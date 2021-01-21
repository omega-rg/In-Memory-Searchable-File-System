/*
A tree-wide search to fill the search buffer with the files that satisfy the search criteria
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

// int imsfs_readdir_search(const char *path, void *buffer, fuse_fill_dir_t filler, off_t offset, struct fuse_file_info *fi)

void preprocessing(char *pat, int m, int lps[]){
    // lps[i] represents length of largest proper prefix of pat[0:i] that is also a suffix of it.

    if(m == 0)
        return;
    
    lps[0] = 0;

    int i = 1;
    int window  = 0;

    while(i < m){
        if(pat[i] == pat[window]){
            window++;
            lps[i] = window;
            i++;
        }
        else{
            if(window != 0){
                window = lps[window-1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
}

void tree_search_fill_helper(imsfs_tree_node* node, imsfs_searchobj* searcher, fuse_fill_dir_t filler, void *buffer, int m, int lps[]){
    
    for (int i=0; i<node->end_of_children; i++){
        if (node->children[i] == NULL) continue;
        else if (node->children[i]->isfile == 1){
            if (match_node(node->children[i], searcher, m, lps)){
                filler(buffer, node->children[i]->name, NULL, 0);
                add_to_search_buffer(node->children[i]);
            }
        }
        else{
            tree_search_fill_helper(node->children[i], searcher, filler, buffer, m, lps);
        }
    }

    return;
}

void tree_search_fill(fuse_fill_dir_t filler, void *buffer, imsfs_searchobj* searcher){
    
    if (!searcher) return;

    free_search_buffer();

    filler(buffer,".",NULL,0);
    filler(buffer,"..",NULL,0);
    
    int m = 0; // Length of substring
    if((searcher -> substr) != NULL){
        m = strlen(searcher -> substr);
    }
    int lps[m];
    preprocessing(searcher -> substr, m, lps);

    tree_search_fill_helper(root, searcher, filler, buffer, m, lps);

    return;
}

