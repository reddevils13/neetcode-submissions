class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int, int> mp;
        vector<int> ans;
        for(int i = 0; i < n; i++){

            if(mp.contains(target-nums[i])){
                ans.push_back(mp[target-nums[i]]);
                ans.push_back(i);
                return ans;
            }
            mp[nums[i]] = i;
                
        }

        return ans;
    }
};
