class Solution {
public:
    vector<string> ans;
    string Map[10] = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    void solve(int idx, string cur, string digits)
    {
        if(idx >= digits.size())
        {
            ans.push_back(cur);
            return;
        }
        string str = Map[digits[idx] - '0'];
        for(int i=0; i<str.size(); i++)
        {
            solve(idx+1, cur+str[i], digits);
        }
        
    }
    vector<string> letterCombinations(string digits) {
        
        if(digits.length() == 0)
        {
            return ans;
        }
        solve(0, "", digits);
        return ans;   
    }
};