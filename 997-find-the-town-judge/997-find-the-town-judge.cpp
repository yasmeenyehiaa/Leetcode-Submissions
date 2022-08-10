class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int in[1005] = {0}, out[1005] = {0}; 
        for(auto p: trust)
        {
            in[p[1]]++;
            out[p[0]]++;
        }
        for(int i=1; i<=n; i++)
        {
            if(in[i] == n-1 && out[i] == 0) return i;
        }
        return -1;
    }
};