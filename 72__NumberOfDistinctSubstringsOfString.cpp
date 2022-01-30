// Time Complexity - O(n^2)
// Space Complexity - O(n^2)
struct Node {
  Node * links[26];

  bool containsKey(char ch) {
    return (links[ch - 'a'] != NULL);
  }

  Node * get(char ch) {
    return links[ch - 'a'];
  }

  void put(char ch, Node * node) {
    links[ch - 'a'] = node;
  }
};
int countDistinctSubstrings(string &s)
{
    Node *root = new Node();
    int count = 0;
    
    // Traverse for every possible substring
    for(int i=0; i<s.size(); ++i) {
        Node *node = root;
        for(int j=i; j<s.size(); ++j) {
            // If Trie doesn't contain this character then new substring
            if(node->containsKey(s[j]) == false) {
                node->put(s[j], new Node());
                ++count;
            }
            node = node->get(s[j]);
        }
    }
    
    // +1 for empty substring
    return count+1;
}