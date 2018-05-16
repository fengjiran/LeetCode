#ifndef _LIST_H_
#define _LIST_H_

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define MAXSIZE 20

typedef int Status;
typedef int ElemType;

typedef struct Node
{
    ElemType data;
    struct Node *next;
} Node;
typedef struct Node *LinkList;

typedef struct dulNode
{
    ElemType data;
    struct dulNode *prior;
    struct dulNode *next;
} dulNode;
typedef struct dulNode *dulLinkList;

#endif // _LIST_H_
