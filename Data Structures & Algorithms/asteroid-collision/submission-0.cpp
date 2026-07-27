class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        stack<int> st;
        for(int i = 0; i < nums.size(); i++){
            int x = nums[i];
            if(x > 0){
                st.push(x);
            }
            else {
                while(!st.empty() && st.top() > 0 && st.top() < -x){
                    st.pop();
                }

                if(st.empty() || st.top() < 0){
                    st.push(x);
                }

                if(!st.empty() && st.top() == -x){
                    st.pop();
                }
            }
        }

        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};