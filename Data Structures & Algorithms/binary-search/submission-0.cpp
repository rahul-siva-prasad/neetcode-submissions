class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        size_t size = nums.size();
        int left = 0;
        int right = size-1;
        int mid;

        while(left <= right)
        {
            mid = left + (right-left)/2;
            int midElm = nums[mid];
            if(midElm == target)
            {
                return mid;
            }
            else if(midElm < target)
            {
                left = mid +1;
            }
            else
            {
                right = mid -1;
            }
        }

        return -1;
        
    }
};
