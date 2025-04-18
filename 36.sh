# Program Number: 36
# Student Name: Yashub Goel; Register Number: IMT2023117
# Date: 12-04-2025
# Description: Program to create a FIFO file using:
# a. mknod command
# b. mkfifo command
# c. Use strace command to determine which command (mknod or mkfifo) is more efficient.

#! /bin/bash

# a. Use mknod to create a named pipe(i.e. fifo file)
mknod my_mknod_fifo p;


# b. Use mkfifo to create a named pipe(i.e. fifo file)
mkfifo my_mkfifo_fifo;


# c. Use strace command to determine which command (mknod or mkfifo) is more efficient.

# mknod:
echo -e "strace summary for mknod command:";
strace -c mknod myfifo_strace_mknod p;

# mkfifo
echo -e "\nstrace summary for mkfifo command:";
strace -c mkfifo myfifo_strace_mkfifo;

echo -e "\nClearly, mkfifo takes slightly lesser\ntime since mkfifo is specific for creating FIFO files,\nwhile mknod is a more general command\nfor creating various types of special files.\n";


# Remove the files created for strace:
rm myfifo_strace_mknod myfifo_strace_mkfifo;