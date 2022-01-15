/////////////////////
///  Solution 1  ///
///////////////////

// Time Complexity - O(2^(m+n))
// Space Complexity - O(1)
class Solution {
public:
    int path(int i, int j, int m, int n) {
        // Out of bounds so it contributes 0
        if(i >= m || j >= n)
            return 0;
        
        if(i == m-1  &&  j == n-1)
            return 1;
        
        int ans = 0;
        // Add the no. of path if we go downwards
        ans += path(i+1, j, m, n);
        
        // Add the no. of path if we go right
        ans += path(i, j+1, m, n);
        
        return ans;
    }
    int uniquePaths(int m, int n) {
        int posX = 0, posY = 0; 
        return path(posX, posY, m, n);
    }
};


/////////////////////
///  Solution 2  ///
///////////////////

// Time Complexity - O(m*n)
// Space Complexity - O(m*n)
// Use DP
class Solution {
public:
    int path(int i, int j, int m, int n, vector<vector<int>> &dp, vector<vector<bool>> &visited) {
        // Out of bounds so it contributes 0
        if(i >= m || j >= n)
            return 0;
        
        // If we reached the end
        if(i == m-1  &&  j == n-1) {
            dp[i][j] = 1;
            visited[i][j] = true;
            return dp[i][j];
        }
        
        int ans = 0;
        
        // Go downwards if it isn't out of bounds
        if(i+1 < m) {
            int down = 0;
            // If downwards is visited then add to answer
            if(visited[i+1][j])
                down = dp[i+1][j];
            // Else go downwards
            else
                down = path(i+1, j, m, n, dp, visited);
            ans += down;
        }
        
        // Go right if it isn't out of bounds
        if(j+1 < n) {
            int right = 0;
            // If right is visited then add to answer
            if(visited[i][j+1])
                right = dp[i][j+1];
            // Else go right
            else
                right = path(i, j+1, m, n, dp, visited);
            ans += right;
        }
        
        // Save current answer to 'dp'
        // and make this position as visited
        dp[i][j] = ans;
        visited[i][j] = true;
        
        return ans;
    }
    int uniquePaths(int m, int n) {
        int posX = 0, posY = 0;
        
        // For DP
        vector<vector<int>> dp(m, vector<int>(n, 0));
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        return path(posX, posY, m, n, dp, visited);
    }
};