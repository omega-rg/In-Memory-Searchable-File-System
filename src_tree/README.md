# SRC_TREE

In this directory, you will find functions used to implement the actual tree functionality. We would like to remind the reader that all our files and directories are stored in the data structure imsfs_tree_node defined by us. 

## Functions
1. **add_dir_node()** and **add_file_node()** create nodes for directories and files. They will be used when commands such as mkdir and touch are called.
2. **assign_mex()** find the smallest whole number position at which a pointer to a child node has not been defined, and assigns a pointer to point to the child directory in question
3. **change_node_location()**: Moves a node from one location in the file system to another. If the node is a directory node, the entire subtree rooted at it is moved.
4. **check_leaf()**: Checks if the specified node is a leaf node or not
5. **error_msg()**: Helper function for error handling
find_pos(): Finds the position of child with respect to the parent node
6. **free_dir_node_recursive()**: Unlinks and frees up memory for a leaf directory node.
7. **free_file_node()**: Unlikes and frees up memory for a file node
8. **get_dir_node()**: Takes path as argument and return the pointer to the node only if it is a directory node
9. **get_file_node()**: Takes path as argument and return the pointer to the node only if it is a file node
10. **get_node()**: Takes path string, resolves it into an existing node from the tree and returns that.
11. **initialise_imsfs()**: Initialises the data structure. Defines a root node as well 
12. **name_from_path()**: Extracts name from entire path 
parent_from_path(): Extracts parent address from entire path 
13. **parent_node_from_path()**: Returns parent node from the given path
14. **print_node_data()**: Prints all data stored in the node
15. **recursive_path_update()**: Once a directory’s location is changed, we have to change the locations of all the nodes in the subtree rooted at that node. This function does just that.
16. **remove_empty_dir()**: If the node is a directory node and it has no children, the node gets removed by this function.
17. **remove_empty_dir()**: If the node is a file node, the node gets removed by this function.
18. **rename_node()**: Changes the name of the specified node(if the node is a directory node, we have update the paths of all its children, and their children and so on)
