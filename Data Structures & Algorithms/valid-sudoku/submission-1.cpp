class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        for(unsigned row=0 ;row<9 ;row++)
        {
            unordered_set<int> seenValue;
            for(unsigned col=0; col<9; col++)
            {
                char elm= board[row][col];
                if(elm == '.')
                {
                    continue;
                }

                if(seenValue.count(elm))
                {
                    return false;
                }
                seenValue.insert(elm);
            }
        }

        for(unsigned col=0 ;col<9 ;col++)
        {
            unordered_set<int> seenValue;
            for(unsigned row=0; row<9; row++)
            {
                char elm= board[row][col];
                if(elm == '.')
                {
                    continue;
                }

                if(seenValue.count(elm))
                {
                    return false;
                }
                seenValue.insert(elm);
            }
        }

        for(unsigned square=0 ;square<9 ;square++)
        {
            unordered_set<int> seenValue;
            for(unsigned row=0; row<3; row++)
            {
                for(unsigned col=0; col<3; col++)
                {
                    unsigned boardRow = (square/3)*3 + row;
                    unsigned boardCol = (square%3)*3 + col;
                    char elm= board[boardRow][boardCol];
                    if(elm == '.')
                    {
                        continue;
                    }

                    if(seenValue.count(elm))
                    {
                        return false;
                    }
                    seenValue.insert(elm);
                }
            }
        }

        return true;
         
    }
};
