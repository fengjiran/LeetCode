#include <stdio.h>
#include <stdlib.h>
#include "list.h"

Status initListHead(LinkList L) //构造一个带头结点的空单链表
{
    Node *head = (Node *)malloc(sizeof(Node)); //头结点
    head->next = NULL;
    L = head;
    return OK;
}

Status insertListHead(LinkList L, ElemType e) //头插法插入一个结点，带有头结点的链表
{
    Node *s = (Node *)malloc(sizeof(Node)); //申请一个结点
    s->data = e;

    s->next = L->next;
    L->next = s;

    return OK;
}

Status getElem(LinkList L, int i, ElemType *e)
{
    // L为带头结点的单链表的头指针
    // 获取第i个元素的值，赋值给e，i>=1
    Node *p = L->next;
    int j = 1;

    while (p && j < i)
    {
        p = p->next;
        j++;
    }

    if (!p || j > i)
        return ERROR;
    *e = p->data;
    return OK;
}