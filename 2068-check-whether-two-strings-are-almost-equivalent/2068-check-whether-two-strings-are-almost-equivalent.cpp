class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        
        map<char, int> frq1, frq2;
        for(auto ch: word1) 
        {
            frq1[ch]++;
        }
        for(auto ch: word2)
        {
            frq2[ch]++;
        }
        for(int i=0; i<26; i++)
        {
            if(abs(frq1[i+'a'] - frq2[i+'a']) > 3)
            {
                return false;
            }
        }
        return true;
    }
};