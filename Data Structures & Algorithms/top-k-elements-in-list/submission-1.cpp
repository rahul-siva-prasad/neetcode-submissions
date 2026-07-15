class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map <int,int> freqMap;
        for(int n: nums)
        {
            freqMap[n] +=1;
        }

        vector<vector<int>> repeatVect (nums.size() + 1);

        for(auto& [num, freq]: freqMap)
        {
            repeatVect[freq].push_back(num);
        }

        vector<int> result;

        for(unsigned i=nums.size(); i>0;i --)
        {
            for(int n: repeatVect[i])
            {
                result.push_back(n);
                if(result.size() == k)
                {
                    return result;
                }
            }
        }
        return result;
    }
};
