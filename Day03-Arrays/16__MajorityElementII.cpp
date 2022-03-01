// Time Complexity - O(n)
// Space Complexity O(1)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        
        int cnt1 = 0, cnt2 = 0;
        int result1 = INT_MAX, result2 = INT_MAX;
        
        for(int num : nums) {
            
            // If current number matches 'result1'
            // Then increment its count
            if(num == result1)
                cnt1++;
            // Else it matches matches 'result2'
            // Increment its count
            else if(num == result2)
                cnt2++;
            // If the result1 changes
            else if(cnt1 == 0) {
                result1 = num;
                cnt1 = 1;
            }
            // If result2 changes
            else if(cnt2 == 0) {
                result2 = num;
                cnt2 = 1; 
            }
            // If the number doesn't match any number
            // then decrement both result's count
            else { 
                cnt1--; 
                cnt2--;
            }
        }
        
        // Verify if  both results are present > n/3 times
        cnt1 = cnt2 = 0;
        for(int num : nums) {
            if(num == result1)
                cnt1++;
            else if(num == result2)
                cnt2++;
        }
        
        if(cnt1 > n/3)
            result.push_back(result1);
        if(cnt2 > n/3) 
            result.push_back(result2);
        
        return result;
    }
};
//Credit : RainbowSecret