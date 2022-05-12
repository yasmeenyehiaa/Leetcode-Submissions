class Solution {
public:
    
    vector<string> ans;
    vector<string> generateParenthesis(int n) {        
            
    Backtrack(0, n,n, "");
    return ans;
        
    }
    
    void Backtrack(int i, int opened, int closed, string s)
    {
        if(opened == 0 && closed == 0)
        {
            ans.push_back(s);
            return;
        }
        
        if(opened)
        {
            Backtrack(i+1, opened-1, closed, s+'(');
        }
        if(closed > opened) 
        {
            Backtrack(i+1, opened, closed-1, s+')');     
        }
    }
};