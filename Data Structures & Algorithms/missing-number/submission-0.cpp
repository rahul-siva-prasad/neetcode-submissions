class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        int size = nums.size();
        int xorr = size;

        for(int i=0; i< size;i++)
        {
            xorr = xorr ^ i ^ nums[i];
        }
        return xorr;

    }
};
