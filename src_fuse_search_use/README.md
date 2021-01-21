# SRC_SEARCH_FUSE_USE

Contains implementations of FUSE functions in case of a search/use request.

## Functions
1. **imsfs_getattr_search()**: Exposes the directories in the search-query command as empty directories
2. **imsfs_getattr_use()**: Return the attributes of the file requested using use query
3. **imsfs_open_use()**: Opens the file requested using  the use query
4. **imsfs_read_use()**: Reads the file requested using the use query
5. **imsfs_readdir_search()**: Searches for file which match the metadata specified in the search query
6. **imsfs_unlink_use()**: Removes the file requested using the use query
7. **imsfs_write_use()**: Writes to the file requested using the use query
