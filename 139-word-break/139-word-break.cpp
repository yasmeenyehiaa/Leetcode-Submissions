class Solution {
public:
    string str;
    int n, dp[305];
    bool solve(int idx, vector<string> wordDict)
    {
        if(idx == n) return true;
        if(dp[idx] != -1) return dp[idx];
        for(int i=idx; i<n; i++)
        {
            string tmp = str.substr(idx, i-idx+1);
            if(find(wordDict.begin(), wordDict.end(), tmp) != wordDict.end() && solve(i+1, wordDict))
                return dp[idx] = true;
        }
        return dp[idx] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        memset(dp, -1, sizeof dp);
        str  = s;
        return solve(0, wordDict);
    }
};