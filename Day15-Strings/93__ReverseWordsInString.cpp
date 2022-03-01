/////////////////////
///  Solution 1  ///
///////////////////

// Time Complexity - O(n)
// Space Complexity - O(n)

class Solution {
public:
    string reverseWords(string s) {
        int len = s.size();
        stack<string> st;
        
        int idx = 0;
        string curr, ans;
        
        while(idx < len) {
            // We've encountered space so push current string to stack
            if(s[idx] == ' '  &&  curr.size() > 0) {
                st.push(curr);
                curr = "";
            }
            
            // Skip white spaces
            while(idx < len  &&  s[idx] == ' ') {
                ++idx;
            }
            
            // End of the string
            if(idx == len)  break;
            
            curr += s[idx++];
        }
        
        while(!st.empty()) {
            if(curr.size() > 0)
                ans += curr + " ";
            
            curr = st.top();
            st.pop();
        }
        ans += curr;
        
        return ans;
    }
};





/////////////////////
///  Solution 2  ///
///////////////////

// Time Complexity - O(n)
// Space Complexity - O(1)

class Solution {
public:
    void removeExtraSpaces(string &s) {
        int i = 0;
        
        while(i < s.size()) {
            // Remove trailing spaces
            if((i == 0  ||  i == s.size()-1)  &&  s[i] == ' ')
                s.erase(s.begin()+i);
            // Remove middle extra spaces
            else if(i < s.size()-1  &&  s[i] == ' '  &&  s[i+1] == ' ')
                s.erase(s.begin()+i);
            else
                ++i;
        }
    }
    string reverseWords(string s) {
        removeExtraSpaces(s);
        
        reverse(s.begin(), s.end());
        
        int idx = 0, pos = 0;
        
        // Reverse word by word
        while(idx < s.size()) {
            // Skip characters
            while(idx < s.size()  &&  s[idx] != ' ')
                ++idx;
            
            if(idx == s.size())
                break;
            
            reverse(s.begin()+pos, s.begin()+idx);
            ++idx;
            pos = idx;
        }
        reverse(s.begin()+pos, s.begin()+idx);
        
        return s;
    }
};