class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        //BRUTE FORCE
        int maxVol = 0;
        for(int i=0; i<heights.size();i++)
        {
            int botNeck = heights[i];
            if(heights[i] > maxVol)
            {
                maxVol = heights[i];
            }
            for(int j=i+1; j<heights.size(); j++)
            {
                if(heights[j] <  botNeck)
                {
                    botNeck = heights[j];
                }
                int width = j-i+1;
                int vol = botNeck * width;
                if(vol > maxVol)
                {
                    maxVol = vol;
                }
            }
        }
        return maxVol;
    }
};
