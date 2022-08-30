class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n = nums.size(), i = 0;
        // Cyclic sort: O(n)
        while(i < n)
        {
            int j = nums[i];
            if(nums[i] < n && nums[i] != nums[j])
            {
                swap(nums[i], nums[j]);
            }
            else i++;
        }
        for(int i=0; i<n; i++)
        {
            if(i != nums[i]) return i;
        }
        return n;        
    }
};