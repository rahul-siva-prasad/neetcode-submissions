class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<string, vector<string>> hashMap;
        
        for(string s: strs)
        {
            vector<int> freqMap(26,0);
            for(char ch: s)
            {
                freqMap[ch - 'a']++;
            }

            string key = to_string(freqMap[0]);
            for(size_t i=1; i< 26;i++)
            {
                key += ','+ to_string(freqMap[i]);
            }

            hashMap[key].push_back(s);
        }
        vector<vector<string>> result;
        for(auto& [key, vecString]: hashMap)
        {
            result.push_back(vecString);
        }

        return result;
    }
};
