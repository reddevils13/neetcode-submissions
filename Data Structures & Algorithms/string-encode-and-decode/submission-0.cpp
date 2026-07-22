class Solution {
public:
    map<string, vector<string>> enc;
    string encode(vector<string>& strs) {
        string encoded_string;
        for(auto x:strs){
            encoded_string+=x;
        }
        enc[encoded_string] = strs;
        return encoded_string;
    }

    vector<string> decode(string s) {
        return enc[s];
    }
};
