class Solution {
public:
    string convert(string s, int numRows) {
        
        if(numRows == 1) return s;
        
        string ans = "";
        vector<string> vec(numRows);
        bool check = 0;
        int row = 0;
        for(int i=0; i<s.size(); i++)
        {
            vec[row] += s[i];
            if(row == 0 || row == numRows-1) check = !check;
            row += check? 1:-1;
        }
        for(auto str: vec)
        {
            ans += str;
        }
        return ans;
    }
};