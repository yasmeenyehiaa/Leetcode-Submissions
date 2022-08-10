class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
        vector<int>ans;
        int in[100005] = {0}, out[100005] = {0};
        for(auto i:edges)
        {
            in[i[1]]++;
            out[i[0]]++;
        }
        for(int i=0;i<n;i++)
        {
            if(in[i]==0 && out[i]!=0)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};