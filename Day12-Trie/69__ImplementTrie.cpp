class TrieNode {
public:
    TrieNode *arr[26];
    bool flag = false;
    
    // If this contains 'ch'
    bool containsChar(char ch) {
        return arr[ch-'a'] != NULL;
    }
    
    // Get character 'ch' 's Node
    TrieNode* get(char ch) {
        return arr[ch-'a'];
    }
    
    // Set 'ch' character's node
    void set(char ch, TrieNode* node) {
        arr[ch-'a'] = node;
    }
    
    // Set this as end of word
    void setEnd() {
        flag = true;
    }
    
    // Is this end of the word
    bool isEnd() {
        return flag;
    }
};
class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* tmp = root;
        
        for(char ch : word) {
            // If it doesn't contain this character
            // then create a new TrieNode
            if(tmp->containsChar(ch) == false) {
                tmp->set(ch, new TrieNode());
            }
            
            // Move to next Node
            tmp = tmp->get(ch);
        }
        
        // Set this words as ended
        tmp->setEnd();
    }
    
    bool search(string word) {
        TrieNode* tmp = root;
        
        for(char ch : word) {
            // If it doesn't contain this character
            // then return FALSE
            if(tmp->containsChar(ch) == false)
                return false;
            
            // Move to next Node
            tmp = tmp->get(ch);
        }
        
        // If this hasn't ended, return FALSE
        if(tmp->isEnd() == false)
            return false;
        return true;
    }
    
    bool startsWith(string prefix) {
        TrieNode* tmp = root;
        
        for(char ch : prefix) {
            // If it doesn't contain this character
            // then return FALSE
            if(tmp->containsChar(ch) == false)
                return false;
            
            // Move to next Node
            tmp = tmp->get(ch);
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */