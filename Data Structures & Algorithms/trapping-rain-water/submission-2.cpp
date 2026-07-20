class Solution {
public:
    int trap(vector<int>& height)
    {
        int size = height.size();
        if(size == 0)
        {
            return 0;
        }

        int leftPtr = 0;
        int rightPtr = size-1;
        int leftMax = height[leftPtr];
        int rightMax = height[rightPtr];
        int result=0;

        while(leftPtr < rightPtr)
        {
            if(leftMax < rightMax)
            {
                leftPtr+=1;
                leftMax = max(leftMax, height[leftPtr]);
                //water above bar
                result += leftMax - height[leftPtr];
            }
            else
            {
                rightPtr -=1;
                rightMax = max(rightMax , height[rightPtr]);
                //water above bar
                result += rightMax - height[rightPtr];
            }   
        }
        return result;
    }
};
