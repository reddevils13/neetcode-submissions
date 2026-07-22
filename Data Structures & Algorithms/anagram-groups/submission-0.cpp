class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<string, vector<string>> mp;
        for (auto x: strs){
            string s = x;
            sort(x.begin(), x.end());
            mp[x].push_back(s);
        }

        for(auto x: mp){
            vector<string> tmp;
            for(auto y: x.second){
                tmp.push_back(y);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};
