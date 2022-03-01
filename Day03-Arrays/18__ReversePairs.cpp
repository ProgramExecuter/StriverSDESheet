// Time Complexity - O( nlogn + n + n )
// NlogN - for sorting,  N - for getting answer,  N - for copying
// Space Complexity - O(n)
class Solution {
public:
    // This function takes into account the case of OVERFLOW!!
    bool check(int x, int y) {
        // If the X is <= 2* Y
        // then return true
        
        if(x/2 < y) {
            return true;
        }
        else if(x/2 > y) {
            return false;
        }
        else {
            // If x/2 == y
            
            // If there is an extra +1 in X
            // then return FALSE
            if(x%2 == 1)
                return false;
            
            // Else return TRUE
            return true;
        }
    }
    int merge(vector<int>& nums, int low, int mid, int high) {
        int ans = 0;
        
        int i=low, j=mid+1;
        vector<int> tmp;
        
        // Do this for all "j" array's elements
        while(j <= high) {
            // Find the position in "i" array
            // whose's element is > 2*nums[j]
            while(i <= mid  &&  check(nums[i], nums[j])) {
                ++i;
            }
            // If we don't find such position
            // break from the loop
            if(i > mid)
                break;
            
            // If this position's element is > 2*nums[j]
            // then its subsequent elements will be as well
            ans += (mid-i+1);
            
            ++j;
        }
        
        //
        // Simply merge two sorted arrays
        i = low, j = mid+1;
        while(i <= mid  &&  j <= high) {
            if(nums[i] < nums[j])
                tmp.push_back(nums[i++]);
            else
                tmp.push_back(nums[j++]);
        }
        
        // Push the remaining elements from any array
        while(i <= mid)
            tmp.push_back(nums[i++]);
        
        while(j <= high)
            tmp.push_back(nums[j++]);
        
        // Copy the 'temp' array in 'nums'
        for(int i=low; i<=high; ++i) {
            nums[i] = tmp[i-low];
        }
        
        return ans;
    }
    int mergeSort(vector<int>& nums, int low, int high) {
        if(low >= high) {
            return 0;
        }
        
        int mid = (low+high)/2;
        
        int ans = 0;
        ans += mergeSort(nums, low, mid);
        ans += mergeSort(nums, mid+1, high);
        ans += merge(nums, low, mid, high);
        
        return ans;
    }
    int reversePairs(vector<int>& nums) {
        int st = 0, en = nums.size()-1;

        int ans = mergeSort(nums, st, en);
        
        return ans;
    }
};