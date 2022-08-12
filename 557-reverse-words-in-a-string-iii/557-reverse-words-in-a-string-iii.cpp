class Solution {
public:
    string reverseWords(string s) {
        
        string tmp = "", ans = "";
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == ' ')
            {
                reverse(tmp.begin(), tmp.end());
                ans += tmp;
                tmp = "";
                 ans += " ";
            }
            else tmp += s[i];
        }
        reverse(tmp.begin(), tmp.end());
        ans += tmp;
        return ans;
    }
};