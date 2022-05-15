class Solution {
public:
    int mySqrt(int x) {
        
        int ans, l = 0, r = x; 
        if(x<=1)
        {
            return x;
        }
        while(l<=r)
        {
            int mid = (l+r)/2;
            
            if(x/mid == mid)
            {
                return mid;
            }
            if(mid < x/mid)
            {
                l = mid+1;
                ans = mid;
            }
            else r = mid-1;
        }    
        return ans;
    }
};