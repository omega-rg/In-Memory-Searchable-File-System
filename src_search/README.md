# SRC_SEARCH

In this directory, we have defined all those functions that enable us to search through our filesystem based on our tags(prefix search or substring match)

## Functions
1. **check_tag()**: Checks if the search keyword is supported or not(currently, “PREFIX” or “SUBSTR”).
2. **create_search_object()**: This object contains the data that will be used to filter out the files to our search buffer. For eg, it contains either the prefix, substring or both.
3. **free_search_object()**: Clears the search object and deallocates its memory.
4. **get_search_object()**: From the search command typed, create the search object with the prefix pointers and the substring pointers pointing to the appropriate keywords
5. **get_tag_ptr()**: Get the pointer for tag depending on the input string
6. **initialise_search()**: Declares and initialises the keywords for search and use. Allocates data for the search tags- “PREFIX”, “SUBSTR”
7. **is_search_query()**: Returns true if the command typed is for using the searchability feature of the file system
8. **match_node()**: Find out whether the given node matches the criteria of the search object
9. **tree_search_fill()**: A tree-wide search to fill the search buffer with the files that satisfy the search criteria

