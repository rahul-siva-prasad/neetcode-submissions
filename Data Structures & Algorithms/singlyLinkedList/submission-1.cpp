class LinkedList {
private:
    struct Node
    {
        struct Node* next;
        int data;
    };

    Node* head;

    Node* f_createNode(int data)
    {
        Node* node_p = new Node;
        node_p->data = data;
        node_p->next = NULL;
        return node_p;
    }
public:
    LinkedList() 
    {
        this->head=NULL;
    }

    int get(int index) 
    {
        Node* currNode_p = this->head;
        for(unsigned i=0; i<index; i++)
        {
            if(!currNode_p)
            {
                return -1;
            }
            currNode_p = currNode_p->next;
        }

        if(!currNode_p)
        {
            return -1;
        }
        
        return currNode_p->data;
    }

    void insertHead(int val) 
    {
        Node* newNode_p = f_createNode(val);

        if(this->head == NULL)
        {
            this->head = newNode_p;
            return;
        }

        newNode_p->next = this->head;
        this->head = newNode_p;
    }
    
    void insertTail(int val) 
    {
        Node* newNode_p = f_createNode(val);

        if(this->head == NULL)
        {
            this->head = newNode_p;
            return;
        }

        Node* currNode_p = this->head;
        while(currNode_p->next)
        {
            currNode_p = currNode_p->next;
        }
        currNode_p->next = newNode_p;
    }

    bool remove(int index) 
    {
        Node* currNode_p = this->head;
        Node* prevNode_p = NULL;

        if(currNode_p == NULL)
        {
            return false;
        }
        if(index == 0)
        {
            Node* tempNode_p = this->head->next;
            delete this->head;
            this->head = tempNode_p;
            return true;
        }

        for(unsigned i=0; i<index; i++)
        {
            if(!currNode_p)
            {
                return false;
            }
            prevNode_p = currNode_p;
            currNode_p = currNode_p->next;
        }

        if(!currNode_p)
        {
            return false;
        }
        
        prevNode_p->next = currNode_p->next;
        delete currNode_p;
        return true;
}

    vector<int> getValues() 
    {
        vector<int> listResult;

        Node* currNode_p = this->head;
        while(currNode_p)
        {
            listResult.push_back(currNode_p->data);
            currNode_p = currNode_p->next;
        }

        return listResult;
    }
};
