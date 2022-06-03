class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int n = nums.size(), j = 0, k = n-1;
        for(int i=0; i<n; i++)
        {
            if(nums[i] != 0)
            {                
                nums[j++] = nums[i];
            }
        }
        for(; j<n; j++)
        {
            nums[j] = 0;
        }
    }
};