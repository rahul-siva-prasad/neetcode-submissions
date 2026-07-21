class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        unordered_set<char> strSet;
        int size = s.size();
        int maxSequence=0;
        int locSequence=0;
        int leftPtr=0;

        for(int i=0 ;i< size; )
        {
            if(!strSet.contains(s[i]))
            {
                locSequence +=1;
                strSet.insert(s[i]);
                if(locSequence > maxSequence)
                {
                    maxSequence = locSequence;
                }
                i++;
            }
            else
            {
                locSequence=0;
                strSet.clear();
                i = leftPtr+1;
                leftPtr=i;
            }
        }
        return maxSequence;
        
    }
};
