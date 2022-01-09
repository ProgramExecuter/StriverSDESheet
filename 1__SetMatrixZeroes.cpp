///////////////////////
///   SOLUTION 1   ///
/////////////////////

// This solution works only on positive range
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int nRow = matrix.size(), nCol = matrix[0].size();
        
        for(int row = 0; row < nRow; ++row) {
            for(int col = 0; col < nCol; ++col) {
                // If element is 0
                // then set its row and col elements to be -1
                if(matrix[row][col] == 0) {
                    // Set col elements to be -1 if it isn't 0
                    int i = 0;
                    for(; i < nRow; ++i) {
                        if(matrix[i][col] != 0)
                            matrix[i][col] = -1;
                    }
                    
                    //Set row elements to be -1 if it isn't 0
                    i = 0;
                    for(; i < nCol; ++i) {
                        if(matrix[row][i] != 0)
                            matrix[row][i] = -1;
                    }
                }
            }
        }
        
        // If the element <= 0 then set it to be 0
        for(int row = 0; row < nRow; ++row) {
            for(int col = 0; col < nCol; ++col) {
                if(matrix[row][col] <= 0)
                    matrix[row][col] = 0;
            }
        }
    }
};



///////////////////////
///   SOLUTION 2   ///
/////////////////////

// In this solution we make use of extra space
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int nRow = matrix.size(), nCol = matrix[0].size();
        
        vector<int> rowFlags(nRow, 1), colFlags(nCol, 1);
        
        for(int row = 0; row < nRow; ++row) {
            for(int col = 0; col < nCol; ++col) {
                // If the element is 0 then
                // make 'flags' of row and col = 0
                if(matrix[row][col] == 0) {
                    rowFlags[row] = 0;
                    colFlags[col] = 0;
                }
            }
        }
        
        // If the element <= 0 then set it to be 0
        for(int row = 0; row < nRow; ++row) {
            for(int col = 0; col < nCol; ++col) {
                // If the flag of row or col is 0
                // then make the element to be 0
                if(rowFlags[row] == 0  ||  colFlags[col] == 0) {
                    matrix[row][col] = 0;
                }
            }
        }
    }
};



///////////////////////
///   SOLUTION 3   ///
/////////////////////

// Optimum Solution
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int nRow = matrix.size(), nCol = matrix[0].size();
        
        int colFlag = 1;
        
        for(int row = 0; row < nRow; ++row) {
            for(int col = 0; col < nCol; ++col) {
                if(matrix[row][col] == 0) {
                    // If its first col
                    // then we make use of 'colFlag'
                    if(col == 0) {
                        // Make first col flag = 0
                        colFlag = 0;
                        // Make first element in row = 0
                        // matrix[row][0] = 0;
                    }
                    else {
                        // Make first element in col = 0
                        matrix[0][col] = 0;
                        // Make first element in row = 0
                        matrix[row][0] = 0;
                    }
                }
            }
        }
        
        // Start from end of matrix to avoid problem
        // of initializing the flag area of matrix
        for(int row = nRow-1; row >= 0; --row) {
            for(int col = nCol-1; col >= 0; --col) {
                if(col == 0) {
                    // If row or 'colFlag' = 0
                    // then make the element 0
                    if(colFlag == 0  ||  matrix[row][0] == 0)
                        matrix[row][col] = 0;
                }
                else {
                    // If the row or col flag = 0
                    // then make the element 0
                    if(matrix[row][0] == 0  ||  matrix[0][col] == 0)
                        matrix[row][col] = 0;
                }
            }
        }
    }
};