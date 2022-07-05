class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() <= 1) 
        {
            return nums.size();
        }
        int ans = 1;
        map<int,int> frq;
        
        for(int i=0; i<nums.size(); i++)
        {
            frq[nums[i]]++;
        }
        
        for(auto p: frq)
        {
            int tmp = 1, el = p.first;
            if(frq[el-1]) continue;
            while(frq[el+1]) {
                tmp++;
                el++;
            }
            ans = max(ans, tmp);            
        }
        return ans;
    }
};