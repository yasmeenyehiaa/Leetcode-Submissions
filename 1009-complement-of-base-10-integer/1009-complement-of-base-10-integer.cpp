class Solution {
public:
    int bitwiseComplement(int num) {
        
        int n = num, numBits = 0;
        if(num == 0) return 1;
        while(n > 0) 
        {
            numBits++;
            n = n >> 1;
        }
        int allBits = pow(2, numBits) - 1;
        return num ^ allBits;
    }
};