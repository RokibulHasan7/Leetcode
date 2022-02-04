class WordDictionary {
public:
    unordered_map<int, vector<string>> mp;
    
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        int sz = word.size();
        mp[sz].push_back(word);
    }
    
    bool isExist(string a, string b){
        //cout<<a<<" "<<b<<endl;
        for(int i = 0; i < b.size(); i++){
            //cout<<b[i]<<endl;
            if(a[i] == '.'){
                continue;
            }
            
            if(a[i] != b[i]){
                return false;
            }
        }
        return true;
    }
    bool search(string word) {
        int n = word.size();
        for(int i = 0; i < mp[n].size(); i++){
            string tmp = mp[n][i];
            if(isExist(word, tmp)){
                return true;
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
