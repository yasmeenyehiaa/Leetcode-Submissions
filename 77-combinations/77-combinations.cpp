class Solution {
public:
    int n;
    vector<vector<int>> ans;
    void solve(int i, int k, vector<int> v)
    {
        if(k == 0) 
        {
            ans.push_back(v);
            return;
        }
        for(int j=i; j<=n; j++)
        {
            v.push_back(j);
            solve(j+1, k-1, v);
            v.pop_back();
        }
    }
    vector<vector<int>> combine(int nn, int k) {
        n = nn;
        solve(1, k, {});
        return ans;
    }
};