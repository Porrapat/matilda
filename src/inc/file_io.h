/*
Functions for file input/output.
*/

#ifndef MATILDA_FILE_IO_H
#define MATILDA_FILE_IO_H

#include "config.h"

#include <stdio.h>

#include "types.h"


/*
Create a new file and open it for writing; creating new filenames if the file
already exists.
RETURNS file descriptor
*/
int create_and_open_file(
    char * restrict filename,
    u32 filename_size,
    const char * restrict prefix,
    const char * restrict extension
);

/*
RETURNS the number of bytes read or -1 if failed to open/be read
*/
d32 read_binary_file(
    void * dst_buf,
    u32 buf_len,
    const char * filename
);

/*
RETURNS the number of ASCII characters read or -1 if failed to open/be read
*/
d32 read_ascii_file(
    char * restrict dst_buf,
    u32 buf_len,
    const char * restrict filename
);

/*
Searches for and allocates the space needed for the relative path to the files
found ending with the text present in extension.
At most fills max_files file names.
RETURN number of file names saved
*/
u32 recurse_find_files(
    const char * restrict root,
    const char * restrict extension,
    char ** filenames,
    u32 max_files
);

#endif
