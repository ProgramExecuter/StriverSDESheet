int Solution::solve(vector<int> &A, int B) {
    int xr = 0, cnt = 0;
    unordered_map<int, int> mp;

    for(int x=0; x<A.size(); ++x) {
        int i = A[x];
        // XOR the prefix with current element
        xr = xr^i;

        if(xr == B) {
            ++cnt;
        }

        // If we get Y = XR^B
        int tmpY = xr^B;
        if(mp.find(tmpY) != mp.end()) {
            cnt += mp[tmpY];
        }

        mp[xr]++;
    }

    return cnt;
}
