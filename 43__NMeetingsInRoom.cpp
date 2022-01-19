// Time Complexity - O(nlogn + n)
// Space Complexity - O(n)

class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int, int>> tmp;
        
        // Make vector of {end, start}
        for(int i=0; i<n; ++i) {
            tmp.push_back({end[i], start[i]});
        }
        
        // Sort the meetings by ascending order of their end time
        sort(tmp.begin(), tmp.end());
        
        int en = -1, ans = 0;
        
        for(auto meet : tmp) {
            int currSt = meet.second, currEnd = meet.first;
            
            // If this meeting's starting time < curr meeting's ending time
            // then we can have this meeting
            if(currSt > en) {
                ++ans;
                en = max(en, currEnd);
            }
        }
        return ans;
    }
};