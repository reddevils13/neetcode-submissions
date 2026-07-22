class Solution {
public:
    int numRescueBoats(vector<int>& arr, int limit) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        // 1, 2, 4, 5
        int l = 0, r = n - 1;
        int ans = 0;
        while(l <= r){
            int sum = arr[l] + arr[r];
            if(sum <= limit){
                ans++; l++; r--;
            }
            else {
                if(arr[l] > arr[r]){
                    l++; ans++;
                }
                else{
                    r--, ans++;
                }
            }
        }
        return ans;
    }
};