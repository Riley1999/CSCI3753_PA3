#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

#define SIZE 6762

int main(int argc, char** argv) 
{
    char *buff[SIZE];
    int count, length = 0;

    if(argv[1]==NULL) {
        printf("Please enter a file name...\n");
        return 1;
    }

    printf("Attempting to open %s...\n", argv[1]);

    int file = 0;

    if((file=open(argv[1], O_RDONLY))==-1) {
        printf("Failed to open file.\n");
        return 1;
    }

    count = read(file, buff, SIZE);
    buff[count] = '\0';

    // printf("Test 0: %c\n", buff[0]);
    // printf("Test 11: %c\n", buff[11]);
    // printf("Test 12: %c\n", buff[12]);

    for(int i=0; i<count; i++) {
        printf("%c\n", buff[i]);
        // if(buff[i]=='\r') {
        //     length = i;
        //     printf("Legnth: %d\n", length);
        // }
    }

    //printf("Buffer: %s\n", buff);
    //printf("COUNT: %d\n", count);

    return 0;
}