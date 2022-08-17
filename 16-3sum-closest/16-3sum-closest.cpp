class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = 1e5;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-2; i++)
        {
            int p1 = i+1, p2 = n-1;
            while(p1 < p2)
            {
                int val = nums[i] + nums[p1] + nums[p2];
                if(val == target)
                {
                    return target;
                }
                else if(val > target) 
                {
                    if(val-target < abs(target-ans)) ans = val;
                    p2--;
                }
                else 
                {
                    if(target-val < abs(target-ans)) ans = val;
                    p1++;   
                }
            }
        }        
        return ans;
    }
};

