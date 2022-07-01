class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int tmp = 0, mx = 0;
        map<int,int> cnt;
        for(int i=0; i<nums.size(); i++)
        {
            cnt[nums[i]]++;
        }
        
        for(auto p: cnt)
        {
            int n = p.first;
            if(!cnt[n-1])
            {
                tmp = 1;
                int x = n;
                while(cnt[++x])
                {
                    tmp++;
                }
            }
            mx = max(mx, tmp);            
        }
        return mx;
    }
};