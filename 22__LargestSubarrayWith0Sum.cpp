class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {
        // Map for getting sums at different positions
        unordered_map<int, int> mp;
        
        int sum = 0, ans = 0;
        for(int i=0; i<n; ++i) {
            sum += A[i];
            
            // If sum==0 then take answer
            if(sum == 0) {
                ans = max(ans, i+1);
                continue;
            }
            
            // If the sum isn't in the map
            // then put the sum in the map
            if(mp.find(sum) == mp.end()) {
                mp[sum] = i;
            }
            // If we find the sum previously then compare its length with 'ans'
            else {
                ans = max(ans, i-mp[sum]);
            }
        }
        return ans;
    }
};
