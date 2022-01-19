class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        
        // If size is less than 3 then NO answer
        if(n < 3) {
            return ans;
        }
        
        // Sort the array
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n; ++i) {
            int reqSum = 0 - nums[i];
            
            int front = i+1, back = n-1;
            
            while(front < back) {
                if(nums[front]+nums[back] == reqSum) {
                    // Push these 3 elements to 'ans'
                    ans.push_back({nums[i], nums[front], nums[back]});
                    
                    // Skip Duplicates of nums[front]
                    while(front+1 < n  &&  nums[front+1] == nums[front]) {
                        ++front;
                    }
                    
                    // Skip Duplicates of nums[back]
                    while(back-1 > i  &&  nums[back-1] == nums[back]) {
                        --back;
                    }
                    
                    // Move to next pair
                    ++front;
                    --back;
                }
                else if(nums[front]+nums[back] < reqSum) {
                    ++front;
                }
                else {
                    --back;
                }
            }
            
            // Skip duplicates of nums[i]
            while(i+1 < n  &&  nums[i+1] == nums[i]) {
                ++i;
            }
        }
        
        return ans;
    }
};