class Solution {
public:
    string longestPalindrome(string s) {
        
        if(!s.size()) return "";
        int n = s.size(), l = 0, len = 1;
        
        vector<vector<bool>> dp(n, vector<bool> (n,0));
        for(int i=0; i<n; i++)
        {
            dp[i][i] = 1;
            for(int j=0; j<i; j++)
            {
                dp[j][i] = (s[i]==s[j] && (i== j+1 || dp[j+1][i-1]));
                if(dp[j][i] && i-j+1 > len)
                {
                    len = (i-j+1);
                    l = j;
                }
            }
        }
        
        return s.substr(l, len);
        
    }
};