// ** Since since size of trie is constant(32) it isn't added in complexities

// Time Complexity - O(n)
// Space Complexity - O(n)

// Trie Node
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
/// Trie
class Trie {
    Node *root;
public:
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
    
    int findMax(int num) {
        Node *node = root;
        int ans = 0;
        
        for(int i = 31; i >= 0; i--) {
            // Get this 'bit'
            int bit = (num >> i) & 1;
            
            // Check if this position contains opposite BIT
            if(node->containsKey(1-bit)) {
                ans = ans | (1<<i);

                // So that we can move into this BIT's direction
                bit = 1-bit;
            }
            
            // Move to next Node
            node = node->get(bit);
        }
        return ans;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int ans = 0;
        // Trie *t = new Trie();
        Trie t;
        
        // Insert all numbers
        for(int num : nums) {
            t.insert(num);
        }
        
        // Find the number with highest XOR
        for(int num : nums) {
            ans = max(ans, t.findMax(num));
        }
        
        return ans;
    }
};