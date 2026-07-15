class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int,int> freqMap;
        for(int num : nums)
        {
            freqMap[num]++;
        }

        vector<pair<int,int>> sortedFreqList;
        for(auto& [num, freq]: freqMap)
        {
            sortedFreqList.push_back({freq, num});
        }

        sort(sortedFreqList.rbegin(), sortedFreqList.rend());

        vector<int> result;
        for(unsigned i=0; i<k;i++)
        {
            result.push_back(sortedFreqList[i].second);
        }

        return result;
    }
};
