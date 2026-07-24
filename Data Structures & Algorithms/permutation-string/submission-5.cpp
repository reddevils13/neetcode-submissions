class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l = 0, r = 0;
        map<char, int> mp1;
        for(char x: s1){
            mp1[x]++;
        }
        int n = mp1.size();
        for(int i = 0; i < s2.size(); i++){
            map<char, int> mp2;
            int curr = 0;
            for(int j = i; j < s2.size(); j++){
                char c = s2[j];
                mp2[c]++;
                if(mp1[c] < mp2[c])
                    break;
                
                if(mp1[c] == mp2[c])
                    curr++;
                if(curr == n)
                    return true;
            }
        }
        return false;
    }
};
