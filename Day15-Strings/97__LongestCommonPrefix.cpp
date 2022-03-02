// Time Complexity - O(m*n)
// Space Complexity - O(n)

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        
        // Find the prefix
        for(int i = 0; i < strs.size(); ++i) {
            int minSize = min(strs[i].size(), ans.size());
            int j = 0;
            
            while(j < minSize) {
                // This character doesn't match
                if(strs[i][j] != ans[j])
                    break;
                ++j;
            }
            
            // Decrease the size of prefix by >= 0
            ans = ans.substr(0, j);
        }
        
        return ans;
    }
};