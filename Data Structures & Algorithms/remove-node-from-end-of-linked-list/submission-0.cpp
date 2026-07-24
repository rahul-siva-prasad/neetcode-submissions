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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode dummy(0);
        dummy.next=head;
        ListNode* fastPtr = head;
        ListNode* slowPtr = head;
        ListNode* prev = nullptr;

        while(n > 1)
        {
            n -=1;
            fastPtr = fastPtr->next;
        }
        while(fastPtr->next)
        {
            prev = slowPtr;
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next;
        }
        
        if(slowPtr == head)
        {
            head = slowPtr->next;
            return head;
        }

        prev->next = slowPtr->next;
        return dummy.next;

    }
};
