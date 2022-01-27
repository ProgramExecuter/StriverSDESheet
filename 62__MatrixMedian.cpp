int greaterThan(vector<int> &row, int num) {
    int low = 0, high = row.size()-1; 
    
    while(low <= high) {
        int mid = (low+high)/2; 
        if(row[mid] <= num)
            low = mid+1;
        else
            high = mid-1;
    }
    return low; 
}
int getMedian(vector<vector<int>> &matrix)
{
    int m = matrix.size(), n = matrix[0].size();
    
    // These are range of numbers in matrix
    int low = 1, high = 1e5, ans = 0;
    
    while(low <= high) {
        int mid = (high+low)/2;
        
        // Get the number of elements than are less than this 'mid'
        int cnt = 0;
        for(int i=0; i<m; ++i)
            cnt += greaterThan(matrix[i], mid);
        
        if(cnt <= (m*n)/2)
            low = mid+1;
        else
            high = mid-1;
    }
    return low;
}