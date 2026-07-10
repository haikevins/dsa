#include <stdlib.h>

struct ListNode 
{
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) 
{
    struct ListNode dummy;
    dummy.next = head;

    struct ListNode* slow = &dummy;
    struct ListNode* fast = head;

    for (int i = 0; i < n; i++)
    {
        fast = fast->next;
    }

    while (fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }

    struct ListNode* nodeDelete = slow->next;
    slow->next = slow->next->next;

    free(nodeDelete);

    return dummy.next;
}