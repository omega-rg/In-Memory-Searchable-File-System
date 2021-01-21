/*
Helper function for error handling
*/


#include "tree.h"


void error_msg(const char * msg, const char * reason){
    // fputs(msg, stderr);
    // fputs(": ", stderr);
    // fputs(reason, stderr);
    // fputs("\n", stderr);

    printf("%s: ",msg);
    printf("%s\n",reason);

    //exit(1);
}
