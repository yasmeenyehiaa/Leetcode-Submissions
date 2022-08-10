class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        int ans = 0;
        queue<int> q;
        q.push(0);
        set<int> visited(forbidden.begin(),forbidden.end());
        while(!q.empty())
        {
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                
                int cur = q.front();
                q.pop();
                bool wasBack = (cur < 0);
                cur = abs(cur);
                
                if(cur == x) return ans; 
                
                int nxt = cur + a;
                
                if(nxt < 10000 && visited.find(nxt) == visited.end()){
                    visited.insert(nxt);
                    q.push(nxt);
                }
                
                nxt = cur - b;
                if(!wasBack && nxt > 0 && visited.find(nxt) == visited.end()){
                    q.push(nxt * -1);
                }
            }
            ans++;
        }
        return -1;
    }
};