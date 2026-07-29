class Solution {
public:
    vector<int> countBits(int n) 
    {
        vector<int> result;
        for(int num=0; num<=n ;num++)
        {
            int numCopy = num;
            int count=0;
            while(numCopy)
            {
                numCopy &= (numCopy-1);
                count++;
            }
            result.push_back(count);
        }
        
        return result;
    }
};
