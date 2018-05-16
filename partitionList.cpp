#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

// 创建两个链表a,b（带头结点，注意头结点的指针域初始化为NULL），将原来链表中的每个节点，小于x的节点放在
// a链表的末尾，大于等于x的节点放在b链表的末尾，最后将b的头结点连接到a的末尾
struct ListNode *partition(struct ListNode *head, int x)
{
    struct ListNode *dummy_big = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *dummy_small = (struct ListNode *)malloc(sizeof(struct ListNode));

    dummy_big->next = NULL;
    dummy_small->next = NULL;

    struct ListNode *p1 = dummy_big;
    struct ListNode *p2 = dummy_small;

    struct ListNode *cur = head;

    while (cur)
    {
        if (cur->val < x)
        {
            p1->next = cur;
            p1 = cur;
        }
        else
        {
            p2->next = cur;
            p2 = cur;
        }

        cur = cur->next;
    }

    p1->next = dummy_big->next;
    p2->next = NULL;

    return dummy_small->next;
}