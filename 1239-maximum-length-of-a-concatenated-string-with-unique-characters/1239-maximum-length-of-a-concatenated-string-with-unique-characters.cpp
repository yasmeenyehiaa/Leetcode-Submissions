class Solution {
public:
    int ans = 0;
    bool is_unique(string s)
    {
        map<char, int> cnt;
        for(auto ch: s)
        {
            if(cnt[ch] > 0) return false;
            cnt[ch]++;
        }
        return true;
    }
    void solve(vector<string>& arr, int i, int n, string s)
    {
        if(!is_unique(s)) return;
        if(i == n)  // change
        {
            ans = max(ans, (int)s.size());
            return;
        }
        
        solve(arr, i+1, n, s+arr[i]);
        solve(arr, i+1, n, s);
    }
    int maxLength(vector<string>& arr) {
        
        int n = arr.size();
        solve(arr, 0, n, "");
        return ans;
    }
};