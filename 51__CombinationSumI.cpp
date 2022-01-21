class Solution {
public:
    void subsets(vector<int> &candidates, int i, vector<vector<int>> &ans, vector<int> &curr, int reqZero) {
        if(i == candidates.size()) {
            if(reqZero == 0)
                ans.push_back(curr);
            return;
        }
        
        // Don't pick it
        subsets(candidates, i+1, ans, curr, reqZero);
        
        // Pick It
        if(reqZero >= candidates[i]) {
            curr.push_back(candidates[i]);
            subsets(candidates, i, ans, curr, reqZero-candidates[i]);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        
        subsets(candidates, 0, ans, curr, target);
        
        return ans;
    }
};