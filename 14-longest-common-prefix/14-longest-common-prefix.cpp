class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string f=strs[0];
        for(int i=0;i<f.size();i++)
        {
            char c=f[i];
            for(int j=1;j<strs.size();j++)
            {
                if(i==strs[j].size() || strs[j][i]!=c)
                    return f.substr(0,i);
            }
        }
        return f;
    }
        
};