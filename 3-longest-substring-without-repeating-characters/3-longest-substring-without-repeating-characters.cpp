class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.size(), r = 0, ans = 0;
        map<char,int> mp;
        
        for(int l=0; l<n; l++)
        {
            //mp[s[l]]++;
            while(r<n && !mp[s[r]])
            {
                mp[s[r]]++;
                r++;
            }            
            ans = max(ans, r-l);
            mp[s[l]]--;
        }
        
        return ans;
    }
};