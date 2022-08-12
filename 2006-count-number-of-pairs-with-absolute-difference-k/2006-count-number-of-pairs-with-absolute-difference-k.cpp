class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int cnt = 0;
        unordered_map<int, int> Freq;
        for (int i = 0; i < nums.size(); i++) {
            Freq[nums[i]]++;
        }
        
        for (auto pr : Freq) {
            int val = pr.first;
            int freq = pr.second;
            if (Freq.find(val + k) != Freq.end()) {
                cnt += Freq[val] * Freq[val + k];   
            } 
            if (Freq.find(val - k) != Freq.end()) {
                cnt += Freq[val] * Freq[val - k];
            }
        }
        // cout<<cnt<<endl;
        return (cnt / 2);
    }
};