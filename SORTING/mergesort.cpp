#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *sortList(ListNode *head)
{
    if (!head || !head->next)
    {
        return head;
    }
    ListNode dummy = ListNode(0);
    dummy.next = head;
    ListNode *slow = &dummy;
    ListNode *fast = &dummy;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *l1 = sortList(slow->next);
    slow->next = NULL;
    ListNode *l2 = sortList(head);

    //merge
    dummy.next = NULL;
    ListNode *p = &dummy;
    while (l1 && l2)
    {
        if (l1->val <= l2->val)
        {
            p->next = l1;
            l1 = l1->next;
            p = p->next;
            p->next = NULL;
        }
        else
        {
            p->next = l2;
            l2 = l2->next;
            p = p->next;
            p->next = NULL;
        }
    }
    if (l1 == NULL)
    {
        p->next = l2;
    }
    if (l2 == NULL)
    {
        p->next = l1;
    }
    return dummy.next;
}