class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        int num = 0;
        for(int i=0; i<nums.size(); i++)
        {
          num = num ^ nums[i];
        }
        int n1 = 0, n2 = 0, rightMostBit = 1;
        while((rightMostBit & num) == 0)
        {
          rightMostBit = rightMostBit << 1;
        }
        for(auto n: nums)
        {
          if(n & rightMostBit)
          {
            n1 ^= n;
          }
          else n2 ^= n;
        }
        return vector<int>{n1,n2};
    }
};