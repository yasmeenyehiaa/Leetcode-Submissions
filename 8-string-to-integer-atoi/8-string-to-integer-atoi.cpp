class Solution {
public:
    int myAtoi(string s) {
        int n = s.size(), sign = 1;
        long long int num = 0;
        
        while(s[0]==' ')
        {
            s.erase(s.begin());
        }
        
        if(s[0]=='-')
        {
            sign=-1;
            s.erase(s.begin());
        }
        else if(s[0]=='+')
        {
            sign=1;
            s.erase(s.begin());
        }
        
        if(!isdigit(s[0]))
            return 0;
        
        for(int i=0; i<n; i++)
        {
            if(isdigit(s[i]))
            {
                num *= 10;
                num += s[i]-'0';      
            }        
            else return sign*num;
            
            if(num>INT_MAX && sign==1) return INT_MAX;
            else if(num>INT_MAX && sign==-1)  return INT_MIN;
        }
        return sign*num;
    }
};