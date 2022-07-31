class NumArray {
public:
    const int N = 300005;
    int tree[200000], n;
    vector<int> nums;
    void build(int idx, int l, int r)
    {
        if(l==r) 
        {
            tree[idx] = nums[l];
            return;
        }
        int m = (l+r)/2;
        build(2*idx, l,m);
        build(2*idx+1,m+1, r);
        tree[idx] = tree[2*idx]+tree[2*idx+1]; 
    };
    
    NumArray(vector<int>& num) {
        nums = num;
        n = nums.size();
        build(1,0,n-1);
        
    }
    void upd(int idx, int l, int r, int pos, int val)
    {
        if(l>pos || r<pos) return;
        if(l==r) 
        {
            tree[idx] = val;
            nums[pos] = val;
            return;                
        }
        int m = (l+r)/2;
        upd(2*idx, l,m,pos, val);
        upd(2*idx+1, m+1, r, pos, val);
        tree[idx] = tree[2*idx]+tree[2*idx+1];
    }
    void update(int index, int val) {
        upd(1,0,n-1,index,val);        
    }
    int query(int idx, int l, int r, int lx, int rx)
    {
        if(rx<l || lx>r) return 0;
        if(lx<=l && r<=rx) return tree[idx];
        int m = (l+r)/2;
        return query(2*idx, l, m, lx, rx) + query(2*idx+1, m+1, r, lx, rx);
    }
    int sumRange(int left, int right) {
        return query(1,0,n-1,left,right);        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */