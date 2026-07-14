class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        if(s.length() != t.length())
        {
            return false;
        }

        int freqMap_s[26] = {0};
        int freqMap_t[26] = {0};

        for(size_t i=0 ;i<s.length() ;i++)
        {
            freqMap_s[s[i] - 'a']++;
            freqMap_t[t[i] - 'a']++;
        }

        for(size_t i=0; i<26; i++)
        {
            if(freqMap_s[i] != freqMap_t[i])
            {
                return false;
            }
        }
        return true;
    }
};
