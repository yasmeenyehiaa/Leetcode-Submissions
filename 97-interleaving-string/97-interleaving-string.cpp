class Solution {
public:
    int n,m, dp[205][105][105];
    string v1, v2, v3;
    bool solve(int i, int p1, int p2, string ans)
    {
        if(dp[i][p1][p2] != -1) return dp[i][p1][p2];
        if(ans == v3 && p1 == n && p2 == m) return true;
        bool ok = 0;
        if(p1 < n && v1[p1] == v3[p1+p2])
        {
            ok |= solve(i+1, p1+1, p2, ans+v3[p1+p2]);
        }
        if(p2 < m && v2[p2] == v3[p1+p2])
        {
            ok |= solve(i+1, p1, p2+1, ans+v3[p1+p2]);
        }
        
        return dp[i][p1][p2] = ok;
    }
    bool isInterleave(string s1, string s2, string s3) {
        
        n = s1.size(), m = s2.size();
        v1 = s1, v2 = s2, v3 = s3;
        memset(dp, -1, sizeof dp);
        return solve(0,0,0, "");
    }
};