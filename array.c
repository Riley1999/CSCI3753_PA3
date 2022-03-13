#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include "array.h"

int stack_init(stack *s) 
{
    s->top = -1;
}

int stack_push(stack *s, char *hostname)
{
    // Program input takes # of requester threads
    // test.c will create these threads 
    // Then stack_push will use semaphore 

    if(s->top==-1) {
        s->array[0] = &hostname;
        s->top = 0;
        return 0;
    }
    else if(is_full(s)==1) {
        printf("Stack is full\n");
        return 1;
    }
    else {
        s->array[s->top+1] = &hostname;
        s->top++;
        return 0;
    }
}

int stack_pop (stack *s, char **hostname)
{
    
}

int is_full (stack *s)
{
    if(s->top==7) {
        return 1;
    }
    return 0;
}

void display (stack *s)
{
    for(int i=0; i<8; i++) {
        printf("%s\n", s->array[i]);
    }
}

void stack_free (stack *s)
{
    free(s->array);
} 