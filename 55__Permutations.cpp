////////////////////
///  Solution 1 ///
//////////////////


// Time Complexity - O(n! * n)
// Space Complexity - O(n)      -->  Extra Space for 'vis'
class Solution {
public:
    void permutation(vector<int>& nums, vector<vector<int>> &ans, vector<int> &curr, vector<bool> &vis) {
        // If 'curr' has all elements then it is a permutation
        // push 'curr' to 'ans'
        if(curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }
        
        
        for(int i=0; i<nums.size(); ++i) {
            // If this element is not visted push it to 'curr'
            // and make it visited
            if(vis[i] == false) {
                curr.push_back(nums[i]);
                vis[i] = true;
                
                permutation(nums, ans, curr, vis);
                
                // Get back to previous condition
                curr.pop_back();
                vis[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums)
    {
        int len = nums.size();
        vector<vector<int>> ans;
        vector<int> curr;
        vector<bool> vis(len, false);
        
        permutation(nums, ans, curr, vis);
        
        return ans;
    }
};




////////////////////
///  Solution 2 ///
//////////////////

// Time Complexity - O(n! * n)
// Space Complexity - O(1)      --> No Extra Space
class Solution {
public:
    void permutation(vector<int>& nums, vector<vector<int>> &ans, int idx) {
        // We have reached end of array
        if(idx == nums.size()) {
            ans.push_back(nums);
            return;
        }
        
        for(int i = idx; i < nums.size(); ++i) {
            // Swap 'idx' element with this element
            // to get a permutation
            swap(nums[i], nums[idx]);
            permutation(nums, ans, idx + 1);
            // Swap them back to previous
            swap(nums[i], nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> ans;
        
        permutation(nums, ans, 0);
        
        return ans;
    }
};