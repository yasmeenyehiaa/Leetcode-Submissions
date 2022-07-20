class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        map<char, vector<int>> mp;
        for(int i=0; i<s.size(); i++)
        {
            mp[s[i]].push_back(i);
        }
        int ans = 0;
        for(auto w: words)
        {
            int lst =-1, f = 1;
            for(int i=0; i<w.size(); i++)
            {
                auto it = upper_bound(mp[w[i]].begin(), mp[w[i]].end(), lst);
                if(it != mp[w[i]].end())
                {
                    int tmp = it - mp[w[i]].begin();
                    lst = mp[w[i]][tmp];                 
                }
                else f = 0;
            }
            if(f)ans++;
        }
        return ans;
    }    
};