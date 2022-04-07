// Time Complexity - O(M*N)
// Space Complexity - O(M*N)

class Solution {
public:
    void bfs(vector<vector<char>>& grid, int row, int col, int nRow, int nCol, vector<vector<bool>> &vis) {
        queue<pair<int, int>> q;
        
        q.push({row, col});
        vis[row][col] = true;
        
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            // Check right
            if(x+1 < nRow  &&  grid[x+1][y] == '1'  &&  !vis[x+1][y]) {
                q.push({x+1, y});
                vis[x+1][y] = true;
            }
            
            // Check down
            if(y+1 < nCol  &&  grid[x][y+1] == '1'  &&  !vis[x][y+1]) {
                q.push({x, y+1});
                vis[x][y+1] = true;
            }
            
            // Check left
            if(x > 0  &&  grid[x-1][y] == '1'  &&  !vis[x-1][y]) {
                q.push({x-1, y});
                vis[x-1][y] = true;
            }
            
            // Check up
            if(y > 0  &&  grid[x][y-1] == '1'  &&  !vis[x][y-1]) {
                q.push({x, y-1});
                vis[x][y-1] = true;
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int nRow = grid.size(), nCol = grid[0].size(), cntIslands = 0;
        
        vector<vector<bool>> vis(nRow, vector<bool>(nCol, false));
        
        for(int row = 0; row < nRow; ++row) {
            for(int col = 0; col < nCol; ++ col) {
                if(vis[row][col])   continue;               // Skip visited islands
                
                if(grid[row][col] == '1') {                   // Check for land
                    bfs(grid, row, col, nRow, nCol, vis);
                    ++cntIslands;                           // Increment count of islands
                }
            }
        }
        
        return cntIslands;
    }
};