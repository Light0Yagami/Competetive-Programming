/*
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
*/

class Trie {
public:
    struct Node{
    Node *child[26] = {NULL};
    bool isWord = false;
    };

    Node *head = new Node();
    
    Trie() {}
    
    void insert(string word) {
        Node *temp = head;
        int n = word.length();
        
        for(int i = 0;i < n; i++){
            if(!temp ->child[word[i] - 'a']){
                temp->child[word[i] - 'a'] = new Node();
            }
            temp = temp->child[word[i] - 'a'];
        }
        temp->isWord = true;
    }
    
    bool search(string word) {
        Node *temp = head;
        int n = word.length();
        
        for(int  i = 0; i< n; i++){
            if(temp->child[word[i] - 'a'] == NULL){
                return false;
            }
            temp = temp->child[word[i] - 'a'];
        }
        
        return temp->isWord;
    }
    
    bool startsWith(string prefix) {
        Node *temp = head;
        for(char c: prefix){
            if(!temp->child[c -'a'])
                return false;
            temp = temp->child[c - 'a'];
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
