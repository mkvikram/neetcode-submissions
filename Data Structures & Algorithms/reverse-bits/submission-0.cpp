class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans=0;
        int t=0;
        int i=0;
        while(i<32)
        {
           t=n&1;
           ans=ans<<1;
           ans=ans|t;
           n=n>>1;
           i++;
        }
        return ans;
    }
    
};
