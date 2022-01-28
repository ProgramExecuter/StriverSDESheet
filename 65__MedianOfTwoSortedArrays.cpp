// Time Complexity - O(log(m+n))
// Space Complexity - O(1)

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr1 = ( nums1.size() <  nums2.size() ) ? nums1 : nums2;
        vector<int> arr2 = ( nums1.size() >= nums2.size() ) ? nums1 : nums2;
        
        int n = arr1.size(), m = arr2.size();
        int low = 0, high = n;
        
        // arr1 -> array with lower size
        // arr2 -> array with higher size
        
        while(low <= high) {
            int mid = (low+high)/2;
            int cutPoint = (m+n+1)/2 - mid;
            
            // Divide the array into two parts
            // left an right
            int left1  = mid == 0       ? INT_MIN : arr1[mid-1];
            int left2  = cutPoint == 0  ? INT_MIN : arr2[cutPoint-1];
            int right1 = mid == n       ? INT_MAX : arr1[mid];
            int right2 = cutPoint >= m  ? INT_MAX : arr2[cutPoint];
            
            // Valid Cut
            if(left1 <= right2  &&  left2 <= right1) {
                double ans;
                
                if((m+n)%2 == 0) {
                    int ele1 = max(left1, left2);
                    int ele2 = min(right1, right2);

                    ans = (ele1 + ele2)/2.0;
                }
                else {
                    ans = 1.0*max(left1, left2);
                }
                
                return ans;
            }
            else if(left1 > right2)
                high = mid-1;
            else
                low = mid+1;
        }
        return 0.0;
    }
};