class Solution {
public:
    bool isHappy(int n) 
    {
        unordered_set<int> mset;
        while(n != 1)
        {
            int newNum = 0;
            while(n)
            {
                int lastDigit = n%10;
                newNum = newNum + (lastDigit * lastDigit);
                n= n/10;
            }
            if (newNum == 1)
            {
                return true;
            }
            if(mset.find(newNum) != mset.end())
            {
                return false;
            }
            mset.insert(newNum);
            n = newNum;
        }
        return true;
        
    }
};
