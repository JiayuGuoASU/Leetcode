/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *finalList = new ListNode(0);
        ListNode *head = finalList;
        while (l1 && l2)
        {
            ListNode *newNode = new ListNode(0);
            if (l1->val > l2->val)
            {
                newNode = l2;
                cout << "l2" << l2->val << endl;
                l2 = l2->next;
            }
            else
            {
                newNode = l1;
                cout << "l1" << l1->val << endl;
                l1 = l1->next;
            }
            finalList->next = newNode;
            finalList = finalList->next;
        }
        if (l1)
        {
            finalList->next = l1;
        }
        if (l2)
        {
            finalList->next = l2;
        }
        return head->next;
    }
};

尝试一下减少内存占用，即不申请newNode，只是用之前的ListNode，不申请新内存。
class Solution2
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *finalList = new ListNode(0);
        ListNode *head = finalList;
        while (l1 && l2)
        {
            if (l1->val > l2->val)
            {
                finalList->next = l2;
                l2 = l2->next;
            }
            else
            {
                finalList->next = l1;
                l1 = l1->next;
            }
            finalList = finalList->next;
        }
        if (l1)
        {
            finalList->next = l1;
        }
        if (l2)
        {
            finalList->next = l2;
        }
        return head->next;
    }
};
04/27/2021   11:12	Accepted	8 ms	15.1 MB	cpp 
04/27/2021   11:15	Accepted	4 ms	14.8 MB	cpp