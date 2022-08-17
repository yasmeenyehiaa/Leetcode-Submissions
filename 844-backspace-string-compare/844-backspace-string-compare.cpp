class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        string tmp1 = "", tmp2 = "";
        for(int i=0; i<s.size(); i++)
        {
            if(i && s[i] == '#')
            {
                if(i == 0) continue;
                if(tmp1.size() > 0) tmp1.pop_back();   
            }
            else tmp1.push_back(s[i]);
        }
        for(int i=0; i<t.size(); i++)
        {
            if(t[i] == '#')
            {
                if(i == 0) continue;
                if(tmp2.size() > 0) tmp2.pop_back();   
            }
            else tmp2.push_back(t[i]);
        }
        return tmp1 == tmp2;
    }
};