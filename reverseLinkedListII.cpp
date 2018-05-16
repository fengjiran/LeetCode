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
    for (i = 1; i < m - 1; i++)
        pre = pre->next;

    ListNode *head2 = pre;
    pre = head2->next;
    ListNode *cur = pre->next;

    for (i = m; i < n; i++)
    {
        pre->next = cur->next;
        cur->next = head2->next;
        head2->next = cur;
        cur = pre->next;
    }

    return head;
}