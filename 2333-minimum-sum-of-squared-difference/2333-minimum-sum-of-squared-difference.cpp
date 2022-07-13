class Solution {
public:
    long long getSquareDiff(map<int, int, greater<int>> counter) {
        long long ans = 0;
        for (auto pr : counter) {
            if (pr.first != 0) {
                ans += (pr.first * 1LL * pr.first) * pr.second;
            }
        }
        return ans;
    }
    
    void print(map<int, int, greater<int>> m) {
        for (auto pr : m) {
            cout<<pr.first<<" "<<pr.second<<endl;
        }
    }
    
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        map<int, int, greater<int>> counter;
        for (int i = 0; i < nums1.size(); i++) {
            int diff = abs(nums1[i] - nums2[i]);
            if (counter.find(diff) == counter.end()) {
                counter[diff] = 1;
            } else {
               counter[diff]++; 
            }
        }
        
        //print(counter);
        
        int k = k1 + k2;
        while (k != 0 && counter.size() != 0) {
            auto it = counter.begin();
            pair<int, int> p = *it;
            int val = p.first;
            int freq = p.second;
            if (val == 0 || freq == 0) {
                counter.erase(val);
                continue;
            }
            if (k >= freq) {
                if (val - 1 != 0) {
                    if (counter.find(val - 1) != counter.end()) {
                        counter[val - 1] += freq;
                    } else {
                        counter[val - 1] = freq;
                    }
                    counter.erase(val);
                    k -= freq;
                } else {
                    counter.erase(val);
                    k -= freq;
                }
            } else {
                if (val - 1 != 0) {//handle else part
                    if (counter.find(val - 1) != counter.end()) {
                        counter[val - 1] += k;
                    } else {
                        counter[val - 1] = k;
                    }
                    counter[val] = freq - k;
                    k = 0;     
                } else {
                    counter[val] = freq - k;
                    k = 0;
                }
            }
        }
        
        //print(counter);
        
        while (k == 0 || counter.size() == 0) {
            return getSquareDiff(counter);
        }
        return 0;
     }
};