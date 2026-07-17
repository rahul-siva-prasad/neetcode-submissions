class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) 
    {
        vector<pair<int,int>> carVec;
        for(int i=0 ;i<position.size(); i++)
        {
            carVec.push_back({position[i], speed[i]});
        }

        sort(carVec.rbegin(), carVec.rend());

        stack<double> stk;

        for(int i=0 ;i<carVec.size(); i++)
        {
            double timeTaken = (double)(target - carVec[i].first) / carVec[i].second;
            if(!stk.empty())
            {
                if(timeTaken > stk.top())
                {
                    stk.push(timeTaken);
                }
            }
            else
            {
                stk.push(timeTaken);
            }
        }
        return stk.size();
    }
};
