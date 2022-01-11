///////////////////
//  Solution 1  //
/////////////////

// Time Complexity - O(n^2)
// Space Complexity - O(n^2)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        // Sort the intervals
        sort(intervals.begin(), intervals.end());
        
        // For answer array
        vector<vector<int>> ans;
        
        // Visit each element of intervals
        for(int i=0; i<n; ++i) {
            int st = intervals[i][0], en = intervals[i][1];
            
            if(!ans.empty()) {
                // We skip intervals that are merged
                if(ans.back()[1] >= st)
                    continue;
            }
            
            // Visit new items in 'intervals'
            // make the 'end' of current interval as highest overlapping time's 'end'
            for(int j=i+1; j<n; ++j) {
                if(intervals[j][0] <= en) {
                    en = max(en, intervals[j][1]);
                }
            }
            
            // Push the new interval
            ans.push_back({st, en});
        }
        
        return ans;
    }
};



///////////////////
//  Solution 2  //
/////////////////

// Time Complexity - O(n)
// Space Complexity - O(n^2)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        //Sort the intervals
        sort(intervals.begin(), intervals.end());
        
        // New array for answer
        vector<vector<int>> ans;
        
        // Start & end time of current interval
        int st = intervals[0][0];
        int en = intervals[0][1];
        
        for(int i = 1; i < n; ++i) {
            int currStart = intervals[i][0];
            int currEnd   = intervals[i][1];
            
            if(currStart <= en) {
                en = max(en, currEnd);
            }
            else {
                // Make new temp array for until now range
                vector<int> tmp;
                tmp.push_back(st);
                tmp.push_back(en);
                
                // push the 'tmp' array to 'ans'
                ans.push_back(tmp);
                
                // Assign the new start & end
                st = currStart;
                en = currEnd;
            }
        }
        // Make new temp array for until now range
        vector<int> tmp;
        tmp.push_back(st);
        tmp.push_back(en);

        // push the 'tmp' array to 'ans'
        ans.push_back(tmp);
        
        return ans;
    }
};