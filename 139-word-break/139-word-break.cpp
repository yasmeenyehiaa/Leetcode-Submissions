class Solution {
public:
    int n, dp[305];
    string str;
    bool solve(int idx, set<string> wordDict)
    {
        if(idx == n) return true;
        if(dp[idx] != -1) return dp[idx];
        for(int i=idx; i<n; i++)
        {
            string tmp = str.substr(idx, i-idx+1);
            if(wordDict.count(tmp) && solve(i+1, wordDict))
                return dp[idx] = true;
        }
        return dp[idx] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        str  = s;
        set<string> st;
        for(auto w: wordDict) st.insert(w);
        memset(dp, -1, sizeof dp);
        return solve(0, st);
    }
};