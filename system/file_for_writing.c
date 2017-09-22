// opeaning a file for writing using system call and checking their permissions

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char **argv){

	int fd, flags, mode;
	flags = O_CREAT ;
	mode = S_IWGRP | S_IWUSR | S_IWOTH ;
	fd = open("test.txt", flags, mode);
	close(fd);

	return 0;
}