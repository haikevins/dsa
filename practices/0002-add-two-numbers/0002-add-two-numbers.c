#include <stdlib.h>
#include <stdint.h>

struct ListNode 
{
    int val;
    struct ListNode *next;
};

struct ListNode* createNode(int value) 
{
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));

    node->val = value;
    node->next = NULL;

    return node;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) 
{
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = NULL;

    struct ListNode* tail = &dummy;

    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) 
    {
        int sum = carry;

        if (l1 != NULL) 
        {
            sum += l1->val;
            l1 = l1->next;
        }
        else
        {
            sum += 0;
        }

        if (l2 != NULL) 
        {
            sum += l2->val;
            l2 = l2->next;
        }
        else
        {
            sum += 0;
        }

        int digit = sum % 10;
        carry = sum / 10;

        tail->next = createNode(digit);
        tail = tail->next;
    }

    return dummy.next;
}