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
    void reorderList(ListNode* head) 
    {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* slowPtr = head;
        ListNode* fastPtr = head;
        while(fastPtr && fastPtr->next)
        {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }
        //MIDPOINT is slowPtr
        ListNode* midPoint = slowPtr;

        ListNode* prev = nullptr;
        ListNode* curr = midPoint;
        ListNode* next = nullptr;
        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        ListNode* l1 = dummy.next;
        ListNode* l2 = prev;

        int index = 0;
        while(l1 && l2 && l1 != midPoint)
        {
            if(index == 0)
            {
                ListNode* next = l1->next;
                l1->next = l2;
                l1 = next;
            }
            else
            {
                ListNode* next = l2->next;
                l2->next = l1;
                l2 = next;
            }
            index = !index;
        }        
    }
};
