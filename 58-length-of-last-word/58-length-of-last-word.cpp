class Solution {
public:
    int lengthOfLastWord(string s) {
        
        string tmp = "";
        
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == ' ')
                continue;
            if(i && s[i-1] == ' ')
            {
                tmp = "";
            }
            tmp += s[i];
        }
        return tmp.size();        
    }
};