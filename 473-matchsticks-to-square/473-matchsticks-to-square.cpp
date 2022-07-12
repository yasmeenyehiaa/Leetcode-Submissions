class Solution {
public:
    int side = 0;
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        for(int i=0; i<matchsticks.size(); i++)
        {
            sum += matchsticks[i];
        }
        side = sum/4;
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        if((float)sum/4 > side || matchsticks[0] > side) return false; 
       
        return backtrack(0, side, 0,matchsticks);
    }
    bool backtrack(int idx, int rem, int done, vector<int>& arr)
    {
        if(done == 3) return true;
        
        for(; idx < arr.size(); idx++)
        {
            int tmp = arr[idx];
            bool ok = 0;
            if(tmp > rem) continue;
            arr[idx] = side + 5;
            if(tmp == rem)
            {
                ok = backtrack(1, side, done+1, arr);
            }
            else
            {
                ok = backtrack(idx+1, rem-tmp, done, arr);
            }
            
            if(ok) return true;
            arr[idx] = tmp;
            while(idx < arr.size() && arr[idx+1] == tmp) idx++;
        }
        
        return false;
    }
};