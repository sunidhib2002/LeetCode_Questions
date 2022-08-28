class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int i = 0; i < arr.size(); i++) {
            freq[arr[i]] += 1;
        }
        vector<int> values;
        for (auto pr : freq) {
            values.push_back(pr.second);
        }
        sort(values.begin(), values.end(), greater<int>());
        int mid = arr.size() / 2;
        int i = 0;
        
        while (mid > 0 && i < values.size()) {
            mid -= values[i];
            i += 1;
        }
        
        return i;
    }
};