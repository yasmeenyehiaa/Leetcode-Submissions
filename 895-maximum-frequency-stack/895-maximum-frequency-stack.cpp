class FreqStack {
public:
    map<int,int> frq;
    int sz;
    priority_queue<pair<int, pair<int,int>>> pq;
    FreqStack() {
       sz = 0;
    }
    
    void push(int val) {
        
        frq[val]++;
        pq.push({frq[val], {++sz, val}});
    }
    
    int pop() {
        int ans = pq.top().second.second;
        pq.pop();
        frq[ans]--;
        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */