// Time Complexity - O(2^n)
// Space Complexity - O(2^n)
class Solution {
public:
    void util(vector<vector<int>> &ans, vector<int> &nums, vector<int> &curr, int begin) {
		// Push the current vector into 'ans'
        ans.push_back(curr);
        
		for(int i = begin; i < nums.size(); ++i) {
            // Skip the duplicates
			if(i == begin || nums[i] != nums[i-1]) { 
				curr.push_back(nums[i]);
				util(ans, nums, curr, i+1);
				
                // Remove this element
                curr.pop_back();
			}
        }
	}
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
		// Sort the array so we can skip the duplicates
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        vector<int> curr;
		
        util(ans, nums, curr, 0);
		
        return ans;
    }
};