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

void initStack(SqStack *S);
bool isStackEmpty(SqStack *S);
bool isStackFull(SqStack *S);
void push(SqStack *S, ElemType e);
void pop(SqStack *S, ElemType *e);

#endif