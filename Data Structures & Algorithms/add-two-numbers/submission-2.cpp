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

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode dummy(0);
        int carryOver = 0;
        ListNode* currNode_p = &dummy;
        while( l1 || l2 || carryOver)
        {
            int val1 = l1? l1->val : 0;
            int val2 = l2? l2->val : 0;
            int result = val1 + val2 + carryOver;
            carryOver = result>9 ? 1:0;
            result %= 10;

            currNode_p->next = new ListNode(result);
            currNode_p = currNode_p->next;

            l1= l1? l1->next: nullptr;
            l2= l2? l2->next: nullptr;
        }
        return dummy.next;
    }
};
