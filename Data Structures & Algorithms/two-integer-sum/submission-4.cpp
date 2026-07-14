class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> res;
        unordered_map<int,int> ump;

        for(size_t i=0; i<nums.size();i++)
        {
            int complement = target - nums[i];

            if(ump.find(complement) != ump.end())
            {
                res.push_back(ump[complement]);
                res.push_back(i);
                return res;
            }
            ump[nums[i]] = i;
        }
        return res;
    }
};
