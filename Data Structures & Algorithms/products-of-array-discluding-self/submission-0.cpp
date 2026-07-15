class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int prod=1;
        int zeroCount = 0;
        int zeroIdx = -1;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] == 0)
            {
                zeroCount ++;
                if(zeroIdx == -1)
                {
                    zeroIdx = i;
                }
            }
            else
            {
                prod *= nums[i];
            }
        }

        vector<int> result(nums.size(),0);        
        if(zeroCount>1)
        {
            return result;
        }
        else
        {
            if(zeroCount == 1)
            {
                result[zeroIdx] = prod;
                return result;
            }
            else
            {
                for(int i=0; i<nums.size(); i++)
                {
                    result[i] = prod/nums[i];
                }
            }
        }
        return result;
    }
};
