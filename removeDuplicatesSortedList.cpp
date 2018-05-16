#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *deleteDuplicates(struct ListNode *head)
{
    if (head == NULL)
        return NULL;

    struct ListNode *pre = head;
    struct ListNode *cur = head->next;

    while (cur)
    {
        if (cur->val != pre->val)
        {
            pre->next = cur;
            pre = cur;
        }
        cur = cur->next;
    }

    pre->next = NULL;

    return head;
}