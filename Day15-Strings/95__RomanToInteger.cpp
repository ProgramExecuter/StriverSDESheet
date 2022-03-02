// Time Complexity - O(n)
// Space Complexity - O(1)

class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        int n = s.size();
        for(int i=0; i<n; ++i)
        {
            int temp = 0;
            if(s[i] == 'I') {
                // If it is before V or X then it is subtracted
                if(i<n-1 && (s[i+1]=='V' || s[i+1]=='X'))
                    temp = -1;
                // Else it is added
                else
                    temp = 1;
            }
            else if(s[i] == 'X') {
                // If it is before L or C then it is subtracted
                if(i<n-1 && (s[i+1]=='L' || s[i+1]=='C'))
                    temp = -10;
                // Else it is added
                else
                    temp = 10;
            }
            else if(s[i] == 'C') {
                // If it is before D or M then it is subtracted
                if(i<n-1 && (s[i+1]=='D' || s[i+1]=='M'))
                    temp = -100;
                // Else it is added
                else
                    temp = 100;
            }
            else if(s[i] == 'V') {
                temp = 5;
            }
            else if(s[i] == 'L') {
                temp = 50;
            }
            else if(s[i] == 'D') {
                temp = 500;
            }
            else if(s[i] == 'M') {
                temp = 1000;
            }
            ans += temp;
        }
        return ans;
    }
};