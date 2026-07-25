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
            if(map.find(currNode_p) == map.end())
            {
                Node* newNode_p = new Node(0);
                map[currNode_p] = newNode_p;
            }
            map[currNode_p]->val = currNode_p->val;

            Node* next_p = currNode_p->next;
            Node* random_p = currNode_p->random;

            if(map.find(next_p) == map.end())
            {
                if(next_p)
                {
                    Node* newNode_p = new Node(0);
                    map[next_p] = newNode_p;
                }
            }
            map[currNode_p]->next = map[next_p];

            if(map.find(random_p) == map.end())
            {
                if(random_p)
                {
                    Node* newNode_p = new Node(0);
                    map[random_p] = newNode_p;
                }
            }
            map[currNode_p]->random = map[random_p];
            currNode_p = currNode_p->next;
        }
        return map[head];
    }
};
