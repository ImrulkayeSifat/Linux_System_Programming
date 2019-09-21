#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


int main(int argc, char *argv[])
{
    int fd_in = -1;
    int fd_out = -1;

    char buffer[10] = {0};
    int ret = 0;
	int retw = 0;
	char *INPUT_FILENAME;
	char *OUTPUT_FILENAME;

    if(argc != 3)
    {
        printf("Please provide the filename as argument to read and for writing\n");
		printf("./a.out test_read test_write\n");
        exit(EXIT_FAILURE);
    }

	INPUT_FILENAME = argv[1];
	OUTPUT_FILENAME = argv[2];

    fd_in = open(INPUT_FILENAME, O_RDONLY);

    if(fd_in == -1)
    {
        printf("Error in opening the input file  error_num=%d  %s\n", errno, strerror(errno) );
        exit(EXIT_FAILURE);
    }

   
    fd_out = open(OUTPUT_FILENAME,   O_TRUNC | O_APPEND | O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

    if(fd_out == -1)
    {
        printf("Error in opening the output file  error_num=%d  %s\n", errno, strerror(errno) );
		close(fd_in); 
        exit(EXIT_FAILURE);
    }

    while ((ret = read(fd_in, (void *)buffer, sizeof(buffer)-1 )) >0 )
    {
		retw = write(fd_out, buffer, ret);

		if(retw != ret)
		{
			printf("Error in writing complete data. error=%s\n", strerror(errno));
			close(fd_out);
			close(fd_in);
			exit(EXIT_FAILURE);
			
		}
        memset(buffer, 0 , sizeof(buffer));
    }

    close(fd_in);
    close(fd_out);

    return EXIT_SUCCESS;
}
