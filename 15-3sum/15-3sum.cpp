class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        set<vector<int>> st;
        for(int i=0; i<n-2; i++)
        {
            int t = nums[i];
            int p1 = i+1, p2 = n-1;
            while(p1 < p2)
            {
                if(nums[p1] + nums[p2] + t == 0)
                {
                    st.insert({nums[i], nums[p1], nums[p2]});
                    p1++;
                    p2--;
                }
                else if(nums[p1] + nums[p2] + t > 0) p2--;
                else p1++;                
            }
        }
        for(auto a: st) ans.push_back(a);
        return ans;
    }
};