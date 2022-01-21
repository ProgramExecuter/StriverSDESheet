class Solution {
public:
    void subsets(vector<int> &arr, int target, int start, vector<int> &curr, vector<vector<int>> &ans) {
        if(target == 0) {
            ans.push_back(curr);
            return;
        }
        
        for(int i=start; i<arr.size(); ++i) {
            // Don't take duplicates
            if(i > start && arr[i]==arr[i-1])
                continue;
            
            // If this element is greater than 'target'
            // then rest of the elements will be greater as well
            if(arr[i] > target)
                break;
            
            // Call next permutation
            curr.push_back(arr[i]);
            subsets(arr, target-arr[i], i+1, curr, ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        
        vector<vector<int>> ans;
        vector<int> curr;
        
        subsets(candidates, target, 0, curr, ans);
        
        return ans;
    }
};