class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        //BRUTE FORCE
        vector<int> result;
        for(int i=0; i<temperatures.size()-1; i++)
        {
            int count=0;
            bool found= false;
            for(int j=i+1; j<temperatures.size(); j++)
            {
                count++;
                if(temperatures[j] > temperatures[i])
                {
                    found = true;
                    break;
                }
            }
            count = found? count:0;
            result.push_back(count);
        }
        result.push_back(0);
        return result;
    }
};
