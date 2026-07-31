class Solution {
public:
    int getSum(int a, int b) 
    {
        int result =0;
        int cIN = 0;
        //SUM = A ^ B ^ Cin
        //CARRY = A&B | B&Cin | Cin&A
        for(int i=0;i <32;i++)
        {
            int aIN = (a >> i) & 0x1;
            int bIN = (b >> i) & 0x1;

            int sum = aIN ^ bIN ^ cIN;
            cIN =  (aIN & bIN) | (bIN & cIN) | (aIN & cIN);

            if(sum)
            {
                result |= (0x1<<i);
            }
        }
        return result;
    }
};
