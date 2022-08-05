class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        vector<int> v;
        map<int,int> cnt;
        for(int i=0; i<nums.size(); i++)
        {
            cnt[nums[i]*nums[i]]++;
        }
        for(auto p: cnt)
        {
            int x = p.first, y = p.second;
            while(y--)
            {
                v.push_back(x);
            }
        }
        return v;        
    }
};