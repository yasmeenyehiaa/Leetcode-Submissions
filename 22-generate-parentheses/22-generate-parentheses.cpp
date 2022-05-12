class Solution {
public:
    vector<string> generateParenthesis(int n) {
        
    vector<string> ans;        
    Backtrack(0, n,n, "", ans);
    return ans;
        
    }
    
    void Backtrack(int i, int opened, int closed, string s, vector<string> &ans)
    {
        if(opened == 0 && closed == 0)
        {
            ans.push_back(s);
            return;
        }
        
        if(opened)
        {
            Backtrack(i+1, opened-1, closed, s+'(', ans);
        }
        if(closed > opened) 
        {
            Backtrack(i+1, opened, closed-1, s+')', ans);     
        }
    }
};