// Time Complexity - O(n*n)     =>  erase takes O(n) time
// Space Complexity - O(n)
class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> tmp(n, 0);
        for(int i=1; i<=n; ++i) {
            tmp[i-1] = i;
            // Get factorial
            fact *= i;
        }
        fact /= n;
        
        // For 0-based indexing
        k -= 1;
        
        string ans;
        while(true) {
            // Take the number for answer
            ans += to_string(tmp[k/fact]);
            // Erase the positioned numbers from remaining numbers
            tmp.erase(tmp.begin() + k/fact);
            
            // If all numbers are positioned then BREAK
            if(tmp.size() == 0)
                break;
            
            k %= fact;
            fact /= tmp.size();
        }
        
        return ans;
    }
};