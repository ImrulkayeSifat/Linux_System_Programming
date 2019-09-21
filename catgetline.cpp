#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *fp;
    char *line = NULL;
    size_t len =0;
    ssize_t read;

    fp = fopen("hello.txt","r");
    if(fp == NULL)
        exit(EXIT_FAILURE);
    printf("Characters read:\t\t Contents\n");
    while((read = getline(&line,&len,fp)) != -1)
    {
        printf("%zu :\t",read);
        printf("%s",line);
    }
    if(line)
        free(line);
    fclose(fp);
    exit(EXIT_SUCCESS);
}
