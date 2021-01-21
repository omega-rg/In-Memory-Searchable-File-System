# SRC_USE

Here, we have functions that we will need after typing ./USE/… We access the search buffer filled by typing ls ./FIND/… We can make use of the nodes present in the search buffer. In addition to this, there are functions that allow us to add more nodes to the buffer, remove particular nodes, and even the flush out the contents of the buffer completely.

##Functions 
1. ** add_to_search_buffer()**: Add the given node into the search buffer that has been defined in the search directory
2. **free_search_buffer()**: Flush out all node-entries from the search buffer, deallocate/free up it’s memory
3. **get_file_name_use()**: Extract the filename from a “USE” command
4. **get_node_from_search_buffer()**: Search through the buffer to get the node referred to by the filename
5. **is_use_query()**: Returns true if the command typed is for making use of the search buffer, that is, if the command has the following format- <command> ./USE/…
6. **remove_node_from_search_buffer()**: Remove the given node from the search buffer

