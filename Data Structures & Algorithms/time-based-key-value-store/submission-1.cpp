class TimeMap {
    unordered_map<string, vector<pair<int,string>>> map;
public:
    TimeMap() 
    {
        
    }
    
    void set(string key, string value, int timestamp) 
    {
        map[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) 
    {
        vector<pair<int,string>>& lookUp = map[key];
        if(lookUp.empty())
        {
            return "";
        }
        int leftLimit = 0;
        int rightLimit = lookUp.size()-1;
        int probIdx = -1;

        while(leftLimit <= rightLimit)
        {
            int mid = leftLimit + (rightLimit-leftLimit)/2;
            if(lookUp[mid].first <= timestamp)
            {
                leftLimit = mid+1;
                probIdx = mid;
            }
            else
            {
                rightLimit = mid-1;
            }
        }

        if(probIdx == -1)
        {
            return "";
        }
        return lookUp[probIdx].second;
    }
};
