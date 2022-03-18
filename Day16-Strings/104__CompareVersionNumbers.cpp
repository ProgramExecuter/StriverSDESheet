// Time Complexity - O(n + m)
// Space Complexity - O(1)

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0, n1 = version1.size(), n2 = version2.size();
        
        while(i < n1  ||  j < n2) {
            int num1 = 0, num2 = 0;
            
            // Find version1's current revision's 'num'
            while(i < n1  &&  version1[i] != '.') {
                num1 = num1*10 + (version1[i]-48);
                ++i;
            }
            
            // Find version2's current revision's 'num'
            while(j < n2  &&  version2[j] != '.') {
                num2 = num2*10 + (version2[j]-48);
                ++j;
            }
            
            // If the versions aren't at end
            // then skip '.'
            if(i < n1)      ++i;
            if(j < n2)      ++j;
            
            
            if(num1 > num2)
                return 1;
            else if(num1 < num2)
                return -1;
        }
        
        return 0;
    }
};