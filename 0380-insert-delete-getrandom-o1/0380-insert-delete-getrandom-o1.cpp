class RandomizedSet {
public:
    unordered_set<int>v;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
       if(v.find(val)==v.end())
       {
           v.insert(val);
           return true;
       }
        return false;
    }
    
    bool remove(int val) {
        if(v.find(val)!=v.end())
        {
            v.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return *next(v.begin(),rand()%v.size()); 
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */