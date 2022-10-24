class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        int dup, missing = 1;
        for(auto n: nums)
        {
            if(nums[abs(n)-1] < 0) dup = abs(n); //if visited
            else nums[abs(n)-1] *= -1;       // mark as visited
        }
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i] > 0) missing = i+1;
        }
        return {dup, missing};        
    }
};