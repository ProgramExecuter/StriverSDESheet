class Solution {
public:
    vector<int> lps(string needle) {
        int n = needle.size();
        
        vector<int> res(n, 0);
        
        for (int i = 1, len = 0; i < n;) {
            if (needle[i] == needle[len])
                res[i++] = ++len;
            else if(len > 0)
                len = res[len - 1];
            else
                res[i++] = 0;
        }
        
        return res;
    }
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        
        if(n == 0)
            return 0;
        if(m == 0)
            return -1;
        
        vector<int> table = lps(needle);
        
        for(int i=0, j=0; i<m;) {
            if (haystack[i] == needle[j]) { 
                i++, j++;
            }
            if(j == n) {
                return i - j;
            }
            if(i < m  &&  haystack[i] != needle[j]) {
                j ? j = table[j - 1] : i++;
            }
        }
        return -1;
    }
};