class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int curr = nums[0];
        int cnt = 0;
        
        for(int ele : nums) {
            // If this element is same as 'curr'
            // Increase 'cnt'
            if(ele == curr) {
                ++cnt;
            }
            // If it isn't then decrease 'count'
            else {
                --cnt;
            }
            
            // If the 'count' becomes 0
            // then make current element as answer
            if(cnt == 0) {
                curr = ele;
                cnt = 1;
            }
        }
        
        return curr;
    }
};