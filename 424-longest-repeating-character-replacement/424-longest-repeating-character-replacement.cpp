class Solution {
public:
    int characterReplacement(string s, int k) {
        
    int mx = 0, n = s.size(), l = 0, ans = 0;
    unordered_map<char,int> cnt;
    for(int r=0; r<n; r++)
    {
      cnt[s[r]]++;
      mx = max(mx, cnt[s[r]]);
      while(l<n && r-l+1-mx > k)
      { 
        cnt[s[l]]--;
        l++;
      }
      ans = max(ans, r-l+1);
    }
    return ans;
        
    }
};