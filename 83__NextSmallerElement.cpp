vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> ans(n, -1);
    stack<int> st;

    for(int i=n-1; i>=0; --i) {
        int ele = arr[i];
        
        while(!st.empty()  &&  st.top() >= ele)
            st.pop();
        
        // We found element < currEle in the right
        if(!st.empty())
            ans[i] = st.top();
        
        st.push(ele);
    }

    return ans;
}