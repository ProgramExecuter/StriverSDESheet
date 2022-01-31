void sortStack(stack<int> &st)
{
    stack<int> tmp;
    int n = st.size();
    
    for(int i=0; i<n; ++i) {
        int tp = st.top();
        st.pop();
        
        // Remove (n-i) elements and find lowest from them
        for(int j=i+1; j<n; ++j) {
            int curr = st.top();
            st.pop();
            if(curr < tp)
                swap(curr, tp);
            tmp.push(curr);
        }

        // Put lowest element into 'st'
        st.push(tp);
        
        // Put the removed elements back
        while(!tmp.empty()) {
            st.push(tmp.top());
            tmp.pop();
        }
    }
}