class Solution {
public:
    int trap(vector<int>& height)
    {
        int waterTrapped = 0;
        int size = height.size();
        vector<int> prefixMax(size);
        vector<int> suffixMax(size);

        prefixMax[0] = height[0];
        suffixMax[size-1] = height[size-1];

        for(int i=1; i<size;i++)
        {
            prefixMax[i] = max(height[i], prefixMax[i-1]);
        }

        for(int i= size-2; i>=0; i--)
        {
            suffixMax[i] = max(height[i], suffixMax[i+1]);
        }

        for(int i=0; i<size; i++)
        {
            waterTrapped += min(prefixMax[i], suffixMax[i]) - height[i];
        }
        return waterTrapped;
    }
};
