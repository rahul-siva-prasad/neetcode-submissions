class Solution {
public:
    int trap(vector<int>& height)
    {
        int size = height.size();
        if(size == 0)
        {
            return 0;
        }
        int vol=0;

        for(int i=0; i< size;i++)
        {
            int leftMax = height[i];
            int rightMax = height[i];

            for(int j=0; j<i; j++)
            {
                leftMax = max(leftMax, height[j]);
            }

            for(int j=i+1; j<size;j++)
            {
                rightMax = max(rightMax, height[j]);
            }

            vol += min(leftMax, rightMax) - height[i];
        }
        return vol;
    }
};
