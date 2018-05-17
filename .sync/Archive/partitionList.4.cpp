#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *partition(struct ListNode *head, int x)
{
    struct ListNode *dummy_big = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *dummy_small = (struct ListNode *)malloc(sizeof(struct ListNode));

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