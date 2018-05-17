#include <stdio.h>
#include <stdlib.h>
#include "list.h"

Status initListHead(LinkList L) //构造一个带头结点的空单链表
{
    Node *head = (Node *)malloc(sizeof(Node)); //头结点
    head->next = NULL;
    L = head;
}