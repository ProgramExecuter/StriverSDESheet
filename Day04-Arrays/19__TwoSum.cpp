// Time Complexity - O(n)   Since the searching in map is O(1)
// Space Complexity - O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        
        // Insert the elements in map
        unordered_map<int, int> mp;
        
        // Take one element
        for(int i=0; i<n; ++i) {
            // Find its counterpart for sum = 'target'
            if(mp.find(target-nums[i]) != mp.end()) {
                // If we found the counterpart then return these numbers
                return {mp[target-nums[i]], i};
            }
            mp[nums[i]] = i;
        }
        
        return {};
    }
};