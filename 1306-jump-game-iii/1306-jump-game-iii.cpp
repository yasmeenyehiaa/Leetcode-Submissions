class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int> q;
        q.push(start);
        bool vis[50005] = {0};
        vis[start] = 1;
        while(!q.empty())
        {
            int tmp = q.front();
            q.pop();
            if(arr[tmp] == 0) return true;
            if(tmp+arr[tmp] < n && !vis[tmp+arr[tmp]])
            {
                q.push(tmp+arr[tmp]);
                vis[tmp+arr[tmp]] = 1;
            }
            if(tmp-arr[tmp] >= 0 && !vis[tmp-arr[tmp]])
            {
                q.push(tmp-arr[tmp]);  
                vis[tmp-arr[tmp]] = 1;
            }
        }
        return false;
    }
};