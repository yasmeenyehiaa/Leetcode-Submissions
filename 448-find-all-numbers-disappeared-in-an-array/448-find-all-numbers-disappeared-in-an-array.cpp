class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
    vector<int> missingNumbers;
    int i = 0, n = nums.size();
    while(i < n)
    {
      int j = nums[i] - 1;
      if(nums[i] != nums[j])
      {
        swap(nums[i], nums[j]);
      }
      else i++;
    }
    for(int i=0; i<n; i++)
    {
      if(nums[i] != i+1) 
      {
        missingNumbers.push_back(i+1);
      }
    }
    cout << endl;
    return missingNumbers;
    }
};