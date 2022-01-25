/////////////////////
///  Solution 1  ///
///////////////////

// Time Complexity - O(9^(n^2) * n)    -  n  => for checking validity
// Space Complexity - O(n^2)

class Solution {
public:
  bool check(vector<vector<char>> &board, int i, int j, char val)
  {
      int row = i - i%3, column = j - j%3;
      for(int x=0; x<9; x++) if(board[x][j] == val) return false;
      for(int y=0; y<9; y++) if(board[i][y] == val) return false;
      for(int x=0; x<3; x++)
      for(int y=0; y<3; y++)
          if(board[row+x][column+y] == val) return false;
      return true;
  }
  bool solveSudoku(vector<vector<char>> &board, int i, int j)
  {
      if(i==9) return true;
      if(j==9) return solveSudoku(board, i+1, 0);
      if(board[i][j] != '.') return solveSudoku(board, i, j+1);

      for(char c='1'; c<='9'; c++)
      {
          if(check(board, i, j, c))
          {
              board[i][j] = c;
              if(solveSudoku(board, i, j+1)) return true;
              board[i][j] = '.';
          }
      }
          
      return false;
  }
  void solveSudoku(vector<vector>& board) {
    solveSudoku(board, 0, 0);
  }
};





/////////////////////
///  Solution 2  ///
///////////////////

// Time Complexity - O(9^(n^2))
// Space Complexity - O(n^2 + 3*n)

class Solution {
public:
    bool placeNums(vector<vector<char>>& board, int row, int col, vector<vector<bool>> &rowFlag, vector<vector<bool>> &colFlag, vector<vector<bool>> &boxFlag)
    {
        if(row == 9)
            return true;
        if(col == 9)
            return placeNums(board, row+1, 0, rowFlag, colFlag, boxFlag);
        
        if(board[row][col] != '.')
            return placeNums(board, row, col+1, rowFlag, colFlag, boxFlag);
        
        for(int num=1; num<=9; ++num)
        {
            if(
                // This number
                // isn't present in this ROW
                rowFlag[row][num] == false  &&
                // isn't present in this COLUMN
                colFlag[col][num] == false  &&
                // isn't present in this BOX
                boxFlag[3*(row/3) + col/3][num] == false
            )
            {
                board[row][col] = char('0'+num);
                rowFlag[row][num] = true;
                colFlag[col][num] = true;
                boxFlag[3*(row/3) + col/3][num] = true;

                // If we were able to fill the subsequent places using this num
                // then return TRUE
                if(placeNums(board, row, col+1, rowFlag, colFlag, boxFlag))
                    return true;
                
                // If we were unable to fill subsequent places using this num
                // Then backtrack previous config
                else
                {
                    board[row][col] = '.';
                    rowFlag[row][num] = false;
                    colFlag[col][num] = false;
                    boxFlag[3*(row/3) + col/3][num] = false;
                }
            }
        }
        // If board is empty at any place
        // then we haven't filled the sudoku
        // thus return FALSE
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rowFlag(9, vector<bool>(10, false));
        vector<vector<bool>> colFlag(9, vector<bool>(10, false));
        vector<vector<bool>> boxFlag(9, vector<bool>(10, false));
        
        // Hash already present numbers
        for(int row=0; row<9; ++row) {
            for(int col=0; col<9; ++col) {
                if(board[row][col] != '.') {
                    int num = board[row][col]-'0';
                    rowFlag[row][num] = true;
                    colFlag[col][num] = true;
                    boxFlag[3*(row/3) + col/3][num] = true;
                }
            }
        }
        
        placeNums(board, 0, 0, rowFlag, colFlag, boxFlag);
    }
};