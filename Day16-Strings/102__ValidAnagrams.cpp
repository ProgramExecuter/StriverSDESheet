// Time Complexity - O(n)
// Space Complexity - O(n)

class Solution {
public:
    bool isAnagram(string s, string t) {
        // If the lengths of both strings are different
        // then return false
        if(s.length() != t.length())
            return false;
        
        // Save frequency of each character
        int cnt[26] = {0};
        for(int i=0; i<s.length(); ++i)
        {
            ++cnt[s[i]-'a'];
            --cnt[t[i]-'a'];
        }
        
        // If the frequency of all characters in both strings are same
        // then the strings are anagram of each other
        for(int x : cnt)
        {
            if(x != 0)
                return false;
        }
        return true;
    }
};