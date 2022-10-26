class Solution {
public:
    int divide(int dividend, int divisor) {
        
        if(dividend == divisor) return 1;
        bool pos = (dividend>=0 == divisor >=0)? true:false;
        
        unsigned int ans = 0;
        unsigned int a = abs(dividend);
        unsigned int b = abs(divisor);
        while(a >= b)
        {
            int cnt = 0;
            while( a > (b <<  (cnt+1))) cnt++;            
            ans += (1 << cnt);
            a -= (b << cnt);
        }        
        if(ans == (1<<31) && pos) return INT_MAX;
        return pos? ans: -ans;
    }
};
