#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include "array.h"

int main(//int argc, char **argv)
{
    // int req = 0;

    // printf("Enter number of requester threads required...\n");
    // scanf("%d", &req);
    
    // pthread_t threads[req];

    // for(int i=0; i<req; i++) {
    //     pthread_create(threads[i], NULL, &array_put, NULL);
    // }
    // return 0;

    stack s;

    array_init(&s);

    pthread_t thread_id;

    pthread_create(&thread_id, NULL, &array_get, NULL);

    pthread_join(thread_id, NULL);

    return 0;
}

// int main()
// {
//     char *test[8] = {"ab", "cd", "ef", "gh", "ij", "kl", "mn", "op"};

//     stack t;
    
//     array_init(&t);

//     for(int i=0; i<8; i++) {
//         array_put(&t, test[i]);
//     }
    
//     display(&t);

//     array_put(&t, "full");

//     array_get(&t, *t.array);
    
//     display(&t);

//     while(t.top!=-1) {
//         array_get(&t, *t.array);
//     }

//     array_get(&t, *t.array);

//     for(int i=0; i<4; i++) {
//         array_put(&t, test[i]);
//     }

//     display(&t);

//     array_free(&t); 
// }



