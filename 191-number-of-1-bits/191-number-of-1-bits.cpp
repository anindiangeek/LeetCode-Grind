class Solution {
public:
    int hammingWeight(uint32_t n) {
         int setBitCount = 0;
        
        while (n) {
            n &= (n - 1); 
            ++setBitCount;
        }
        
        return setBitCount;
        
    }
};