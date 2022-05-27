class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int n = nums.size();
        map<int,int> vis;
        for(int i=0; i<n; i++)
        {
            vis[nums[i]]++;
        }
        for(auto p: vis)
        {
            if(p.second == 1)
            {
                return p.first;
            }
        }
        return  nums[n-1];
    }
};