class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> allChars;
        for(auto ch: s)
        {
            if(isalnum(ch))
            {
                allChars.push_back(tolower(ch));
            }
        }
        int n = allChars.size();
        bool ok = 1;
        for(int i=0; i<n/2; i++)
        {
            if(allChars[i] != allChars[n-i-1])
            {
                ok = 0;
                break;
            }
        }
        if(ok)
        {
            return true;
        }
        else
        {
            return false;
        }        
    }
};