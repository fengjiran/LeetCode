#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
    int val;
    struct ListNode *next;
} ListNode;

// 1.因为存储是反过来的，即数字342存成2->4->3，所以要注意进位是向后的；
// 2.链表l1或l2为空时，直接返回，这是边界条件，省掉多余的操作；
// 3.链表l1和l2长度可能不同，因此要注意处理某个链表剩余的高位；
// 4.2个数相加，可能会产生最高位的进位，因此要注意在完成以上1－3的操作后，判断进位是否为0，
//   不为0则需要增加结点存储最高位的进位。
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    if (l1 == NULL && l2 == NULL)
        return NULL;

    ListNode *p1 = l1->next;
    ListNode *p2 = l2->next;

    ListNode *l3 = (ListNode *)malloc(sizeof(ListNode));
    l3->next = NULL;
    ListNode *p3 = l3;

    int carry = 0;
    int sum = 0;

    while (p1 != NULL && p2 != NULL)
    {
        sum = p1->val + p2->val;
        carry = sum / 10;

        ListNode *temp = (ListNode *)malloc(sizeof(ListNode));
        temp->val = sum % 10;

        p1 = p1->next;
        p2 = p2->next;

        p3->next = temp;
        p3 = p3->next;
        p3->next = NULL;
    }
}