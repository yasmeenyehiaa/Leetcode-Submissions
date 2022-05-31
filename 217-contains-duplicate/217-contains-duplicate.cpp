class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
    
    unordered_map<int, int> cnt;
    for(auto x: nums){
        cnt[x]++;
        if(cnt[x] >= 2){
            return true;
        }
    }
    return false;
  }
};