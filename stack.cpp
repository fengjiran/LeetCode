#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void initStack(SqStack *S)
{
    S->base = (ElemType *)malloc(sizeof(ElemType) * STACK_INIT_SIZE);
    if (!S->base)
        exit(-1);

    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
}

bool isStackEmpty(SqStack *S)
{
    return S->base == S->top;
}

bool isStackFull(SqStack *S)
{
    return (S->top - S->base) >= S->stacksize;
}

void push(SqStack *S, ElemType e)
{
    if (isStackFull(S))
    {
        S->base = (ElemType *)realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(ElemType));
        if (!S->base)
            exit(-1);

        S->top = S->base + S->stacksize;
        S->stacksize += STACKINCREMENT;
    }

    *(S->top) = e;
    S->top++;
}

void pop(SqStack *S, ElemType *e)
{
    if (isStackEmpty(S))
        exit(-1);
    S->top--;
    *e = *(S->top);
}