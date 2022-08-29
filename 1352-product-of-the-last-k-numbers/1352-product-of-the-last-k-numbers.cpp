class ProductOfNumbers {
public:
    vector<int> prefixPro;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if (num == 0) {
            prefixPro.clear();
            prefixPro.push_back(0);
        } else if (prefixPro.size() == 0) {
            prefixPro.push_back(num);
        } else {
            int n = prefixPro.size();
            int lastVal = prefixPro[n - 1];
            if (lastVal == 0) {
                prefixPro.push_back(num);
            } else {
                prefixPro.push_back(lastVal * num);    
            }
        }
    }
    
    void print(vector<int> &vec) {
        for (int i = 0; i < vec.size(); i++) {
            cout<<vec[i]<<" ";
        }
        cout<<endl;
    }
    
    int getProduct(int k) {
        int n = prefixPro.size();
        // print(prefixPro);
        // cout<<n<<" "<<n - k - 1<<endl;
        if (n - k - 1 < 0) {
            if (prefixPro[0] == 0) {
                return 0;
            }
            return prefixPro[n - 1];
        }
        if (prefixPro[n - k - 1] == 0) {
            return prefixPro[n - 1];
        } else {
            return (prefixPro[n - 1] / prefixPro[n - k - 1]);    
        }
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */