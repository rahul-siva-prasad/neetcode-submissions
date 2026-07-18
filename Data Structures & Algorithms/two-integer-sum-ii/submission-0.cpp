class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int leftPtr = 0;
        int rightPtr = numbers.size()-1;
        vector<int> result;

        while(leftPtr < rightPtr)
        {
            int sum = numbers[leftPtr] + numbers[rightPtr];
            if(sum < target)
            {
                leftPtr++;
            }
            else if(sum > target)
            {
                rightPtr--;
            }
            else
            {
                result.push_back(leftPtr+1);
                result.push_back(rightPtr+1);
                return result;
            }
        }
        return result;
    }
};
