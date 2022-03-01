/////////////////
// Solution 1 //
///////////////

// Time Complexity - O(n^2)
// Space Comlexity - O(n^2)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> ans(n, vector<int>(n, 0));
        
        // Take a different matrix
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                ans[i][j] = matrix[n-1-j][i];
            }
        }
        
        // Copy the answer into matrix
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                matrix[i][j] = ans[i][j];
            }
        }
    }
};




/////////////////
// Solution 2 //
///////////////

// Time Complexity - O(n^2)
// Space Comlexity - O(1)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int len = matrix.size();
        
        // Take TRANSPOSE of matrix
        for(int i=0; i<len; ++i) {
            for(int j=0; j<i; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        // Reverse each row
        for(int i=0; i<len; ++i) {
            // Use two pointer
            for(int j=0; j<len/2; ++j) {
                swap(matrix[i][j], matrix[i][len-1-j]);
            }
        }
    }
};