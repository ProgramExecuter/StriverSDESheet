/////////////////////
///  Solution 2  ///
///////////////////

// Time Complexity - O(logn)
// Space Complexity - O(1)

class Solution {
public:
    int search(vector<int>& nums, int target) {
        for(int i=0; i<nums.size(); ++i)
            if(nums[i] == target)
                return i;
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
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        
        while(low <= high) {
            int mid = (low+high)/2;
            
            if(nums[mid] == target)
                return mid;
            
            // We check if left side is sorted
            if(nums[low] <= nums[mid]) {
                // If the 'target' lies in left side
                if(target >= nums[low]  &&  target <= nums[mid])
                    high = mid-1;
                // If it doesn't
                else
                    low = mid+1;
            }
            else {
                // If the target lies in right side
                if(target >= nums[mid]  &&  target <= nums[high])
                    low = mid+1;
                // If it doesn't
                else
                    high = mid-1;
            }
        }
        return -1;
    }
};