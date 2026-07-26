class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> ans;
        priority_queue<pair<int, int>> pq;
        for(int i = 0; i < n; i++){
            pq.push({nums[i], i});
            if(i >= k - 1){
                while(pq.top().second <= i - k){
                    pq.pop();
                }
                int mx = pq.top().first;
                ans.push_back(mx);
            }
        }
        return ans;
    }
};
