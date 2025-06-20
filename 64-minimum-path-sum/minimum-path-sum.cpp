class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) continue; // Starting cell
                else if(i == 0) grid[i][j] += grid[i][j - 1]; // First row
                else if(j == 0) grid[i][j] += grid[i - 1][j]; // First column
                else grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]); // DP transition
            }
        }

        return grid[m - 1][n - 1]; // Minimum path sum to reach bottom-right
    }
};