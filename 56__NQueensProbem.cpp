/////////////////////
///  Solution 1  ///
///////////////////

// Time Complexity - O(n! * n)      ->  'n' for checking diagonals & row
// Space Complexity - O(n^2)

class Solution {
public:
    bool checkDiagonal(int row, int col, int n, vector<string> curr, int xAdd, int yAdd)
    {
        while(row>=0  && col>=0  &&  row<n  &&  col<n)
        {
            if(curr[row][col] == 'Q')
                return false;
            row += xAdd;
            col += yAdd;
        }
        
        return true;
    }
    bool isValid(int row, int col, vector<string> &curr, int n)
    {
        // Check if there is any queen in ROW before this column
        for(int i=0; i<col; ++i)
        {
            if(curr[row][i] == 'Q')
                return false;
        }
        
        // Check the diagonals of the queen
        bool isOK = true;
        
        // Check Upper Left Diagonal
        isOK = isOK && checkDiagonal(row, col, n, curr, -1, -1);
        // Check Lower Left Diagonal
        isOK = isOK && checkDiagonal(row, col, n, curr, 1, -1);

        // If the diagonals have any queen
        // then return FALSE
        if(isOK == false)
            return false;
        
        return true;
    }
    void placeQueens(int n, int col, vector<string> &curr, vector<vector<string>> &ans)
    {
        // If reached end push it to 'ans'
        if(col == n)
        {
            ans.push_back(curr);
            return;
        }
        
        for(int row=0; row<n; ++row)
        {
            if(isValid(row, col, curr, n)) 
            {
                curr[row][col] = 'Q';
                placeQueens(n, col+1, curr, ans);
                curr[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        
        // Current string where no queen is placed
        vector<string> curr;
        for(int row=0; row<n; ++row)
        {
            string tmp(n, '.');
            curr.push_back(tmp);
        }
        
        placeQueens(n, 0, curr, ans);
        
        return ans;
    }
};



/////////////////////
///  Solution 2  ///
///////////////////

// Time Complexity - O(n!)
// Space Complexity - O(n^2 + 3*n)

class Solution {
public:
    void placeQueens(int n, int col, vector<string> &curr, vector<vector<string>> &ans, vector<bool> &left, vector<bool> &lowerDiag, vector<bool> &upperDiag)
    {
        // If reached end, push it to 'ans'
        if(col == n)
        {
            ans.push_back(curr);
            return;
        }
        
        for(int row=0; row<n; ++row)
        {
            if(
                // For Checking ROWS of Queens
                left[row] == false  &&
                // For Checking Lower Diagonal of Queens
                lowerDiag[row+col] == false  &&
                // For Checking Upper Diagonal of Queens
                upperDiag[n-1 + col-row] == false
            ) 
            {
                // Placing Flags
                left[row] = true;
                lowerDiag[row+col] = true;
                upperDiag[n-1 + col-row] = true;
                // Placing Queen
                curr[row][col] = 'Q';
                
                placeQueens(n, col+1, curr, ans, left, lowerDiag, upperDiag);
                
                // Removing Queen
                curr[row][col] = '.';
                // Removing Flags
                left[row] = false;
                lowerDiag[row+col] = false;
                upperDiag[n-1 + col-row] = false;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        
        // Current string where no queen is placed
        vector<string> curr;
        for(int row=0; row<n; ++row)
        {
            string tmp(n, '.');
            curr.push_back(tmp);
        }
        
        vector<bool> left(n, false), lowerDiag(2*n-1, false), upperDiag(2*n-1, false);
        
        placeQueens(n, 0, curr, ans, left, lowerDiag, upperDiag);
        
        return ans;
    }
};