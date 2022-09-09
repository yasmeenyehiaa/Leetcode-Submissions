class Solution {
public:
  int dp[205][20005];
  bool solve(int i, int rem, const vector<int> &num)
  {
    if(i == num.size())
    {
      return (rem==0);
    }
    if(rem < 0) return 0;
    if(dp[i][rem] != -1) return dp[i][rem];
    return dp[i][rem] = solve(i+1, rem-num[i], num) || solve(i+1, rem, num);
  }
  bool canPartition(vector<int> &num) {
    int sum = 0;
    for(auto a: num) sum += a;
    if(sum%2 == 1) return 0;
    memset(dp, -1, sizeof dp);
    return solve(0,sum/2, num);
  }
};