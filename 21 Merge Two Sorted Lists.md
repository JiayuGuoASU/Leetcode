https://leetcode.com/problems/merge-two-sorted-lists/submissions/

[**(5) Merge Two Sorted Lists - LeetCode**](https://leetcode.com/problems/merge-two-sorted-lists/submissions/)

Merge two sorted linked lists and return it as a **sorted** list. The list should be made by splicing together the nodes of the first two lists.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/10/03/merge_ex1.jpg)

```
Input: l1 = [1,2,4], l2 = [1,3,4]
Output: [1,1,2,3,4,4]
```

**Example 2:**

```
Input: l1 = [], l2 = []
Output: []
```

**Example 3:**

```
Input: l1 = [], l2 = [0]
Output: [0]
```

 

**Constraints:**

- The number of nodes in both lists is in the range `[0, 50]`.
- `-100 <= Node.val <= 100`
- Both `l1` and `l2` are sorted in **non-decreasing** order.



**SOLUTION：**

```c++
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
```

尝试一下减少内存占用，即不申请newNode，只是用之前的ListNode，不申请新内存。

```c++
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
```

熟悉了C++指针，和new 的操作

在做题的时候出现报错信息：

**runtime error: member access within null pointer of type 'struct ListNode'**

后来经过搜索发现：

直接声明的变量 比如 ListNode *final；

它是有可能被随机分配到一个地址的，有可能是NULL。

所以这时候不能直接用final->next