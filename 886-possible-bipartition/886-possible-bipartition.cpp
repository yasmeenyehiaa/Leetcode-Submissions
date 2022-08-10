class Solution {
public:    
    vector<int> adj[2005];
    bool dfs(vector<int>& color, int node)
    {
        for(auto it: adj[node])
        { 
            if(color[it]==-1)
            { 
                color[it]=1-color[node]; 
                if(!dfs(color,it)) return false;
            }
            else if(color[it]!=1-color[node]) return false;
        }
        return true;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        for(int i=0;i<dislikes.size();i++)
        {
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        vector<int>color(n+1,-1);
        for(int i=1;i<=n;i++)
        {
            if(color[i]==-1)
            {
                color[i]=0;
                if(!dfs(color,i)) return false;
            }
        }
        return true;
    }
};