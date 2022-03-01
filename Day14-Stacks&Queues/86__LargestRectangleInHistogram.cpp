/*

1. Very Brute Force ( Time Complexity - O(n^3) , Space Complexity - O(1) )

   We loop for all subarrays, and find the answers by finding minimum element in that subarray
   thus , ans = max ( ans , ( (j-i) * minEle ) )



2. Brute Force ( Time Complexity - O(n^2) , Space Complexity - O(1) )

   We visit every element and for each element (say i-th element) we search for element lower than it in left and right of the array. Say left_idx = x, right_idx = y
   then , ans = max ( ans , ( ( (i-x-1) + 1 + (y-i-1) ) * arr[i] ) )

*/



/////////////////////
///  Solution 3  ///
///////////////////

// Time Complexity - O(n)
// Space Complexity - O(n)

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), ans = 0;
        
        stack<pair<int, int>> st;
        
        for(int i=0; i<n; ++i) {
            
            // If the stack has elements greater than current element
            while(!st.empty()  &&  st.top().first > heights[i]) {
                
                // We take the top element of stack
                // and calculate the area for this height
                pair<int, int> tmp = st.top();
                st.pop();

                int rightWidth = i - tmp.second - 1;
                int leftWidth;

                // If stack is not empty
                // then this element wasn't smallest element in left side
                if(!st.empty())
                    leftWidth = tmp.second - st.top().second - 1;
                else
                    leftWidth = tmp.second;

                int width = leftWidth + 1 + rightWidth;

                int area = tmp.first * width;

                ans = max(ans, area);
            }
            
            // Push this element to the stack
            st.push({heights[i], i});
            
            ans = max(ans, heights[i]);
        }
        
        while(!st.empty()) {
            // We take the top element of stack
            // and calculate the area for this height
            pair<int, int> tmp = st.top();
            st.pop();

            int leftWidth;
            int rightWidth = n - 1 - tmp.second;

            // If stack is not empty
            // then this element wasn't smallest element in left side
            if(!st.empty()) {
                leftWidth = tmp.second - st.top().second - 1;
            }
            else {
                leftWidth = tmp.second;
            }

            int width = leftWidth + 1 + rightWidth;

            int area = tmp.first * width;

            ans = max(ans, area);
        }
        
        return ans;
    }
};