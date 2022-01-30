class Node {
public:
    Node *links[2];
    
    bool containsKey(int i) {
        return links[i] != NULL;
    }
    
    Node* get(int i) {
        return links[i];
    }
    
    void put(int i, Node *node) {
        links[i] = node;
    }
};
class Trie {
public:
    Node *root;
    
    Trie() {
      root = new Node();
    }
    
    void insert(int num) {
        Node *node = root;
        
        for(int i = 31; i >= 0; i--) {
            // Get this 'bit'
            int bit = (num >> i) & 1;
            
            // Fill this bit if not available
            if(node->containsKey(bit) == false)
                node->put(bit, new Node());
            
            // Move to next Node
            node = node->get(bit);
        }
    }
    
    int findMax(int idx, Node *node, int curr, int &num, int &range) {
        // This number > range
        if(curr > range) {
            return -1;
        }
        
        //  We've reached the end of bits
        if(idx == -1) {
            return (curr ^ num);
        }
        
        // Find the idx-th bit in 'num'
        int bit = (num >> idx) & 1;
        
        // If this contains opposite bit
        if(node->containsKey(1-bit)) {
            int tmpCurr = curr | ((1-bit) << idx);
            
            int res = findMax(idx-1, node->get(1-bit), tmpCurr, num, range);
            
            // If opposite bit gives an answer
            // then no need to check further
            if(res != -1) {
                return res;
            }
        }
        
        // Checkk if same bit is set
        if(node->containsKey(bit)) {
            int tmpCurr = curr | (bit << idx);
            return findMax(idx-1, node->get(bit), tmpCurr, num, range);
        }
        
        // No bit is set
        // Means no such number
        // Thus we return -1
        return -1;
    }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie t;
        
        // Insert all numbers
        for(int num : nums) {
            t.insert(num);
        }
        
        vector<int> ans;
        for(vector<int> tmp : queries) {
            int res = t.findMax(31, t.root, 0, tmp[0], tmp[1]);
            
            ans.push_back(res);
        }
        
        return ans;
    }
};