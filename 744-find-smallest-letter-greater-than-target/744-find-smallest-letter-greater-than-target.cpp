class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        for(auto l : letters)
        {
            if(l <= target) continue;
            else return l;
        }
        return letters[0];        
    }
};