class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        
        if(nums.size() < 2)
        {
            return nums.size();
        }
        
        int prv = nums[1] - nums[0], mx = 1;
        if(prv != 0) mx++;
        for(int i=2; i<nums.size(); i++)
        {
            int d = nums[i] - nums[i-1];
            if(d<0 && prv >=0 || d>0 && prv <= 0) 
            {
                mx++;
                prv = d;
            }
        }
        return mx;        
    }
};