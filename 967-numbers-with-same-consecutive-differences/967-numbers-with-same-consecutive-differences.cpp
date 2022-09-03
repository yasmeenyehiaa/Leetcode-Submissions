class Solution {
public:
    vector<int> ans;
    void solve(int num, int rem, int k)
    {
        if(rem == 0) 
        {
            ans.push_back(num);
            return;
        }
        int lst = num % 10;
        if(lst+k < 10)
        {
            int x = num*10 + (lst+k);
            solve(x, rem-1, k);
        }
        if(k!=0 && lst-k >= 0)
        {
            int x = num*10 + (lst-k);
            solve(x, rem-1, k);
        }        
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        
        for(int i=1; i<10; i++)
        {
            solve(i, n-1, k);
        }
        return ans;
    }
};