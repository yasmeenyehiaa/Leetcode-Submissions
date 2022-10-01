class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size()-1, ans = INT_MAX;
        
        while(l < r)
        {
            int m = (l+r)/2;
            if(nums[m] > nums[r]) 
            {
                l = m+1;
            }
            else 
            {
                r = m;
            }
        }
        return nums[l];
    }
};
// TC: O(log(n))
// SC: O(1)