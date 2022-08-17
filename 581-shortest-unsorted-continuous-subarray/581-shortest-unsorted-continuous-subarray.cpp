class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size(), l = 0, h = n-1;
        while(l<n-1 && nums[l] <= nums[l+1]) l++;
        if(l == n-1) return 0;
        while(h>0 && nums[h] >= nums[h-1]) h--;
        int mn = 1e9, mx = -1e9;
        for(int i=l; i<=h; i++)
        {
            mx = max(mx, nums[i]);
            mn = min(mn, nums[i]);
        }
        while(l>0 && nums[l-1] > mn) l--;
        while(h<n-1 && nums[h+1] < mx) h++;
        
        return (h-l)+1;
    }
};