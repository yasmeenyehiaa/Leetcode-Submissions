class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
        
    vector<int> missingNumbers;
    int i = 0, n = nums.size();
    while(i < n)
    {
      int j = nums[i] - 1;
      if(nums[i] > 0 && nums[i] <= n && nums[i] != nums[j])
      {
        swap(nums[i], nums[j]);
      }
      else i++;
    }
    unordered_set<int> st;
    for(int i=0; i<n; i++)
    {
      if(nums[i] != i+1)
      {
        if(missingNumbers.size() < k) missingNumbers.push_back(i+1);
        st.insert(nums[i]);
      }
    }
    i = n;
    while(missingNumbers.size() < k)
    {
      if(st.find(i+1) == st.end())
      {
        missingNumbers.push_back(i+1);
      }      
      i++;
    }
    return missingNumbers[k-1];
        
    }
};