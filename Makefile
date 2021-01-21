CC = gcc
MOUNTPOINT = mountpoint
DIRS = src_fuse src_tree src_fuse_search_use src_search src_use
MAIN = ./src_fuse/imsfs_main.c
HEADERS = -I./include/
CCFLAGS = -Wall -D_FILE_OFFSET_BITS=64 `pkg-config fuse --libs` -DFUSE_USE_VERSION=26 -lm
SOURCE = $(wildcard ./src_*/*.c)
EXECUTABLE = imsfs

all: run_imsfs
	
run_imsfs: $(MOUNTPOINT) $(EXECUTABLE) 
	@echo "Running IMSFS"
	./$(EXECUTABLE) -f $(MOUNTPOINT)

$(MOUNTPOINT): 
	@echo "Making mountpoint"
	@mkdir $(MOUNTPOINT)

$(EXECUTABLE): $(DIRS) $(MAIN) 
	@echo "Building"
	$(CC) -o $(EXECUTABLE) $(HEADERS) $(SOURCE) $(CCFLAGS)

clean:
	-fusermount -zu $(MOUNTPOINT)
	rm -f -r $(MOUNTPOINT)
	rm -f $(EXECUTABLE)
