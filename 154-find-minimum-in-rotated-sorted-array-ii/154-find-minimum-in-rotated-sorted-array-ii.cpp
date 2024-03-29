class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        while(l < r)
        {
            int m = (l+r)/2;
            if(nums[m] > nums[r])
            {
                l = m+1;
            }
            else if(nums[m] < nums[r])
            {
                r = m;
            }
            else // nums[m] = nums[l] = nums[r] -> skip this part
            {
                r--;
            }
        }
        return nums[r];        
    }
};