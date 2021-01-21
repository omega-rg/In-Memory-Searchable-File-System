/*
Takes path string, resolves it into an existing node from the tree and returns that.
*/

#include "tree.h"

imsfs_tree_node *get_node(const char *path){
    // Format for path is "/directory/sub1/sub2/..."
    //
    // Algorithm for finding node-
    // 1) Store 2 pointers, curptr for cur '/', nxtptr for next '/'
    // 2) nxtptr will point to end of string (nullptr) at the end
    // 3) Generate string from characters in between
    // 4) Current string should be a child current node. If so make this new current node and loop.
    
    printf("path passed to get_node: %s\n",path);
    
    imsfs_tree_node *cur = root;

    if(strcmp(path, "/") == 0){
        return cur;
    }

    int curptr = 0, nxtptr = 1;
    int pathlen = strlen(path);
    char *sub_dir = NULL;
    bool resolved = 0;

    do{
        bool found = 0;
        while(path[nxtptr] != '/'){
            nxtptr++;
            if(nxtptr >= pathlen)
                break;
        }
        curptr++;

        int subdir_len = nxtptr - curptr + 1; //no. of bytes to allocate for subdir
        /*
        if(nxtptr == pathlen) //doubtful
            subdir_len++;
        */
        if(subdir_len <= 0){
            error_msg("Node not found", "Invalid path");
            return NULL;
        }
        sub_dir = (char *)malloc(sizeof(char) * subdir_len);
        for(int i = curptr; i < nxtptr; i++){
            sub_dir[i - curptr] = path[i];
        }
        sub_dir[nxtptr - curptr] = '\0';

        for(int i = 0; i < (cur -> end_of_children); i++){
            if(!(cur -> children[i]))
                continue;
            char *tmp_name = (cur -> children[i]) -> name;
            printf("Temp name dir: %s\n", tmp_name);
            printf("Sub dir name: %s\n", sub_dir);
            printf("Length of sub_dir name %d\n", subdir_len);
            if(strcmp(tmp_name, sub_dir) == 0){
                cur = cur -> children[i];
                found = 1;
                break;
            }
        }
        if(!found)
            break;

        free(sub_dir);
        sub_dir = NULL;
        curptr = nxtptr;
        nxtptr++;
        if(nxtptr >= pathlen)
            resolved = 1;
    }while(nxtptr < pathlen);

    if(!resolved){
            error_msg("Node not found", "Invalid path");
            printf("Path is %s\n", path);
            printf("Unresolved one\n");
            return NULL;
    }

    return cur;
}

