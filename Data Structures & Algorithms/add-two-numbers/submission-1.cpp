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
        int carryOverValue =0;
        int isCarryOver =0;

        ListNode *l1Start = l1, *l2Start=l2;
        ListNode* l1_prev_p =nullptr, *l2_prev_p = nullptr;
        ListNode* startNode_p = l1Start;
        while(l1 && l2)
        {
            int result = l1->val + l2->val + isCarryOver;
            isCarryOver = result>9? 1:0;
            result %= 10;
            l1->val = result;
            l2->val = result;

            l1_prev_p = l1;
            l2_prev_p = l2;

            l1 = l1->next;
            l2 = l2->next;
        }
        if(isCarryOver)
        {
            if(l1 == nullptr && l2==nullptr)
            {
                l1_prev_p ->next = new ListNode(1);
            }
            else
            {
                ListNode* next_p = l1? l1:l2;
                ListNode* prev_p = nullptr;
                while(next_p && isCarryOver)
                {
                    int result = next_p->val + isCarryOver;
                    isCarryOver = result>9? 1:0;
                    result %= 10;

                    prev_p = next_p;
                    next_p->val = result;
                    next_p = next_p->next;
                }
                if(isCarryOver)
                {
                    prev_p ->next = new ListNode(1);
                }
            }
        }

        if(l2)
        {
            startNode_p = l2Start;
        }
        
        return startNode_p;
    }
};
