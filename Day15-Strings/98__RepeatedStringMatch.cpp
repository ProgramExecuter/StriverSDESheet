/////////////////////
///  Solution 1  ///
///////////////////

// Time Complexity  - O(m * n)
// Space Complexity - O(1)

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int n = a.size(), m = b.size();
        
        // Check for start of substring
        for(int i=0, j=0; i<n; ++i) {
            int cnt = 1;
            
            // Check character by character
            for(j=0; j<m; ++j) {
                if( a[(i+j)%n] != b[j] ) {
                    break;
                }
                
                // Reached end of 1st string
                if((i+j) != 0  &&  (i+j)%n == 0) {
                    ++cnt;
                }
            }
            
            if(j == m) {
                return cnt;
            }
        }
        
        return -1;
    }
};





/////////////////////
///  Solution 2  ///
///////////////////

// Time Complexity  - O(m * n)
// Space Complexity - O(1)