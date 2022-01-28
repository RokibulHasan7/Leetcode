class WordDictionary {
public:
    struct node{
        array<node*, 26> child;
        bool isEndofWord = false;
        
        node(){
            for(int i = 0; i < 26; i++){
                child[i]=NULL;
            }
            isEndofWord = false;
        }
    };
    
    node *root = NULL;
    
    WordDictionary() {
        root = new node();
    }
    
    void addWord(string word) {
        node *tmp = root;
        
        for(char ch: word){
            if(tmp -> child[ch-'a'] == NULL){
                tmp -> child[ch-'a'] = new node();
            }
            tmp = tmp-> child[ch-'a'];
        }
        tmp -> isEndofWord = 1;
    }
    
    bool find(const string &word, int idx, node* root){
        int sz = word.size();
        
        for( ;idx < sz; idx++){   
            if(word[idx] == '.'){
                
                for(int i = 0; i < 26; i++){
                    if(root -> child[i] && find(word, idx + 1, root -> child[i])){
                        return true;
                    }
                }
                return false;   
            }
            else if(root -> child[word[idx]-'a']){
                
                root = root -> child[word[idx]-'a'];
            }
            else{
                return false;
            }
        }
        return root -> isEndofWord;
    }
    
    bool search(string word){
        return find(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
