class Solution {
public:
    int search(vector<int>& arr, int key) {
        
        int n = arr.size(), l = 0, r = n-1;
        while(l <= r)
        {
          int m = (l+r)/2;
          if(arr[m] == key) return m;
          if(arr[l] <= arr[m]) // first part
          {
              if(key >= arr[l] && key < arr[m])
              {
                  r = m-1;
              }
              else l = m+1;
          }
          else // second part
          {
              if(key > arr[m] && key <= arr[r])
              {
                l = m+1;
              }
              else r = m-1;
          }
        }
        return -1;
    }
};