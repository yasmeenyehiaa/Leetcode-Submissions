class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        
        map<char, int> frq;
        for(auto ch: word1) 
        {
            frq[ch]++;
        }
        for(auto ch: word2)
        {
            frq[ch]--;
        }
        for(int i=0; i<26; i++)
        {
            if(abs(frq[i+'a']) > 3)
            {
                return false;
            }
        }
        return true;
    }
};