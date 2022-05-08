class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        vector<int> ret;
        map<int,int> mp;
        for(int i=0; i<n; i++)
        {
            mp[nums[i]] = i;
        }
        for(int i=0; i<n; i++)
        {
            int rem = target - nums[i];
            if(mp[rem] && mp[rem] != i)
            {
                ret.push_back(i);
                ret.push_back(mp[rem]);
                break;
            }
        }
        return ret;
    }
    
};