#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include "array.h"

// int main(int argc, char **argv)
// {
//     int req = 0;

//     printf("Enter number of requester threads required...\n");
//     scanf("%d", &req);
    
//     pthread_t threads[req];

//     for(int i=0; i<req; i++) {
//         pthread_create(threads[i], NULL, &stack_push, NULL);
//     }
//     return 0;
// }

int main()
{
    char *test[8] = {"ab", "cd", "ef", "gh", "ij", "kl", "mn", "op"};

    stack t;

    stack_init(&t);

    printf("DISPLAY AFTER INIT: \r");
    display(&t);
    
    for(int i=0; i<8; i++) {
        stack_push(&t, test[i]);
    }

    stack_free(&t);
}

