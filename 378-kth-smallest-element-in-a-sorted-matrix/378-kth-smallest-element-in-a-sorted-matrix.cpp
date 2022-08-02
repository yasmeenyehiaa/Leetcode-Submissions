class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int n = matrix.size();
        int l = matrix[0][0] , r = matrix[n-1][n-1], ans = 0;
        while(l <= r)
        {
            int m = (l+r)/2, cnt = 0;
            for(int i=0; i<n; i++)
            {
                int t = upper_bound(matrix[i].begin(), matrix[i].end(), m) - matrix[i].begin();
                cnt += t;
            }
            if(cnt >= k) 
            {
                ans = m;
                r = m - 1;
            }
            else l = m + 1;
        }
        
        return ans;
    }
};