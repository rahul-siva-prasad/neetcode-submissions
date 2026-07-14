#include <cstring>

class Solution {
    struct FREQ_MAP
    {
        unsigned freqMap[26];
    };
    struct UNIQ_ELM
    {
        FREQ_MAP fMap;
        vector<unsigned> idx;
    };

    void f_createFreqMap(FREQ_MAP* fMap, string s)
    {
        std::memset(fMap, 0x00, sizeof(FREQ_MAP));
        for(unsigned i=0; i<s.length(); i++)
        {
            fMap->freqMap[s[i] - 'a'] +=1;
        }
    }
    bool f_isAnagram(FREQ_MAP* angm1, FREQ_MAP* angm2)
    {
        if (std::memcmp(angm1, angm2, sizeof(FREQ_MAP)) == 0)
        {
            return true;
        }
        return false;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        vector<UNIQ_ELM> uniqueElm;
        FREQ_MAP locFreqMap ={0}; 
        bool unique = true;

        for(unsigned i=0; i<strs.size(); i++)
        {
            unique = true;
            f_createFreqMap(&locFreqMap, strs[i]);

            for(unsigned j=0; j<uniqueElm.size(); j++)
            {
                bool isSameGroup = f_isAnagram(&(uniqueElm[j].fMap), &locFreqMap);
                if(isSameGroup)
                {
                    uniqueElm[j].idx.push_back(i);
                    unique = false;
                }
            }

            if(unique)
            {
                UNIQ_ELM elm;
                std::memcpy(&(elm.fMap.freqMap[0]), &locFreqMap, sizeof(FREQ_MAP));
                elm.idx.push_back(i);
                uniqueElm.push_back(elm);
            }
        }

        vector<vector<string>> resultVect;
        for(unsigned i=0; i<uniqueElm.size(); i++)
        {
            vector<string> anagramGroup;
            for(unsigned j=0; j<uniqueElm[i].idx.size(); j++)
            {
                unsigned idx = uniqueElm[i].idx[j];
                anagramGroup.push_back(strs[idx]);
            }
            resultVect.push_back(anagramGroup);

        }

        return resultVect;
    }
};
