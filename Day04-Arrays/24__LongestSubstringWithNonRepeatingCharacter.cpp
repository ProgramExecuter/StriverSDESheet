class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        
        // If the string is of size 0 or 1
        // return the length of string
        if(n <= 1) {
            return n;
        }
        
        int ans = 0, start = 0, end = 0;
        set<char> st;
        
        while(1) {
            if(end >= n  ||  start >= n) {
                break;
            }
            // If current characters didn't appear before
            // then increase the 'end' and insert this character
            if(st.find(s[end]) == st.end()) {
                st.insert(s[end]);
                ans = max(ans, end-start+1);
                ++end;
            }
            // If current character appeared before
            else {
                // Then increment 'start' until
                // s[start] = s[end]
                while(start < end  &&  s[start] != s[end]) {
                    st.erase(s[start]);
                    ++start;
                }
                // Remove the 'front' element from set
                st.erase(s[start]);
                ++start;
            }
        }
        return ans;
    }
};