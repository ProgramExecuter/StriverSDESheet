/////////////////////
///  Solution 1  ///
///////////////////

// Time Complexity - O(2^n * n^2)    ==>  n^2 -> for checking each string for palindrome
// Space Complexity - O(2^n)

class Solution {
public:
    // Check if a string is palindrome or not
    bool isPalindrome(string s) {
        int n = s.size();
        for(int i=0; i<n/2; ++i) {
            if(s[i] != s[n-1-i])
                return false;
        }
        return true;
    }
    // Check if all strings of vector are palindrome
    bool checkPalin(vector<string> curr) {
        for(string s : curr) {
            // If any string is not a palindrome
            // then ans is false;
            if(!isPalindrome(s))
                return false;
        }
        
        return true;
    }
    void subString(string s, int idx, vector<vector<string>> &ans, vector<string> &curr) {
        if(idx == s.size()) {
            if(checkPalin(curr)) {
                ans.push_back(curr);
            }
            return;
        }
        
        // Add this character to new string
        string tmp;     tmp += s[idx];
        curr.push_back(tmp);
        subString(s, idx+1, ans, curr);
        curr.pop_back();
        
        if(curr.size() > 0) {
            // Add this character to last string
            curr[curr.size()-1] += s[idx];
            subString(s, idx+1, ans, curr);
            curr[curr.size()-1].erase(curr[curr.size()-1].size()-2, 1);
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        
        subString(s, 0, ans, curr);
        
        return ans;
    }
};





/////////////////////
///  Solution 2  ///
///////////////////

// Time Complexity - O(2^n * n)
// Space Compllexity - O(2^n)

// In this approach, we check if taken substring is plaindrome
// thus reducing time complexity by 'n
class Solution {
public:
    // Check if a string is palindrome or not
    bool isPalindrome(string s, int st, int en) {
        while(st < en) {
            if(s[st++] != s[en--])
                return false;
        }
        return true;
    }
    void subString(string s, int idx, vector<vector<string>> &ans, vector<string> &curr) {
        if(idx == s.size()) {
            ans.push_back(curr);
            return;
        }
        
        for(int i=idx; i<s.size(); ++i) {
            // If taken substring is palindrome
            if(isPalindrome(s, idx, i)) {
                // Push this substring to 'curr'
                curr.push_back(s.substr(idx, (i-idx+1)));
                subString(s, i+1, ans, curr);
                // Get previous 'curr'
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        
        subString(s, 0, ans, curr);
        
        return ans;
    }
};