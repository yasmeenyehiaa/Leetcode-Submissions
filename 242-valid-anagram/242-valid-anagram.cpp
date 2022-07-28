class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.size() != t.size())
        {
            return false;
        }
        unordered_map<char, int> cnt_s, cnt_t;
        for(int i=0; i<s.size(); i++)
        {
            cnt_s[s[i]]++;
            cnt_t[t[i]]++;
        }        
        for(auto ch: t)
        {
            if(cnt_t[ch] != cnt_s[ch])
            {
                return false;
            }
        }
        return true;        
    }
};