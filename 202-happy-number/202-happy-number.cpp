class Solution {
public:
    int getNext(int n)
    {
        int tot = 0;
        while(n)
        {
            int x = n%10;
            tot += (x*x);
            n /= 10;
        }
        return tot;
    }
    bool isHappy(int n) {
        
        int slow = n, fast = getNext(n);
        while(fast!=1 && slow!=fast)
        {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }
        return fast == 1;        
    }
};