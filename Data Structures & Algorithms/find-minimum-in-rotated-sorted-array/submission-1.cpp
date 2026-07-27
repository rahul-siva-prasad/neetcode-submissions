class Solution {
public:
    int findMin(vector<int> &nums) 
    {
        int size = nums.size();
        for(int i=1 ;i<size;i++)
        {
            if(nums[i] < nums[i-1])
            {
                return nums[i];
            }
        }
        return nums[0];
        
    }
};
