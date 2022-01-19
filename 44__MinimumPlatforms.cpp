// Time Complexity - O(nlogn + n)
// Soace Complexity - O(n)

class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        sort(arr, arr+n);
        sort(dep, dep+n);
        
        int i = 0, j = 1, ans = 0, count = 1;
        
        // We have 1 platform at start
        while(i < n  &&  j < n) {
            // If the next train's arrival time > departure time of standing train
            // then no need for the current platform and thus demolish it
            // and move 'i' to next train
            if(arr[j] > dep[i]) {
                ++i;
                --count;
            }
            // If the next train's arrival time <= departure time of standing train
            // then we need 1 more platform and thus build it
            // and move 'j' to next train
            else {
                ++j;
                ++count;
            }
            
            // At any point in time what is maximum number of platforms
            ans = max(ans, count);
        }
    	
    	return ans;
    }
};




////
//  Easy to understand
////

class Solution{
    public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Sort the arrival and departure times
        sort(arr, arr+n);
        sort(dep, dep+n);
        
        // We take pointers for arrival and departure of trains
        int ptrArr = 1, ptrDep = 0, ans = 0;
        
        while(ptrArr < n  &&  ptrDep < n) {
            // If arrival-time of next train <= departure-time of this train
            // then move to next arrival train
            if(arr[ptrArr] <= dep[ptrDep])
                ++ptrArr;
            else
                ++ptrDep;
            
            // At any point in time 
            // No. of platforms  =  no. of trains arrived - no. of trains departed
            ans = max(ans, ptrArr-ptrDep);
        }
        ans = max(ans, ptrArr-ptrDep);
    	
    	return ans;
    }
};