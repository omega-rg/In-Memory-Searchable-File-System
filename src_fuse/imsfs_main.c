/*
Main program file
1) Initialises imsfs tree 
2) Initialises searchability data structures
3) Passes control to FUSE
*/

#define FUSE_USE_VERSION 26
#include <fuse.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>
#include "imsfs_operations.h"
#include "imsfs_operations_search_use.h"

//Fuse functions implemented by us
static struct fuse_operations imsfs_operations = {
    .getattr    = imsfs_getattr,
    .create    = imsfs_create,
    //.mknod     = imsfs_mknod,
    .mkdir      = imsfs_mkdir,
    .unlink     = imsfs_unlink,
	.rmdir	    = imsfs_rmdir,
	.rename	    = imsfs_rename,
	.open	    = imsfs_open,
	.read	    = imsfs_read,
	.write	    = imsfs_write,
	.readdir	= imsfs_readdir,
	.create	    = imsfs_create,
	.utimens	= imsfs_utimens,
};


int main(int argc, char **argv) {

	printf("Initialising tree\n");
    initialise_imsfs();
	printf("Initialised tree\n");

	printf("Initialising searchability\n");
    initialise_search();
	printf("Initialised searchability\n");

    //Pass control to FUSE
	return fuse_main(argc, argv, &imsfs_operations, NULL);
}
