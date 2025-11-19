class Trie {
public:
    struct Node {
        bool end;
        Node* children[26];
        Node() {
            end = false;
            for (int i = 0; i < 26; i++) children[i] = nullptr;
        }
    };

    Node* root;

    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!curr->children[idx]) {
                curr->children[idx] = new Node();
            }
            curr = curr->children[idx];
        }
        curr->end = true;
    }
    
    bool search(string word) {
        Node* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!curr->children[idx]) return false;
            curr = curr->children[idx];
        }
        return curr->end;  // Must end exactly at a word
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (!curr->children[idx]) return false;
            curr = curr->children[idx];
        }
        return true;  // Only prefix must match
    }
};
