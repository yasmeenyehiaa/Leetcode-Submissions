class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
        
        int  mx = 0, l = 0, n = arr.size(), cur = 0;
        for(int r=0; r<n; r++)
        {
          if(arr[r] == 1) cur++; 
          while(r-l+1-cur > k)
          {
            if(arr[l] == 1) cur--;
            l++; 
          }
          mx = max(mx, r-l+1);
        }
        return mx;        
    }
};