class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        vector<string> ans;
        int universal[30] = {0};
        for(auto w: words2)
        {
            int frq[30] = {0};
            for(auto c:w)
            {
                frq[c-'a']++;
                universal[c-'a'] = max(frq[c-'a'], universal[c-'a']);
            }
        }
        for(auto w: words1)
        {
            int frq[30] = {0};
            bool ok = 1;
            for(auto c:w)
            {
                frq[c-'a']++;
            }
            for(int i=0; i<26; i++)
            {
                if(frq[i] < universal[i]) 
                {
                    ok = 0;
                    break;
                }
            }
            if(ok) 
            {
                ans.push_back(w);
            }
        }
        return ans;
    }
};