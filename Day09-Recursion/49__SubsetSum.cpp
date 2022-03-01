// Time Complexity - O(2^n)
// Space Complexity - O(2^n)

class Solution
{
public:
    void subsetSum(vector<int> arr, int i, int sum, vector<int> &st, int n)
    {
        if(i == n-1)
        {
            st.push_back(sum+arr[i]);
            st.push_back(sum);
            return;
        }
        subsetSum(arr, i+1, sum, st, n);
        subsetSum(arr, i+1, sum+arr[i], st, n);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> ans;
        subsetSum(arr, 0, 0, ans, N);
        sort(ans.begin(), ans.end());
        return ans;
    }
};