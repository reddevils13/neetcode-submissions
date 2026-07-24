class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> st;
        int n = s.size();
        int l = 0, r = 0;
        int ans = 0;
        while(r < n){
            char x = s[r];
            while(st.find(x) != st.end()){
                st.erase(s[l]);
                l++;
            }
            st.insert(x);
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};
