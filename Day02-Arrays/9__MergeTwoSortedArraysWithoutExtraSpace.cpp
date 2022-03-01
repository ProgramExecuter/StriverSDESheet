// Time Complexity - O(m+n)
// Space Complexity - O(1)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1, j = n-1, k = m+n-1;
        
        // Start from end of both arrays
        for(; k>=0 && i>=0 &&j>=0; --k) {
            if(nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                --i;
            }
            else {
                nums1[k] = nums2[j];
                --j;
            }
        }
        
        // Remaining elements of 'nums1'
        while(k >= 0  &&  i >= 0) {
            nums1[k] = nums1[i];
            --i;    --k;
        }
        
        //Remaining elements of 'nums2'
        while(k >= 0  &&  j >= 0) {
            nums1[k] = nums2[j];
            --j;    --k;
        }
    }
};