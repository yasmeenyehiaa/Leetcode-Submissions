class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        int i=0, n = nums.size();
        vector<int> ans;
        while(i<n)
        {
          int j = nums[i] - 1;
          if(nums[i] != nums[j])
          {
            swap(nums[i], nums[j]);
          }
          else i++;
        }
        for(int i=0; i<n; i++)
        {
          if(nums[i] != i+1) ans.push_back(nums[i]);
        }
        return ans;   
    }
};