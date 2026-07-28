class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int arrSize = nums.size();

        int leftPtr = 0;
        int rightPtr = arrSize-1;

        while(leftPtr <= rightPtr)
        {
            if(nums[leftPtr] == target)
            {
                return leftPtr;
            }
            if(nums[rightPtr] == target)
            {
                return rightPtr;
            }

            int midPtr = leftPtr + (rightPtr - leftPtr)/2;
            int mid = nums[midPtr];
            if(mid == target)
            {
                return midPtr;
            }
            
            if(nums[leftPtr] <= mid)//leftArray is sorted
            {
                if(target > mid || target < nums[leftPtr])
                {
                    leftPtr = midPtr+1;
                }
                else
                {
                    rightPtr = midPtr-1;
                }
            }
            else
            {
                if(target < mid || target > nums[rightPtr])
                {
                    rightPtr = midPtr-1;
                }
                else
                {
                    leftPtr = midPtr+1;
                }

            }
        }
        return -1;
        
    }
};
