class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char, int> mp;
        int l = 0, r = 0, maxf = 0;
        int n = s.size();
        int ans = 0;
        while(r < n){
            mp[s[r]]++;
            maxf = max(maxf, mp[s[r]]);
            while( (r - l + 1 ) - maxf > k){
                mp[s[l]]--;
                l++;
            }
            ans = max(ans, r - l + 1);
            r++;
        }    
        return ans;
    }
};
