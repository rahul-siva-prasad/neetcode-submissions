class Solution {
public:
    int maxArea(vector<int>& heights) 
    {
        int maxVol = 0;
        int leftPtr = 0;
        int rightPtr = heights.size()-1;
        int arrSize = heights.size();

        while(leftPtr < rightPtr)
        {
            int leftHeight = heights[leftPtr];
            int rightHeight = heights[rightPtr];
            int currVol = min(leftHeight, rightHeight) * (rightPtr - leftPtr);

            if(currVol > maxVol)
            {
                maxVol = currVol;
            }

            if(leftHeight < rightHeight)
            {
                leftPtr++;
            }
            else
            {
                rightPtr--;
            }
        }

        return maxVol;
    }
};
