class Solution {
public:
    // time/space: O(mn)/O(min(m, n))
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        if (m < n) return longestCommonSubsequence(text2, text1);
        
        vector<int> dp0(n + 1, 0), dp1(n + 1, 0);
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int pick = ((text1[i] == text2[j]) ? 1 : 0) + dp1[j + 1];
                int not_pick = max(dp1[j], dp0[j + 1]);
                dp0[j] = max(pick, not_pick);
            }
            swap(dp0, dp1);
        }
        return dp1[0];
    }
};
