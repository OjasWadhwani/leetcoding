class WordDictionary {
public:
    /** Initialize your data structure here. */
    map<int, vector<string>> dictionary;
    
    WordDictionary() {
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        int len=word.size();
        map<int, vector<string>>::iterator itr;
        int flag=0;
        for(itr=dictionary.begin(); itr != dictionary.end(); itr++){
            if(itr->first == len)
                flag=1;
        }
        if(flag)
            dictionary[len].push_back(word);
        else{
            vector<string> vtr;
            vtr.push_back(word);
            dictionary.insert(pair<int, vector<string>>(len, vtr) );
        }
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        int len=word.size();
        map<int, vector<string>>::iterator itr;
        for(int i=0; i<dictionary[len].size(); i++){
            int error=0;
            for(int j=0; j<len; j++){
                if(word[j] != '.'){
                    itr = dictionary.find(len);
                    if( (itr->second)[i][j] != word[j]){
                        error=1;
                        break;
                    }
                }
            }
            if(!error)
                return true;
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