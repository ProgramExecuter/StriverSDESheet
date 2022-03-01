/////////////////////
///  Solution 1  ///
///////////////////

// Time Complexity - O(nlogn)
// Space Complexity - O(1)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        
        // If the size is <= 1
        if(n <= 1) {
            return n;
        }
        
        sort(nums.begin(), nums.end());
        
        int ans = 1, currLength = 1;
        
        for(int i=0; i<n-1; ++i) {
            
            // Skip Repeating Numbers
            if(nums[i+1] == nums[i])
                continue;
            
            if(nums[i+1] == nums[i]+1) {
                ++currLength;
            }
            else {
                currLength = 1;
            }
            ans = max(ans, currLength);
            
        }
        ans = max(ans, currLength); 
        
        return ans;
    }
};



/////////////////////
///  Solution 2  ///
///////////////////

// Time Complexity - O(n)
// Space Complexity - O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash;
        
        // Insert all elements in hash
        for(int ele : nums) {
            hash.insert(ele);
        }
        
        int currLength = 1, ans = 0;
        
        // Traverse each element
        // And check if it's starting element of a sequence
        // If it's starting element then element-1 will not be present in 'hash'
        for(int ele : nums) {
            currLength = 1;
            
            // Starting Element
            if(hash.find(ele-1) == hash.end()) {
                int curr = ele;
                
                // Search for next element in sequence
                // while we find the next element in hash
                while(hash.find(++curr) != hash.end()) {
                    ++currLength;
                }
            }
            ans = max(ans, currLength);
        }
        return ans;
    }
};