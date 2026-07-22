class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        //Flattern 2D array;
        int rows = matrix.size();
        int cols = matrix[0].size();
        //SQUARE MATRIX -> TOTAL cells = rows * col;

        int cellCount = rows * cols;
        int left = 0;
        int right = cellCount-1;

        while(left <= right)
        {
            int mid = left + (right-left)/2;
            int row = mid/cols;
            int col = mid%cols;
            int currElm = matrix[row][col];

            if(currElm == target)
            {
                return true;
            }
            else if (currElm > target)
            {
                right = mid-1;
            }
            else
            {
                left = mid +1;
            }
        }
        return false;
        
    }
};
