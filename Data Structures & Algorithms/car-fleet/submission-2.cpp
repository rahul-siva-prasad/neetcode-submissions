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

        double prevTimeTaken = (double)(target - carVec[0].first) / carVec[0].second;
        int fleets = 1;

        for(int i=1; i<carVec.size();i++)
        {
            double timeTaken = (double)(target - carVec[i].first) / carVec[i].second;
            if(timeTaken > prevTimeTaken)
            {
                fleets +=1;
                prevTimeTaken = timeTaken;
            }
        }
        return fleets;
    }
};
