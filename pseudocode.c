
                                    IIIIIIIIIIIIIIIIII
                                    I   PSEUDOCODE   I
                                    IIIIIIIIIIIIIIIIII

    Things to understand:
- file descriptor
- buffer
- static variable
- helper functions
- how read() works


I NEED TO MAKE A PROGRAM THAT (READS) THROUGH THE LINES OF A FILE AND PRINTS LINE BY LINE

we read a file using a file descriptor
we use a buffer with a specific buffer size to read parts of the file
we use a static variable to store leftover content between calls
we will make helper functions to help us find a new line or others

main function logic
--
we call read() - - store the results in a buffer
check if a newline character exists in the current read chunk
if found return the line / otherwise keep reading and appending
                           until new line is reached.
ensure to return the line when the file ends. (even without "\n")

handle edge cases
--
test with different buffer sizes
                    empty files
                    large files
                    memory leaks
                    returns NULL on errors

compile and test
--
test the code by compiling with different buffer sizes (-D BUFFER_SIZE=n)