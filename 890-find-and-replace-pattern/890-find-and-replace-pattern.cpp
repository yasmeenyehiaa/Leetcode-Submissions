class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(auto w: words)
        {
            if(w.size() != pattern.size()) continue;
            map<char,char> mp;
            bool ok = 1;
            int i = 0;
            for(auto ch: w)
            {
                if(mp[pattern[i]])
                {
                    ok = ok && (ch == mp[pattern[i]]);
                }
                else
                {
                    mp[pattern[i]] = ch;
                }
                i++;
            }
            bool vis[28] = {0};
            for(auto p: mp)
            {
                char ch = p.second;
                if(vis[ch - 'a']) 
                {
                    ok = 0; 
                    break;
                }
                vis[ch - 'a'] = 1;
            }
            if(ok) ans.push_back(w);
        }
        return ans;
    }
};