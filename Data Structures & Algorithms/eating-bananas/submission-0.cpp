class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        //Identify lower and upper bound for rate;
        //Lower bound = sum of elements of array/ h
        //Max bound = max(elm)

        int lowerBound = 0;
        int upperBound = 0;
        int sum = 0;
        int size = piles.size();
        int minTime = 0;

        for(int num: piles)
        {
            if(num> upperBound)
            {
                upperBound = num;
            }
            sum += num;
        }
        lowerBound = 1;

        while(lowerBound <= upperBound)
        {
            int mid = lowerBound + (upperBound-lowerBound)/2;
            int timeTaken = 0;
            for(int i=0;i<size;i++)
            {
                timeTaken += (piles[i] + mid -1)/mid;
            }

            if(timeTaken > h)
            {
                lowerBound = mid+1;
            }
            else
            {
                minTime = mid;
                upperBound = mid-1;
            }
        }
        return minTime;
        
    }
};
