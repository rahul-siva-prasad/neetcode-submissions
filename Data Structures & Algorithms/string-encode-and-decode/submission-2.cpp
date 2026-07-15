class Solution {
public:

    string encode(vector<string>& strs) 
    {
        string encodeString;

        for(string str: strs)
        {
            unsigned len = str.length();
            encodeString += to_string(len) +"#";
            encodeString +=str;
        }
        return encodeString;
    }

    vector<string> decode(string s) 
    {
        vector<string>result;

        int strLength=0;
        for(unsigned i=0 ;i<s.length();)
        {
            if(s[i] != '#')
            {
                strLength = strLength*10 + (s[i] - '0');
                i++;
            }
            else
            {
                if(strLength == 0)
                {
                    result.push_back("");
                    i++;
                    continue;
                }
                string decodeString;
                unsigned j;
                for(j= i+1; j<i+strLength+1; j++)
                {
                    decodeString += s[j];
                }
                result.push_back(decodeString);
                strLength=0;
                i= j;
            }
        }
        return result;
    }
};
