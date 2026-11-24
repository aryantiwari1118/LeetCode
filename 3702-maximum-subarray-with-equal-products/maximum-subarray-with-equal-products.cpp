class Solution {
    static constexpr int PRIMES[11][2] = {
        {-1, -1}, {-1, -1}, {0, -1}, {1, -1}, {0, -1},
        {2, -1},  {0, 1},   {3, -1}, {0, -1}, {1, -1}, {0, 2}
    };

public:
    int maxLength(vector<int>& nums) {
        int last[4] = {-1, -1, -1, -1}, ans = 2, left = 0;

        for (int right = 0; right < nums.size(); ++right) {
            for (int p : PRIMES[nums[right]]) {
                if (p != -1) {
                    left = max(left, last[p] + 1);
                    last[p] = right;
                }
            }
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};