// Time Complexity - O(logn)
// Space Complexity - O(1)
class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        
        // Taking N as long long for the case n = INT_MIN
        // since integer goes from -2^31  ->  2^31-1
        // we have one less range in +ve side
        long long tmpN = n;
        
        // Make temporary N positive
        if(tmpN < 0) {
            tmpN *= -1;
        }
        
        while(tmpN) {
            // If N is odd
            if(tmpN%2) {
                ans *= x;
                --tmpN;
            }
            // If N is even
            else {
                x *= x;
                tmpN /= 2;
            }
        }
        
        if(n < 0) {
            ans = (double(1.0))/ans;
        }
        
        return ans;
    }
};