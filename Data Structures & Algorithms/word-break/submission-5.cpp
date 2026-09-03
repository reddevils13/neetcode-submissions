class TrieNode {
    public:
        unordered_map<char, TrieNode*> children;
        bool isWord = false;
};

class Trie {
public:
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }

    void insert(string word){
        TrieNode* node = root;
        for(char c: word){
            if(!node->children.count(c)) {
                node->children[c] = new TrieNode();
            }

            node = node->children[c];
        }

        node->isWord = true;
    }

    bool search(string &s, int i, int j) {
        TrieNode* node = root;
        for(int idx = i; idx <= j; idx++){
            if(!node->children[s[idx]]){
                return false;
            }

            node = node->children[s[idx]];
        }

        return node->isWord;
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie trie;
        int maxLen = 0;
        for(string word: wordDict){
            trie.insert(word);
            maxLen = max(maxLen, (int)word.size());
        }

        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[n] = true;

        for(int i = n - 1; i >= 0; --i){
            for(int j = i; j < min(n, i + maxLen); j++){
                if(trie.search(s, i, j)) {
                    dp[i] = dp[j + 1];
                    if(dp[i]) break;
                }
            }
        }

        return dp[0];
    }
};
