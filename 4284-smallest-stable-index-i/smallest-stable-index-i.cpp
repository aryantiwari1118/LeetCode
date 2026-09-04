class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> lows(n);  
        lows.back() = nums.back();
        for (int i = n - 2; i >= 0; --i)
            lows[i] = min(nums[i], lows[i + 1]);

        int high = nums[0];  
        for (int i = 0; i < n; ++i) {
            high = max(high, nums[i]);
            if (high - lows[i] <= k)
                return i;
        }

        return -1;
    }
};