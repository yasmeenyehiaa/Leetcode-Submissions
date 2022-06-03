class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int n = nums.size();
        for(int i=0; i<n-1; i++)
        {
            if(nums[i] == 0)
            {
                int j = i;
                while(j<n && nums[j] == 0)
                {
                    j++;
                }
                
                if(j == n)
                {
                    break;
                }
                nums[i] = nums[j];
                nums[j] = 0;
            }
        }
    }
};