#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

// 从第二个结点开始，依次将结点插入第一个结点之前，完成翻转
struct ListNode *reverseList(struct ListNode *head)
{
    if (head == NULL)
        return NULL;
    //
}