class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        if(nums.size() == 0)
        {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }        
        
        int n = nums.size(), l = 0, r = n-1, a1 = -1, a2 = -1;
        while(l <= r)
        {
            int m = (l+r)/2;
            if(nums[m] == target)
            {
                a1 = m;
                r = m-1;
            }
            else if(nums[m] < target) l = m+1;
            else r = m-1;
        }
        l = 0, r = n-1;
        while(l <= r)
        {
            int m = (l+r)/2;
            if(nums[m] == target)
            {
                a2 = m;
                l = m+1;
            }
            else if(nums[m] < target) l = m+1;
            else r = m-1;
        }
        ans.push_back(a1);
        ans.push_back(a2);
        return ans;
    }
};