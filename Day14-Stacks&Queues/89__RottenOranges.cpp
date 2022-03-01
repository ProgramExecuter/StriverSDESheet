// Time Complexity - O(m*n)
// Space Complexity - O(m*n)
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        // Used for finding all 4 adjacent coordinates
        vector<int> dir = {-1,0,1,0,-1};
        
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<int,int>> q;
        
        // To keep track of all fresh oranges left
        int fresh = 0;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 2)
                    q.push({i,j});
                if(grid[i][j] == 1)
                    fresh++;
            }
        
        // Initialised to -1 since after each step we increment the time by 1 
        // and initially all rotten oranges started at 0.
        int ans = -1; 
        
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                pair<int,int> p = q.front();
                q.pop();
                for(int i = 0; i < 4; i++)
                {
                    int r = p.first + dir[i];
                    int c = p.second + dir[i+1];
                    if(r >= 0  &&  r < m  &&  c >= 0  &&  c<n  &&  grid[r][c] == 1)
                    {
                        grid[r][c]=2;
                        q.push({r,c});
                        fresh--; // Decrement by 1 foreach fresh orange that now is rotten
                    }
                }
            }
            ans++; // Incremented after each minute passes
        }
        if(fresh > 0)
            return -1; // If fresh>0 that means there are fresh oranges left
        if(ans == -1)
            return 0; // We initialised with -1, so if there were no oranges it'd take 0 mins.
        return ans;
        
    }
};