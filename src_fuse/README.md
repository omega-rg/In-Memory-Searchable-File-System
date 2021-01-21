# SRC_FUSE

Contains source files having implementation of FUSE functions

## Functions
1. **imsfs_create()**: Creates a new file in the file system
2. **imsfs_getattr()**: Fills a stat structure with the file/directory attributes
3. **imsfs_main()**: Main program file- Initialises imsfs tree, Initialises searchability data structures and Passes control to FUSE
4. **imsfs_mkdir()**: Creates a new directory in the file system
5. **imsfs_open()**: Opens a file
6. **imsfs_read()**: Reads data from a file and writes it to the buffer provided by FUSE
7. **imsfs_readdir()**: Reads the children of a directory
8. **imsfs_rename()**: Renames a file from oldpath to the newpath
9. **imsfs_rmdir()**: Removes an empty directory
10. **imsfs_unlink()**: Removes a file
11. **imsfs_utimens()**: Changes timestamps of a file
12. **imsfs_write()**: Writes data to a file
