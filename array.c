#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include "array.h"

int array_init(stack *s) 
{
    for(int i=0; i<8; i++) {
        s->array[i] = malloc(sizeof(char) * MAX_NAME_LENGTH);
    }
    s->top = -1;
    return 0;
}

int array_put(stack *s, char *hostname)
{
    // Program input takes # of requester threads
    // test.c will create these threads 
    // Then stack_push will use semaphore 

    //printf("TEST1\n");

    if (is_full(s)==1) {
        printf("Stack is full, wait...\n");
        return -1;
    }
    //printf("TEST2\n");
    s->top++;
    *s->array[s->top] = hostname;
    //printf("TEST3\n");
    return 0;
}

int array_get (stack *s, char **hostname)
{
    if (is_empty(s)==1) {
        printf("Stack is empty, add elements...\n");
        return 1;
    }
    hostname = s->array[s->top];
    s->top--;
    return 0;
}

int is_full (stack *s)
{
    if(s->top==7) {
        return 1;
    }
    return 0;
}

int is_empty (stack *s)
{
    if(s->top==-1) {
        return 1;
    }
    return 0;
}

int display (stack *s)
{
    if(is_empty(s)==1) {
        printf("Stack is empty, add elements...\n");
        return 1;
    }

    for(int i=0; i<=s->top; i++) {
        printf("%s\n", *s->array[i]);
    }
    return 0;
}

int array_free (stack *s)
{
    free(s->array);
    
    return 0;
} 