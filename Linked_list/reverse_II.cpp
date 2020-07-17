// Reverse a linked list from position m to n.Do it in one - pass.
//Note : 1 ≤ m ≤ n ≤ length of list.
//Example :
//Input : 1->2->3->4->5->NULL,
//m = 2, n = 4 Output : 1->4->3->2->5->NULL
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *reverseBetween(ListNode *head, int m, int n)
{
    if (head == nullptr || head->next == nullptr || m == n)
    {
        return head;
    }
    ListNode *dummy = new ListNode(0, head);
    ListNode *temp = dummy;
    int i = 0;
    while (temp)
    {
        i++;
        if (i == m)
        {
            ListNode *start = temp->next;
            ListNode *end = temp->next;
            for (int j = m; j < n; j++)
            {
                ListNode *temp1 = end->next;
                end->next = temp1->next;
                temp1->next = start;
                start = temp1;
            }
            temp->next = start;
            break;
        }
        temp = temp->next;
    }
    return dummy->next;
}

//Reverse code simple

ListNode *reverse(ListNode *head)
{
    if (!head || !head->next)
    {
        return head;
    }
    ListNode *temp = reverse(head->next);
    head->next->next = head;
    head->next = nullptr;
    return temp;
}