/*
This file contains the implementation of the fuse functions.
*/

#ifndef IMSFS_OPERATIONS_H
#define IMSFS_OPERATIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdarg.h>

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

#include <fuse.h>
#include "tree.h"

int imsfs_getattr (const char *, struct stat *);
int imsfs_create (const char * , mode_t, struct fuse_file_info *);
int imsfs_mkdir (const char *, mode_t);
int imsfs_open (const char *, struct fuse_file_info *);
int imsfs_read (const char *, char *, size_t, off_t, struct fuse_file_info *);
int imsfs_write (const char *, const char *, size_t, off_t, struct fuse_file_info *);
int imsfs_readdir (const char *, void *, fuse_fill_dir_t, off_t, struct fuse_file_info *);
int imsfs_rmdir (const char *);
int imsfs_unlink (const char *);
int imsfs_rename (const char *, const char *);
int imsfs_utimens (const char *, const struct timespec tv[2]);

#endif
