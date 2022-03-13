#ifndef STACK_H
#define STACK_H

#define STACK_SIZE 8                               // max elements in stack
#define MAX_NAME_LENGTH 30 

typedef struct {
    char **array[STACK_SIZE];                      // storage array for integers
    int top;                                       // array index indicating where the top is
} stack;

    int  array_init(stack *s);                     // init the stack
    int  array_put(stack *s, char *hostname);     // place element on the top of the stack
    int  array_get (stack *s, char **hostname);    // remove element from the top of the stack
    int  is_full(stack *s);
    int  is_empty(stack *s);
    int display(stack *s);
    int array_free(stack *s);                     // free the stack's resources

#endif