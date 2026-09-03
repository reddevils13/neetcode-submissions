class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<int> vis(s.size(), -1);
        return dfs(s, 0, st, vis);
    }

    bool dfs(string &s, int i, unordered_set<string> &st, vector<int> &vis){
        int n = s.size();
        if(i == n)
            return true;
        if(vis[i] != -1)
            return vis[i] == 1;
        
        for(int j = i; j < n; j++){
            if(st.find(s.substr(i, j - i +1)) != st.end()){
                if(dfs(s, j + 1, st, vis)){
                    vis[i] = 1;
                    return true;
                }
            }
        }

        vis[i] = 0;
        return false;        
    }
};
