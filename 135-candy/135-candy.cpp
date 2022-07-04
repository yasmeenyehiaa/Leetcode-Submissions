class Solution {
public:
    int candy(vector<int>& ratings) 
    {        
        int ans = 0, n = ratings.size();
        int left[n], right[n];        
        for(int i=0; i<n; i++)  left[i] = right[i] = 1;
        for(int i=1; i<n; i++)
        {
           if(ratings[i] > ratings[i-1])
           {
               left[i] = left[i-1] + 1;
           }
        }
        for(int i=n-2; i>=0; i--)
        {
            if(ratings[i] > ratings[i+1])
            {
                right[i] = right[i+1] + 1;
            }
        }
        for(int i=0; i<n; i++)
        {
            ans += max(right[i], left[i]);
        }
        
        return ans;
    }
};