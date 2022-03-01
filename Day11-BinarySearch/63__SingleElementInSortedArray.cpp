/////////////////////
///  Solution 1  ///
///////////////////

// Time Complexity - O(n)
// Space Complexity - O(1)

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int len = nums.size();
        
        // If only single element present then it is 'answer'
        if(len == 1) {
            return nums[0];
        }
        
        
        // Check all non-edge elements
        for(int i=1; i<len-1; ++i) {
            if(nums[i] != nums[i-1]  &&  nums[i] != nums[i+1])
                return nums[i];
        }
        
        // If first element is odd one out
        if(nums[0] != nums[1])
            return nums[0];
        
        // If last element is odd one out
        if(nums[len-1] != nums[len-2])
            return nums[len-1];
        
        return -1;
    }
};






/////////////////////
///  Solution 2  ///
///////////////////

// Time Complexity - O(logn)
// Space Complexity - O(1)

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int len = nums.size();
        
        // If array is of size 1
        if(len == 1)
            return nums[0];
        
        int low = 0, high = len-1;
        
        while(low <= high) {
            int mid = (low+high)/2;
            
            // If this is EVEN index then its pair must be on RIGHT side
            // If the pair isn't on right side then it means the 'single element' has disturbed order
            // then surely the 'single element' must be on LEFT side of this index
            if(mid%2 == 0) {
                // Order is maintained until this element
                // thus 'single element' must be on right side
                if(nums[mid+1] == nums[mid])
                    low = mid+1;
                
                // Order is disturbed then surely 'single element'
                // has appeared on left side
                else
                    high = mid-1;
            }
            
            // If this is ODD index then its pair must be on LEFT side
            // If the pair isn't on left side then it means the 'single element' has disturbed order
            // then surely the 'single element' must be on RIGHT side of this index
            else {
                // Order is maintained until this element
                // thus 'single element' must be on right side
                if(nums[mid-1] == nums[mid])
                    low = mid+1;
                
                // Order is disturbed then surely 'single element'
                // has appeared on left side
                else
                    high = mid-1;
            }
        }
        
        return nums[low];
    }
};