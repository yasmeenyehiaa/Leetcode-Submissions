class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int> v;
        for(auto el: nums)
        {
            if(!v.size() || el > v.back())
            {
                v.push_back(el);
            }
            else
            {
                auto it = lower_bound(v.begin(), v.end(), el);
                *it = el;
            }
        }
        return v.size();
    }
};