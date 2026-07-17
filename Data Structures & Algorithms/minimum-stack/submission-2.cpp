class MinStack {
    vector<pair<int,int>> stk;
    int stkIdx;
    int min;

    bool f_isEmpty()
    {
        return stkIdx==-1;
    }
public:
    MinStack() 
    {
        stkIdx = -1;
        min = INT_MAX;
    }
    
    void push(int val) 
    {
        if(val< min)
        {
            min = val;
        }
        stk.push_back({val,min});
        stkIdx++;    
    }
    
    void pop() 
    {
        if(f_isEmpty())
        {
            return;
        }
        stkIdx -=1;
        stk.pop_back();

        if(f_isEmpty())
        {
            min = INT_MAX;
        }
        else
        {
            min = stk[stkIdx].second;
        }
    }
    
    int top() 
    {
        return stk[stkIdx].first;  
    }
    
    int getMin() 
    {
        return stk[stkIdx].second;
    }
};
