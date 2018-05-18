#ifndef _STACK_H_
#define _STACK_H_

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef int ElemType;

typedef struct
{
    ElemType *base;
    ElemType *top;
    int stacksize;
} SqStack;

#endif