class Solution {
    bool f_validateChar(char ch)
    {
        if( ch>='A' && ch <= 'Z' || 
            ch>='a' && ch <= 'z' ||
            ch>='0' && ch <= '9')
        {
            return true;
        }
        return false;
    }
public:
    bool isPalindrome(string s) 
    {
        int leftPtr=0;
        int rightPtr = s.length()-1;

        while(leftPtr < rightPtr)
        {
            char ch1=s[leftPtr];
            char ch2=s[rightPtr];
            while(!f_validateChar(ch1) && leftPtr < rightPtr)
            {
                ch1=s[++leftPtr];
            }
            while(!f_validateChar(ch2) && leftPtr < rightPtr)
            {
                ch2=s[--rightPtr];
            }
            if(tolower(ch1) != tolower(ch2))
            {
                return false;
            }
            leftPtr++;
            rightPtr--;
        }
        return true;
        
    }
};
