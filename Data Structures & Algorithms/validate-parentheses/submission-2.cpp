class Solution {
    bool f_isPair(char openParanth, char closeParanth)
    {
        if(openParanth == '(' && closeParanth == ')')
        {
            return true;
        }

        if(openParanth == '{' && closeParanth == '}')
        {
            return true;
        }

        if(openParanth == '[' && closeParanth == ']')
        {
            return true;
        }
        return false;
    }
public:
    bool isValid(string s) 
    {
        stack<char> paranthStk;
        for(char ch: s)
        {
            if(ch == '(' || ch == '{' || ch == '[')
            {
                paranthStk.push(ch);
            }
            else if(ch == ')' || ch == '}' || ch == ']')
            {
                if(paranthStk.empty())
                {
                    return false;
                }
                char openParanth = paranthStk.top();
                if(!f_isPair(openParanth, ch))
                {
                    return false;
                }
                paranthStk.pop();
            }
        }
        return paranthStk.empty();
    }
};
