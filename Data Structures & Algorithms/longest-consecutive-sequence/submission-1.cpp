class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_set<int> lookUp;

        for(int num: nums)
        {
            lookUp.insert(num);
        }
        
        int maxSeq = 0;
        for(int num:nums)
        {
            int locNum = num;
            int locSeq=0;
            //Is sequence possible
            if(!lookUp.contains(locNum-1))
            {
                locSeq+=1;
                while(lookUp.contains(++locNum))
                {
                    locSeq+=1;
                }
            }

            if(locSeq > maxSeq)
            {
                maxSeq = locSeq;
            }
        }
        return maxSeq;
    }
};
