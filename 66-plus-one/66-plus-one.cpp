class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        vector<int> ret;
        int carry = 1;
        for(int i= digits.size()-1; i>=0; i--)
        {
            int tmp = digits[i]+carry;
            if(tmp >= 10)
            {
                carry = 1;
                tmp %= 10;
            }
            else carry = 0;
            ret.push_back(tmp);
        }
        if(carry) ret.push_back(1);
        reverse(ret.begin(), ret.end());
        return ret;
        
    }
};