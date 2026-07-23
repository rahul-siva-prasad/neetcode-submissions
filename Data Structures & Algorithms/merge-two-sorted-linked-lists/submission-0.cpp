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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        ListNode* head = nullptr;
        ListNode* list1_head = list1;
        ListNode* list2_head = list2;
        ListNode* currNode = head;

        if(list1_head && list2_head)
        {
            if(list1_head->val < list2_head->val)
            {
                head = list1_head;
                list1_head = list1_head->next;
            }
            else
            {
                head = list2_head;
                list2_head = list2_head->next;
            }
        }
        else
        {
            if(list1_head)
            {
                return list1_head;
            }
            else
            {
                return list2_head;
            }
        }
        currNode = head;
        while(list1_head && list2_head)
        {
            if(list1_head->val < list2_head->val)
            {
                currNode->next = list1_head;
                currNode = currNode->next;
                list1_head = list1_head->next;
            }
            else
            {
                currNode->next = list2_head;
                currNode = currNode->next;
                list2_head = list2_head->next;
            }
        }

        if(list1_head)
        {
            currNode->next = list1_head;
        }
        else
        {
            currNode->next = list2_head;
        }
        return head;
    }
};
