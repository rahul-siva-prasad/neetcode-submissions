class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        //Fix X and check if value can lie inside current row
        //If X is found, apply bin search for Y coord;

        int rows = matrix.size();
        int cols = matrix[0].size();

        int xLoc = -1;
        for(int x=0; x<rows; x++)
        {
            int leftPtr = 0;
            int rightPtr = cols-1;
            int leftLimit = matrix[x][leftPtr];
            int rightLimit = matrix[x][rightPtr];

            if(target == leftLimit || target == rightLimit)
            {
                return true;
            }

            if(target> leftLimit && target < rightLimit)
            {
                xLoc = x;
                break;
            }
        }

        if(xLoc == -1)
        {
            return false;
        }

        int left = 0;
        int right = cols-1;
        while(left<=right)
        {
            int mid = left + (right-left)/2;
            int elm = matrix[xLoc][mid];
            if(elm == target)
            {
                return true;
            }
            
            if(elm < target)
            {
                left = mid+1;
            }
            else
            {
                right = mid -1;
            }
        }
        return false;
    }
};
