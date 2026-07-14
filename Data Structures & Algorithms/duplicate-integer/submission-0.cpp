class Solution {
public:
    bool hasDuplicate(vector<int>& nums) 
    {
        int arrSize = nums.size();

        sort(nums.begin(), nums.end());

        for(unsigned i=1; i<arrSize; i++)
        {
            if(nums[i] == nums[i-1])
            {
                return true;
            }
        }
        return false;
    }
};