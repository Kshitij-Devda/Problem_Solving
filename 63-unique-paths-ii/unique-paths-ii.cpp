class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacle) {
        int m = obstacle.size();
        int n = obstacle[0].size();

        // If starting or ending point is blocked, return 0
        if (obstacle[0][0] == 1 || obstacle[m-1][n-1] == 1) return 0;

        // Initialize the dp grid
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Starting point
        dp[0][0] = 1;

        // First column
        for (int i = 1; i < m; ++i) {
            if (obstacle[i][0] == 0) dp[i][0] = dp[i-1][0];
        }

        // First row
        for (int j = 1; j < n; ++j) {
            if (obstacle[0][j] == 0) dp[0][j] = dp[0][j-1];
        }

        // Rest of the grid
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacle[i][j] == 0) {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }

        return dp[m-1][n-1];
    }
};