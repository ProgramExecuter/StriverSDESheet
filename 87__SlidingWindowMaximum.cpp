/////////////////////
///  Solution 1  ///
///////////////////

// Time Complexity - O(n*k);
// Space Compelxity - O(1)

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        
        for(int i=0; i<=nums.size()-k; ++i) {
            int mx = INT_MIN;
            
            // Finding maximum from this window
            for(int j=i; j<i+k; ++j)
                mx = max(mx, nums[j]);
            
            ans.push_back(mx);
        }
        
        return ans;
    }
};





/////////////////////
///  Solution 2  ///
///////////////////

// Time Complexity - O(n);
// Space Compelxity - O(n)

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        
        deque<int> q;
        vector<int> ans;
        
        for(int i = 0; i < k; ++i) {
            // Pop elements from back until the last element is greater than 'curr' element
            while(!q.empty()  &&  nums[q.back()] <= nums[i])
                q.pop_back();
            
            q.push_back(i);
        }
        
        for(int i = k-1; i < n; ++i) {
            // Pop elements from back until the last element is greater than 'curr' element
            while(!q.empty()  &&  nums[q.back()] <= nums[i])
                q.pop_back();
            
            // Remove elements out of bounds
            while(!q.empty()  &&  q.front() <= i-k)
                q.pop_front();
            
            
            q.push_back(i);
            
            // Push the highest number as ans
            ans.push_back(nums[q.front()]);
        }
        
        return ans;
    }
};