///////////////////////
///   Solution 1   ///
/////////////////////

// Time Complexity - O(n)
// Space Complexity - O(n)

//    1. Prepare vector<vector<int>> for 'ans'
//    2. Take first element from each inner vector
//    3. You get the answer



//// Space is optimized in 2nd solution
///  We get only 'ans' instead of whole tree



///////////////////////
///   Solution 2   ///
/////////////////////

// Time Complexity - O(n)
// Space Complexity - O(logn)

vector<int> leftView(Node *root)
{
   vector<int> ans;
   int currLevel = -1;
   
   // If no Node is avaliable then return
   if(!root)    return ans;
   
   stack<pair<Node*, int>> st;
   st.push({root, 0});
   
   // While stack isn't empty
   while(!st.empty()) {
       int level = st.top().second;
       Node* curr = st.top().first;
       st.pop();
       
       // If the level of this node is deeper than current answer's level
       if(level > currLevel) {
           ans.push_back(curr->data);
           currLevel = max(currLevel, level); // Increase the level
       }
       
       if(curr->right)  st.push({curr->right, level+1});
       if(curr->left)   st.push({curr->left,  level+1});
   }
}
