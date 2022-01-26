// Time Complexity - O(4^(m*n))
// Space Complexity - O(m*n)

class Solution{
    public:
    void pathFind(vector<vector<int>> &m, int row, int col, int n, string path, vector<string> &ans, vector<vector<bool>> &vis) {
        if(row == n-1  &&  col == n-1)
        {
            ans.push_back(path);
            return;
        }
        
        // Up 
        if(row-1 >= 0  &&  vis[row-1][col] == false  &&  m[row-1][col] == 1) {
            // Move Up
            vis[row][col] = true;
            
            pathFind(m, row-1, col, n, path+'U', ans, vis);
            
            // Backtrack
            vis[row][col] = false;
        }
        
        // Down
        if(row+1 < n  &&  vis[row+1][col] == false  &&  m[row+1][col] == 1) {
            // Move Down
            vis[row][col] = true;
            
            pathFind(m, row+1, col, n, path+'D', ans, vis);
            
            // Backtrack
            vis[row][col] = false;
        }
        
        // Left
        if(col-1 >= 0  &&  vis[row][col-1] == false  &&  m[row][col-1] == 1) {
            // Move Left
            vis[row][col] = true;
            
            pathFind(m, row, col-1, n, path+'L', ans, vis);
            
            // Backtrack
            vis[row][col] = false;
        }
        
        // Right
        if(col+1 < n  &&  vis[row][col+1] == false  &&  m[row][col+1] == 1) {
            // Move Right
            vis[row][col] = true;
            
            pathFind(m, row, col+1, n, path+'R', ans, vis);
            
            // Backtrack
            vis[row][col] = false;
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        
        // Initialize a starting path
        string path;
        
        // First block is blocked so no paths
        if(m[0][0] == 0)
            return ans;
        
        pathFind(m, 0, 0, n, path, ans, vis);
        
        return ans;
    }
};
