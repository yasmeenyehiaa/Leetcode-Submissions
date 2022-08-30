class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int i=0, n = nums.size();
        while(i < n)
        {
              if(nums[i] < 0 || nums[i] > n) 
              {
                  i++;
                  continue;
              }
              int j = nums[i] - 1;
              if(nums[i] > 0 && nums[i] <=n && nums[i] != nums[j])
              {
                swap(nums[i], nums[j]);
              }
              else i++;
        }
        for(int i=0; i<n; i++)
        {
              if(nums[i] != i+1) 
              {
                return i+1;
              }
        }
        return n+1;   
    }
};