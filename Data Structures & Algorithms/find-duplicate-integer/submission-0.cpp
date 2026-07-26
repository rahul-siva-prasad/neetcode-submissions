class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        int size = nums.size();
        vector<int> hasSeen (size,0);

        for(int num: nums)
        {
            int compIdx = num-1;
            if(hasSeen[compIdx] == 1)
            {
                return num;
            }
            else
            {
                hasSeen[compIdx] = 1;
            }
        }
        return 0;
    }
};
