class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        unordered_map <char, int> strMap;
        int leftLimit = 0;
        int rightLimit = 0;
        int maxSubStringLen = 0;

        for(; rightLimit < s.size(); rightLimit++)
        {
            char currChar = s[rightLimit];
            if(strMap.find(currChar) != strMap.end())
            {
                leftLimit = max(strMap[currChar]+1, leftLimit);
            }
            strMap[currChar] = rightLimit;
            maxSubStringLen = max(maxSubStringLen, rightLimit - leftLimit+1);
        }
        return maxSubStringLen;
    }
};
