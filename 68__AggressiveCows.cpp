// Time Complexity - O(nlogn)
// Space Complexity - O(1)
bool isPossible(vector<int> positions , int gap ,  int c) {
    // We place a single player
    int canPlaced = 1, prev = positions[0], n = positions.size();
    
    // We start checking from second element
    int i = 1;
    while(i < n) {
        // Find the right position
        while(i<n  &&  positions[i]<prev+gap)
            ++i;
        // If we couldn't find it BREAK
        if(i >= n)
            break;
        // If found increase count
        ++canPlaced;
        prev = positions[i++];
    }
    // If we can place >= players than required
    // then return TRUE
    if(canPlaced >= c)
        return true;
    return false;
}
int chessTournament(vector<int> positions , int n ,  int c) {
    // Sort the array
    sort(positions.begin(), positions.end());
    // Lowest distance will be 1 and highest is (last-first)element
    int low = 1;
    int high = positions[n-1]-positions[0];
    
    int ans = 1;
    while(low <= high) {
        int mid = (low+high)/2;
        
        // If it possible for this GAP
        // then we can check for increased GAP
        if(isPossible(positions, mid, c)) {
            ans = mid;
            low = mid+1;
        }
        // If this isn't possible for this GAP
        // try to reduce the GAP
        else {
            high = mid-1;
        }
    }
    return ans;
}