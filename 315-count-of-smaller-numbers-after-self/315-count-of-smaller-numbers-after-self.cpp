class Solution {
public:
    int tree[400020];
    void update(int i, int x, int lx, int rx)
    {
        if(lx == rx)
        {
            tree[i] = 1;
            return;
        }
        int m = (lx+rx)/2;
        if(lx <= x && x <= m) update(2*i, x, lx, m);
        else update(2*i+1, x, m+1, rx);
        tree[i] = tree[2*i]+tree[2*i+1];
    }
    int query(int x, int st, int ed, int lx, int rx)
    {
        if(st>rx || ed<lx || lx>rx) return 0;
        if(st<=lx && ed>=rx) return tree[x];
        int m = (lx+rx)/2;
        int l = query(2*x, st, ed, lx, m);
        int r = query(2*x+1, st, ed, m+1, rx);
        return l+r;
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int,int>> vec;
        vector<int> ans(nums.size());
        for(int i=1; i<=nums.size(); i++) vec.push_back({nums[i-1], i});
        sort(vec.begin(), vec.end());
        for(int i=0; i<vec.size(); i++)
        {
            int v = query(1,vec[i].second, nums.size(),1, nums.size());
            ans[vec[i].second-1] = v;
            update(1, vec[i].second, 1, nums.size());
        }
        return ans;
    }
};