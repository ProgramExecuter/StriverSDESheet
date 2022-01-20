// Time Complexity - O(nlogn + n + m*n)
// Space Complexity - O(m)
class Solution 
{
    public:
    static bool comp(Job a, Job b)
    {
        return a.profit > b.profit;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    {
        // Sort the jobs by descending profit
        sort(arr, arr+n, comp);
        
        // Find the last deadline time
        int maxSlots = 0;
        for(int i=0; i<n; ++i) {
            maxSlots = max(maxSlots, arr[i].dead);
        }

        // We make slots for jobs
        // And we fill in their position
        bool slot[maxSlots+1] = {false};
        
        int profit = 0, jobs = 0;
        
        for(int i=0; i<n; ++i) {
            int j = arr[i].dead;
            
            // We start finding place for this job
            while(j > 0  &&  slot[j]) {
                --j;
            }
            
            // If we found an empty place then we fill it with job
            if(j > 0) {
                // Make this slot unavailable
                slot[j] = true;
                
                // Increase no. of jobs performed and profit
                ++jobs;
                profit += arr[i].profit;
            }
        }
        
        return {jobs, profit};
    }
};