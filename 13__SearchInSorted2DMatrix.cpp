// Time Complexity - O(log(m*n)) = O(log(m) + log(n))
// Space Complexity - O(1)
class Solution {
public:
    int findRow(vector<vector<int>>& matrix, int target, int m) {
        int rowNo = -1;
        
        // Find the row
        int low = 0, high = m-1;
        while(low <= high) {
            int mid = (high+low)/2;
            
            if(matrix[mid][0] > target) {
                high = mid-1;
            }
            else if(matrix[mid][0] < target) {
                rowNo = mid;
                low = mid+1;
            }
            else {
                rowNo = mid;
                break;
            }
        }
        
        return rowNo;
    }
    bool findElement(vector<vector<int>>& matrix, int target, int rowNo, int n) {
        // Find the element
        int low = 0, high = n-1;
        while(low <= high) {
            int mid = (high+low)/2;
            
            if(matrix[rowNo][mid] > target) {
                high = mid-1;
            }
            else if(matrix[rowNo][mid] < target) {
                low = mid+1;
            }
            else {
                return true;
            }
        }
        
        // We weren't able to find the element in given row
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        
        // Find the row for 'target'
        int rowNo = findRow(matrix, target, m);
        
        // If unable to find the 'row'
        // then element not available
        if(rowNo < 0) {
            return false;
        }
        
        return findElement(matrix, target, rowNo, n);
    }
};