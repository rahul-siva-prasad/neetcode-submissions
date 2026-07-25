/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        unordered_map<Node*, Node*> map;

        Node* currNode_p = head;
        while(currNode_p)
        {
            Node* copyNode_p = new Node(currNode_p->val);
            map[currNode_p] = copyNode_p;
            currNode_p = currNode_p->next;
        }

        currNode_p = head;
        while(currNode_p)
        {
            map[currNode_p]->next   =  map[currNode_p->next];
            map[currNode_p]->random =  map[currNode_p->random];
            currNode_p = currNode_p->next;
        }

        return map[head];
        
    }
};
