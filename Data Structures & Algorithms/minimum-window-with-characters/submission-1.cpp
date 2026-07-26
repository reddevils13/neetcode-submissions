class Solution {
public:
    string minWindow(string s, string t) {
        int low = 0, start = 0, len = INT_MAX, count = 0;
        int m = t.size();
        int n = s.size();
        map<char, int> mp;
        for(char x: t){
            mp[x]++;
        }

        for(int i = 0; i < n; i++){
            if(mp[s[i]] > 0){
                count++;
            }
            mp[s[i]]--;
            if(count == m){
                while(low < i && mp[s[low]] < 0){
                    mp[s[low]]++;
                    low++;
                }

            if (len > i - low + 1) {
                len = i - low + 1;
                start = low;
            }
                mp[s[low]]++;
                low++;
                count--;
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};
