class Solution {
public:
    int findMin(vector<int> &nums) 
    {
        int leftPtr = 0;
        int rightPtr = nums.size()-1;
        int result = nums[0];

        while(leftPtr <= rightPtr)
        {
            if(nums[leftPtr] < nums[rightPtr])
            {
                result = min(result,nums[leftPtr]);
                break;
            }
            int midPtr = leftPtr + (rightPtr - leftPtr)/2;
            result = min(result, nums[midPtr]);
            if(nums[midPtr] >= nums[rightPtr])
            {
                leftPtr = midPtr+1;
            }
            else
            {
                rightPtr = midPtr-1;
            }
        }
        return result;
    }
};
