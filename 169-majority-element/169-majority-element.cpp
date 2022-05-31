class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int mx, ok = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(ok == 0)
            {
                ok++; 
                mx = nums[i];
            }
            else
            {
                if(nums[i] == mx) ok++;
                else ok--;
            }
        }
        return mx;
    }
};