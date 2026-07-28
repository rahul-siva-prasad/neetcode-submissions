class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int maxSumSoFar = nums[0];
        int currSum = 0;
        int arrSize = nums.size();

        for(int i=0; i<arrSize; i++)
        {
            if(currSum<0)
            {
                currSum = 0;
            }
            currSum += nums[i];
            maxSumSoFar = max(maxSumSoFar, currSum);
        }
        return maxSumSoFar;

    }
};
