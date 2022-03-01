int findCelebrity(int n) {
    stack<int> st;
    
    // Push all people in stack
    for(int i=0; i<n; ++i)
        st.push(i);
    
    // While there is more than 1 person in stack
    while(st.size() > 1) {
        // Get 1st and 2nd person
        int man1 = st.top();
        st.pop();
        int man2 = st.top();
        st.pop();
        
        // If 'man1' knows 'man2'
        // 'man1' cannot be a celebrity
        // then 'man2' can be a celebrity
        if(knows(man1, man2))
            st.push(man2);
        // else 'man1' can be celebrity
        else
            st.push(man1);
    }
    
    // This person can be a celebrity
    int canCeleb = st.top();
    st.pop();
    
    // Check if this person doesn't know anyone
    for(int i=0; i<n; ++i) {
        // If 'canCeleb' knows someone
        // then no celebrity found
        if(knows(canCeleb, i))
            return -1;
    }
    
    // Check if everyone knows this person
    for(int i=0; i<n; ++i) {
        if(i == canCeleb)
            continue; // Skip 'canCeleb' itself
        
        // Atleast 1 person doesn't know 
        // So no celebrity
        if(!knows(i, canCeleb))
            return -1;
    }
    
    return canCeleb;
}