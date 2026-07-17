class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        vector<int> result (temperatures.size(),0);
        stack<pair<int,int>> waitingForWarm;

        for(int i=0; i< temperatures.size(); i++)
        {
            if(!waitingForWarm.empty())
            {
                while(!waitingForWarm.empty() && (temperatures[i] > waitingForWarm.top().first))
                {
                    result[waitingForWarm.top().second] = i - waitingForWarm.top().second;
                    waitingForWarm.pop();
                }
            }
            waitingForWarm.push({temperatures[i],i});
        }
        return result;
        
    }
};
