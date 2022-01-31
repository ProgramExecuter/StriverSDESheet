// Time Complexity - O(nlogn + m)   =>  logn for searching in 'map' in worst case
// Space Complexity - O(n)

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        //since there are no duplicates, we can store them in a map;
        
        //to be returned, initialize it with -1.
        vector<int> res(nums1.size(), -1); 
        
        stack<int> st;
        unordered_map<int, int> umap;
        
        for(int i=0; i<nums2.size(); i++)
        {
            int element = nums2[i];
            
            while(!st.empty() && element > st.top())
            {
                //NGE of st.top() is element
                umap[st.top()] = element;
                st.pop();
            }
            
            st.push(element);
        }
        
        for(int i=0; i<nums1.size(); i++)
        {
            int ele = nums1[i];
            
            if(umap.find(ele) != umap.end())
            {
                int nge = umap[ele];
                res[i] = nge; //push NGE of desired element
            }
        }
        
        return res;
    }
};

// Credits - ayzastark