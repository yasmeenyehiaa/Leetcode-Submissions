class Solution {
public:
    vector<string> ans;
    void solve(int i, string s, string word)
    {
        if(word.size() == s.size()) 
        {
            ans.push_back(word);
            return;
        }        
        if(s[i] <= '9' && s[i] >= '0')
        {
            word += s[i];
            solve(i+1, s, word);
        }
        else
        {
            word.push_back(toupper(s[i]));
            solve(i+1, s, word);
            word.pop_back();
            word.push_back(tolower(s[i]));
            solve(i+1, s, word);
        }
    }
    vector<string> letterCasePermutation(string s) {
        solve(0, s, "");
        return ans;
    }
};