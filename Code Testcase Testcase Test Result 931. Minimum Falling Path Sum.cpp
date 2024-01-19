#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    const int M = 1e9 + 7;
    int n;
    vector<vector<int>> dp;
    vector<vector<int>> matrix;

    int f(int i, int j) {
        int x = matrix[i][j];
        if (i == n - 1) return x;
        if (dp[i][j] < M) return dp[i][j];

        int next = f(i+1, j);
        if (j>0) next=min(next, f(i+1, j-1));
        if (j<n-1) next=min(next, f(i+1, j+1 ));
        return dp[i][j] = x+next;
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        this->matrix = matrix;
        n = matrix.size();
        dp.assign(n, vector<int>(n, M));
        int ans = INT_MAX;

        for (int j = 0; j < n; j++) {
            ans = min(ans, f(0, j));
        }

        return ans;
    }
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
