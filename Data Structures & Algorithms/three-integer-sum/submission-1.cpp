class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> result;
        int leftPtr, rightPtr;
        int target = 0;
        sort(nums.begin(), nums.end());

        for(int i=0; i<nums.size()-2; i++)
        {
            if(i>0 && nums[i] == nums[i-1])
            {
                continue;
            }

            leftPtr = i+1;
            rightPtr = nums.size()-1;
            while(leftPtr < rightPtr)
            {
                int sum= nums[i] + nums[leftPtr] + nums[rightPtr];
                if(sum < target)
                {
                    leftPtr++;
                }
                else if (sum > target)
                {
                    rightPtr--;
                }
                else
                {
                    result.push_back({nums[i], nums[leftPtr], nums[rightPtr]});
                    leftPtr++;
                    rightPtr--;
                    while(leftPtr< rightPtr && nums[leftPtr] == nums[leftPtr-1])
                    {
                        leftPtr++;
                    }
                    while(leftPtr< rightPtr && nums[rightPtr] == nums[rightPtr+1])
                    {
                        rightPtr--;
                    }
                    continue;
                }
            }
        }
        return result;
    }
};
