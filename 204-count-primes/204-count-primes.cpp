class Solution {
public:
    int countPrimes(int n) {
        int ans = 0;
        vector<bool> primes(n+1,true);
        primes[0] = primes[1] = 0;
        
        for(int i=2; i<n; i++)
        {
            if(primes[i])
            {
                ans++;
                for(int j=2; i*j<=n; j++)
                {
                    primes[j*i] = false;
                }
            }
        }
        
        return ans;
    }
};
