class Solution {
public:
    int par[100005], sz[100005];
    int get(int a)
    {
        if(a == par[a]) return par[a] = a;
        return par[a] = get(par[a]);
    }
    void Union(int a, int b)
    {
        a = get(a);
        b = get(b);
        if(sz[a] > sz[b]) swap(a,b);
        par[a] = b;
        sz[b] += sz[a];
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        for(int i=0; i<n; i++)
        {
            par[i] = i; 
            sz[i] = 1;
        }
        int ans = 0, bonus = 0;
        
        for(auto p: connections)
        {
            int a = p[0], b = p[1];
            a = get(a), b = get(b);
            if(a == b) bonus++;
            else
            {
                Union(a,b);
            }
        }
        for(int i=1; i<n; i++)
        {
            if(get(0) != get(i))
            {
                bonus--;
                Union(0,i);
                ans++;
            }
        }
        if(bonus < 0) return -1;  
        return ans;        
    }
};