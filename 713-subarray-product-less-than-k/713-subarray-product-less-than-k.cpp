class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& arr, int k) {
        
        int l = 0, n =arr.size(), pro = 1, ans = 0;
        if(k <= 1) return 0;
        for(int r=0; r<n; r++)
        {
            pro *= arr[r];
            while(pro>=k)
            {
                pro/=arr[l++];            
            }
            ans += (r-l+1);
        }
        return ans;        
        }
};