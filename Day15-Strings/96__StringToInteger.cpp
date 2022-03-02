class Solution {
public:
    int convertToNum(string num) {
        int ans = 0;
        
        for(char ch : num) {
            ans = ans*10 + (ch-'0');
        }
        
        return ans;
    }
    int myAtoi(string s) {
        int n = s.size(), i = 0;
        
        // Skip white spaces
        while(i<n && s[i] == ' ') {
            ++i;
        }
        
        int st = -1, en = -1;
        bool hasSign = false, posNum = true, firstNum = true;
        
        while(i<n) {
            char ch = s[i];
            
            if(ch == '+'  ||  ch == '-') {
                if(!firstNum) {
                    en = i-1;
                    break;
                }
                // If first time SIGN is reached
                if(!hasSign) {
                    hasSign = true;
                    if(ch == '-')
                        posNum = false;
                }
                // If sign has already been read once
                // then end the number string
                else {
                    en = i-1;
                    break;
                }
            }
            else if(ch >= '0'  &&  ch <= '9') {
                // If this is first number encountered
                // Then mark this as start
                if(firstNum) {
                    st = i;
                    firstNum = false;
                }
            }
            // For any other character end the number string
            else {
                en = i-1;
                break;
            }
            
            ++i;
        }
        if(i == n)
            en = i-1;
        
        if(st < 0 || en < 0)
            return 0;
        
        // Skip Zeros
        for(int i=st; i<en; ++i) {
            if(s[i] == '0') {
                ++st;
            }
            else {
                break;
            }
        }
        
        // Length of number string
        int lenNum = en-st+1, ans = 0;
        
        string minNum = "2147483648", maxNum = "2147483647";
        string numString = s.substr(st, lenNum);
        
        // cout<<numString<<endl;
        
        // Then it will not go out of range
        if(lenNum < 10) {
            ans = convertToNum(numString);
            if(!posNum)
                ans *= -1;
        }
        // If will definitely overflow
        // Hence we return the maximum from the sides
        else if(lenNum > 10) {
            if(posNum)
                return INT_MAX;
            else
                return INT_MIN;
        }
        // May or may not overflow
        else {
            if(posNum) {
                if(numString.compare(maxNum) >= 0)
                    return INT_MAX;
                else
                    ans = convertToNum(numString);
            }
            else {
                if(numString.compare(minNum) >= 0)
                    return INT_MIN;
                else
                    ans = convertToNum(numString);
            }
            if(!posNum)
                ans *= -1;
        }
        
        return ans;
    }
};