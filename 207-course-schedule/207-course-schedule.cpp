class Solution {
public:
    vector<int> adj[2005];
    bool vis[2005];
    bool isCyclic(int src, set<int> &stack)
    {
        vis[src] = 1;
        stack.insert(src);
        for(auto a:adj[src])
        {
            if (stack.find(a) != stack.end()) return true;
            if(!vis[a] && isCyclic(a, stack)) return true;
        }
        stack.erase(*stack.find(src));
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       
        int n = prerequisites.size();
        for(int i=0; i<n; i++)  adj[prerequisites[i][0]].push_back(prerequisites[i][1]);    
        for(int i=0; i<numCourses; i++)
        {
            if(!vis[i])
            {
                set<int> st;
                if(isCyclic(i, st)) return false;
            }
        }
        return true;
        
    }
};