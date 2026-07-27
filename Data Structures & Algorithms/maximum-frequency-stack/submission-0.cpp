class FreqStack {
public:
    map<int, int> count;
    priority_queue<vector<int>> pq;
    int index; 
    FreqStack() {
        index = 0;
    }
    
    void push(int val) {
        count[val]++;
        pq.push({count[val], index++, val});
    }
    
    int pop() {
        auto top = pq.top();
        pq.pop();
        int val = top[2];
        count[val]--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */