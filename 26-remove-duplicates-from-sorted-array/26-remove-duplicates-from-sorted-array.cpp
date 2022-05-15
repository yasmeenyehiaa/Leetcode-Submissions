class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cur = 1;
        
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i] != nums[i-1])
            {
                nums[cur++] = nums[i];
            }
        }
        
        return cur;
    }
};