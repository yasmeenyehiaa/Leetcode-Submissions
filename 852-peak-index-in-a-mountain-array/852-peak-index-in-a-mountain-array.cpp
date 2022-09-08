class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int n = arr.size(), l = 0, r = n-1;
        while(l <= r)
        {
            int m = (l+r)/2;
            if(arr[m] > arr[m+1])
            {
                r = m-1;
            }
            else
            {
                l = m+1;
            }
        }
        return l;
        
    }
};