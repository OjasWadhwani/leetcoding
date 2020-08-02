class MyHashSet {
public:
    /** Initialize your data structure here. */
    vector<int> vect;
    MyHashSet() {
        
    }
    
    void add(int key) {
        bool flag=false;
        for(int i=0; i<vect.size(); i++){
            if(key == vect[i])
                flag=true;
        }
        if(!flag)
            vect.push_back(key);
    }
    
    void remove(int key) {
        for(int i=0; i<vect.size(); i++){
            if(key == vect[i])
                vect.erase(vect.begin()+i);
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        for(int i=0; i<vect.size(); i++){
            if(key == vect[i])
                return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */