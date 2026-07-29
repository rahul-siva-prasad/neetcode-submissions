class Solution {
public:
    uint32_t reverseBits(uint32_t n) 
    {
        uint32_t result = 0;
        int idx = 31;
        while(n)
        {
            if(n&0x1)
            {
                result |= 1<<idx;
            }
            idx--;
            n >>=1;
        }   
        return result;
    }
};
