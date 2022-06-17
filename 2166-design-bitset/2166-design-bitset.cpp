class Bitset {
public:
    //string bits = "";
    vector<int> bits; 
    int countOfOne = 0;
    bool flippedFlag = false;
    
    Bitset(int size) {
        for (int i = 0; i < size; i++) {
            bits.push_back(0);        
        }
    }
    
    void fix(int idx) {
        if (flippedFlag) {
            if (bits[idx] == 1) {
                countOfOne += 1;
            }
            bits[idx] = 0;
            
        } else {
            if (bits[idx] == 0) {
                countOfOne += 1;
            }
            bits[idx] = 1;
        }
       // cout<<toString()<<endl;
    }
    
    void unfix(int idx) {
        if (flippedFlag) {
            if (bits[idx] == 0) {
                countOfOne -= 1;
            }
            bits[idx] = 1;
            
        } else {
            if (bits[idx] == 1) {
                countOfOne -= 1;
            }
            bits[idx] = 0;
        }
       // cout<<toString()<<endl;
    }
    
    void flip() {
        //countOfOne = 0;
        flippedFlag = !(flippedFlag);
        countOfOne = bits.size() - countOfOne;
        // int size = bits.size();
        // for (int i = 0; i < size; i++) {
        //     if (bits[i] == 0) {
        //         fix(i);
        //     } else {
        //         unfix(i);
        //     }
        // }
    }
    
    bool all() {
        return (countOfOne == bits.size());
    }
    
    bool one() {
        return (countOfOne >= 1);
    }
    
    int count() {
        return countOfOne;
    }
    
    string toString() {
        string newBits = "";
        if  (flippedFlag) {
             for (int i = 0; i < bits.size(); i++) {
                if (bits[i] == 1)
                    newBits += "0";
                else {
                    newBits += "1";
                }
            }
        } else {
         
            for (int i = 0; i < bits.size(); i++) {
                newBits += to_string(bits[i]);
            } 
        }
        
        return newBits;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */