class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        int ans = 0;
        for(int x:nums){
            if(s.find(x-1) == s.end()){
                int length = 1;
                while(s.find(x+length) != s.end()){
                    length++;
                }
                ans = max(ans, length);
            }
        }

        return ans;
    }
};
