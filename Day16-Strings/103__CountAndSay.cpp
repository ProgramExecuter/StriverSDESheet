// Time Comlexity - O(2^n)
// Space Complexity - O(2^n)

class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        
        for(int i = 2; i <= n; i++) {
            string tmp = "";
            
            // Previous number and its count
            int prev = (ans[0] - 48), cnt = 1;
            
            for(int j = 1; j < ans.size(); ++j) {
                // Current number
                int curr = ans[j] - 48;
                
                // Increase 'cnt' if 'curr' == previous number
                if(curr == prev) {
                    ++cnt;
                }
                else {
                    // Add 'cnt'+'num' to answer
                    tmp += char(48 + cnt);
                    tmp += char(48 + prev);
                    
                    // Make this distinct number as new 'prev'
                    prev = curr;
                    cnt = 1;
                }
            }
            
            // Add 'cnt'+'num' to answer
            tmp += char(48 + cnt);
            tmp += char(48 + prev);
            
            // Assign this as new answer
            ans = tmp;
        }
        
        return ans;
    }
};