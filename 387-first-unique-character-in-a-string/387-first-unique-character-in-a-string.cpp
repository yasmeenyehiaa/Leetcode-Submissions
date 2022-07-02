class Solution {
public:
    int firstUniqChar(string s) {
        map<char, int> cnt;
        for(int i=0; i<s.size(); i++)  cnt[s[i]]++;
        for(int i=0; i<s.size(); i++)
        {
           if(cnt[s[i]] == 1) return i;
        }
        return -1;        
    }
};