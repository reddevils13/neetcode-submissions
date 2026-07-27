class StockSpanner {
public:
    stack<int> s;
    vector<int> span; 
    StockSpanner() {
        
    }
    
    int next(int price) {
        int n = span.size();
        int ans = 0;
        for(int i = n - 1; i >= 0; i--){
            if(price >= span[i]){
                ans++;
            }
            else{
                break;
            }
        }

        span.push_back(price);
        return ans + 1;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */