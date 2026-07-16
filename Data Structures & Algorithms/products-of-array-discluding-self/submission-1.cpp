class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        unsigned inputVecSize = nums.size();
        vector<int> prefixProd(inputVecSize);
        vector<int> suffixProd(inputVecSize);
        vector<int> resultProd(inputVecSize);

        prefixProd[0] = 1;
        suffixProd[inputVecSize-1] = 1;

        for(int i=1 ;i<inputVecSize; i++)
        {
            prefixProd[i] = prefixProd[i-1] * nums[i-1];
        }

        for(int i= inputVecSize-2; i>=0; i--)
        {
            suffixProd[i] = suffixProd[i+1] * nums[i+1];
        }

        for(int i=0 ;i<inputVecSize; i++)
        {
            resultProd[i] = prefixProd[i] *  suffixProd[i];
        }

        return resultProd;

    }
};
