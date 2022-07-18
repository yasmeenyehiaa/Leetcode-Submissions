class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int r = matrix.size(), c = matrix[0].size(), ans = 0;        
        for(int i=0; i<r; i++)
        {
            for(int j=1; j<c; j++)  matrix[i][j] += matrix[i][j-1];
        }
        
        for(int c1=0; c1<c; c1++)
        {
            for(int c2=c1; c2<c; c2++)
            {
                map<int,int> frq;
                frq[0] = 1;
                int sum = 0;
                
                for(int nr=0; nr<r; nr++)
                {
                    sum += matrix[nr][c2] - (c1>0? matrix[nr][c1-1] : 0);
                    ans+=frq[sum-target];
                    frq[sum]++;
                    
                }        
                
            }
        }
        return ans;
        
    }
};