class Solution {
public:
    int mod = 1e9+7;
    int countVowelPermutation(int n) {
        vector<long long> last(5, 1), cur(5, 0);
        vector<vector<long long>> validPrev = {{1, 2, 4}, {0, 2}, {1, 3}, {2}, {2, 3}};
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < 5; ++j) 
                for(auto k: validPrev[j])
                    cur[j] = (cur[j] + last[k])%mod;
            last = cur;
            cur = {0, 0, 0, 0, 0};
        }
        long long ans = 0;
        for(auto n : last) ans = (ans + n)%mod;
        return ans;
    }
};