/////////////////////
///  Solution 1  ///
///////////////////

// Time Complexity - O(2^n * n)
// Space Complexity - O(1)

vector<vector<int>> pwset(vector<int>v)
{
    int n = v.size();
    vector<vector<int>> ans;
    
    // We loop for [0, 2^n -1]
    for(int i = 0; i < (1<<n); ++i) {
        vector<int> tmp;
        
        // We check each bit of this 'i' number
        for(int j=0; j<n; ++j) {
            int bit = (i>>j) & 1;
            
            // If this bit is set
            // push corresponding number into the answer
            if(bit == 1)
                tmp.push_back(v[j]);
        }
        
        ans.push_back(tmp);
    }
    
    return ans;
}




/////////////////////
///  Solution 2  ///
///////////////////

// Time Complexity - O(2^n)
// Space Complexity - O(n)      =>  'n' for recursive stack

#include<bits/stdc++.h>
void allSeq(int idx, vector<int> &v, vector<vector<int>> &ans, vector<int> &curr) {
    if(idx == v.size()) {
        ans.push_back(curr);
        return;
    }
    
    // Don't push this element
    allSeq(idx+1, v, ans, curr);
    
    // Push this element
    curr.push_back(v[idx]);
    allSeq(idx+1, v, ans, curr);
    // Backtrack
    curr.pop_back();
}
vector<vector<int>> pwset(vector<int>v)
{
    vector<vector<int>> ans;
    vector<int> curr;
    
    allSeq(0, v, ans, curr);
    
    return ans;
}