class Solution {
public:
    int vis[15];
    bool can(string s1, string s2)
    {
        int ctr = 0;
        for(int i=0; i<8; i++) ctr += (s1[i] != s2[i]);
        return ctr == 1;
    }
    int minMutation(string start, string end, vector<string>& bank) {
        int ans = 0, n = bank.size();
        queue<string> q;
        q.push(start);
        while(!q.empty())
        {
            ans++;
            int sz = q.size();
            while(sz--)
            {
                string s = q.front(); q.pop();
                if(s == end) return ans-1;
                for(int i=0; i<n; i++)
                {
                    if(!vis[i] && can(s, bank[i]))
                    {
                        q.push(bank[i]);
                        vis[i] = 1;
                    }
                }
            }
        }
        return -1;
        
    }
};