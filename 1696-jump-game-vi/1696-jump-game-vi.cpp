class Solution {
public:    
    int maxResult(vector<int>& nums, int k) 
    {
        int n = nums.size();
        multiset<int, greater<int>> s;
        for(int i=0; i<n; i++)
        {
            int val = s.size() == 0? 0 : *s.begin();
            nums[i] += val;
            s.insert(nums[i]);
            if(s.size() > k) s.erase(s.find(nums[i-k]));
        }
        return nums[n-1];
    }
};