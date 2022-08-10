class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
     
        if( find(deadends.begin(),deadends.end(), "0000") != deadends.end()) return -1;
        queue<string> q;
        q.push("0000");
        int ans = 0;
        map<string, int> mp;
        while(!q.empty())
        {
            ans++;
            int sz = q.size();
            while(sz--)
            {
                string s = q.front();
                q.pop();
                if(s == target) return ans-1;
                for(int i=0; i<4; i++)
                {
                    string tmp = s;
                    if(s[i] < '9')tmp[i] = s[i] + 1;
                    else tmp[i] = '0';
                    if(mp.count(tmp) == 0 && find(deadends.begin(),deadends.end(), tmp) == deadends.end())
                    {
                        mp[tmp] = 1;
                        q.push(tmp);
                    }
                    tmp = s;
                    if(s[i] > '0')tmp[i] = s[i] - 1;
                    else tmp[i] = '9';
                    if(mp.count(tmp) == 0 && find(deadends.begin(),deadends.end(), tmp) == deadends.end())
                    {
                        mp[tmp] = 1;
                        q.push(tmp);
                    }
                }
            }
        }
        return -1;
    }
};