class RandomizedCollection {
    vector<int> nums;
    unordered_map<int, int> mp;
public:
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        if(mp[val] == 0){  //the element is not present yet in the vector or map
            nums.push_back(val);
            mp[val]++;   //due to the reazon of duplicate 
            return true;
        }
        else if(mp[val] > 0){   //it is present in the vector or mp
            nums.push_back(val);
            mp[val]++;
            return false;
        }
        return false;    
    }
    
    bool remove(int val){
        if(mp[val] > 0){  //the element is present
             auto it = find(nums.begin(),nums.end(),val);
             nums.erase(it);
             mp[val]--;
             return true;
         }
         return false;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};