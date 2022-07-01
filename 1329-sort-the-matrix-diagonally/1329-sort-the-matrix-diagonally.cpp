class Solution {
public:
    int m,n;
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        m = mat.size(), n = mat[0].size();
        
        for(int c=0; c<n; c++)
        {
            sort(mat, 0, c);
        }
        
        for(int r=0; r<m; r++)
        {
            sort(mat, r, 0);
        }
        
        return mat;
    }
    
    void sort(vector<vector<int>>& mat, int row, int col)
    {
        int arr[101] = {0};
        int r = row, c = col;
        while(r<m && c<n)
        {
            arr[mat[r++][c++]]++;
        }
        
        r=row, c =col;
        
        for(int i=1; i<101; i++)
        {
            if(arr[i])
            {
                while(arr[i]--)
                {
                    mat[r++][c++] = i;
                }
            }
        }
    }
};