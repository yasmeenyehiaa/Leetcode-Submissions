class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int l = 0, r = nums.size(), ans;
        if(target < nums[0]) 
        {
            return 0;
        }
        else if(target > nums[r-1])
        {
            return r;
        }
      
        while(l+1 < r)
        {
            int mid = (l+r)/2;
            if(nums[mid] <= target)
            {
                ans = mid;
                l = mid;
            }
            else r = mid;
        }
        
        if(nums[ans] == target)
        {
            return ans;
        }
        return ans+1;
    }
};