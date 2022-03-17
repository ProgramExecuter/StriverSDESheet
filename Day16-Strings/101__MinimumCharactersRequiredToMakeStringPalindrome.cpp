vector<int> computeLPSArray(string str)
{
    int M = str.length(), len = 0, i = 1;;
    
    vector<int> lps(M);
    lps[0] = 0;

    while (i < M) {
        if (str[i] == str[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len-1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}
int Solution::solve(string A) {
    string tmp;
    tmp += A;
    reverse(A.begin(), A.end());
    tmp += "*" + A;

    vector<int> lps = computeLPSArray(tmp);

    return (A.size() - lps.back());
}