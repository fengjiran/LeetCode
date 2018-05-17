#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *reverseBetween(struct ListNode *head, int m, int n)
{
    ListNode *pre = head;
    int i;
    for (i = 0; i < m - 1; i++)
        pre = pre->next;

    ListNode *cur = pre->next;
}