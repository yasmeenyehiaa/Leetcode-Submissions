class Solution {
public:
    void reverseString(vector<char>& s) {
        
        int n = s.size();
        for(int i=0; i<n/2; i++)
        {
            char a = s[i], b = s[n-i-1];
            s[i] = b;
            s[n-i-1] = a;
        }        
    }
};