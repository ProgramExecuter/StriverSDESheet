class TrieNode {
public:
    TrieNode *arr[26];
    int cntP = 0;
    int end = 0;
    
    // Getters
    TrieNode* get(char ch) {
        return arr[ch-'a'];
    }
    
    int getCount() {
        return cntP;
    }
    
    int getEnd() {
        return end;
    }
    
    // Setters
    void set(char ch, TrieNode* node) {
        arr[ch-'a'] = node;
    }
    
    void incrementCount() {
        ++cntP;
    }
    
    void decrementCount() {
        --cntP;
    }
    
    void setEnd() {
        ++end;
    }
    
    void removeEnd() {
        --end;
    }
    
    // Check if this character is present
    bool isPresent(char ch) {
        return arr[ch-'a'] != NULL;
    }
};
class Trie{
	TrieNode* root;
    public:

    Trie() {
        // Write your code here.
        root = new TrieNode();
    }

    void insert(string &word) {
        TrieNode* tmp = root;
        
        for(char ch : word) {
            // If it doesn't contain this character
            // then create a new TrieNode
            if(tmp->isPresent(ch) == false) {
                tmp->set(ch, new TrieNode());
            }
            
            // Move to next Node
            tmp = tmp->get(ch);
            tmp->incrementCount();
        }
        
        // Set this word as ended
        tmp->setEnd();
    }

    int countWordsEqualTo(string &word) {
        TrieNode* tmp = root;
        for(char ch : word) {
            // If it doesn't contain this character
            // then return 0
            if(tmp->isPresent(ch) == false)
                return 0;
            
            // Move to next Node
            tmp = tmp->get(ch);
        }
        
        // If this hasn't ended, return FALSE
        if(tmp->getEnd() == 0)
            return 0;
        return tmp->getEnd();
    }

    int countWordsStartingWith(string &word) {
        TrieNode* tmp = root;
        
        for(char ch : word) {
            // If it doesn't contain this character
            // then return 0
            if(tmp->isPresent(ch) == false)
                return 0;
            
            // Move to next Node
            tmp = tmp->get(ch);
        }
        
        return tmp->getCount();
    }

    void erase(string &word) {
        TrieNode* tmp = root;
        for(char ch : word) {
            if(tmp->isPresent(ch) == false)
                return;
            
            // Move to next Node
            tmp = tmp->get(ch);
            tmp->decrementCount();
        }
        
        tmp->removeEnd();
    }
};
