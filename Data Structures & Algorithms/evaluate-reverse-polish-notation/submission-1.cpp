class Solution {
    enum E_OPERATOR{ADD, SUBTRACT, MULTIPLY, DIVIDE};
public:
    int evalRPN(vector<string>& tokens) 
    {
        stack<int> numStk;
        unordered_map<string,E_OPERATOR> operatorMatch =
        {
            {"+", ADD},
            {"-", SUBTRACT},
            {"*", MULTIPLY},
            {"/", DIVIDE}
        };

        for(string token: tokens)
        {
            if(token != "+" && token != "-" && token != "*" && token != "/")
            {
                int num = stoi(token);
                numStk.push(num);
            }
            else
            {
                int oper1, oper2, result;
                oper2= numStk.top();
                numStk.pop();
                oper1 = numStk.top();
                numStk.pop();

                switch(operatorMatch[token])
                {
                    case ADD: result = oper1 + oper2; numStk.push(result); break;
                    case SUBTRACT: result = oper1 - oper2; numStk.push(result); break;
                    case MULTIPLY: result = oper1 * oper2; numStk.push(result); break;
                    case DIVIDE: result = oper1 / oper2; numStk.push(result); break;
                    default: break;
                }
            }
        }
        return numStk.top();
    }
};
