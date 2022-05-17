class RandomizedSet {
public:
    map<int,int>mpp;//-----actual value,index value------//
    vector<int>v;//------->vector
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        /*false---->value already present
        true-------->value inserted by me */
        if(mpp.find(val)!=mpp.end())return false;
        v.push_back(val);
        mpp[val]=v.size()-1;
        return true;
    }
    
    bool remove(int val) {
        /*false------->not present in vector
        true---------->present in the vector*/
        if(mpp.find(val)==mpp.end())return false;
        auto it=mpp.find(val);
        v[it->second]=v.back();
        v.pop_back();
        mpp[v[it->second]]=it->second;
        mpp.erase(val);
        return true;
        
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */