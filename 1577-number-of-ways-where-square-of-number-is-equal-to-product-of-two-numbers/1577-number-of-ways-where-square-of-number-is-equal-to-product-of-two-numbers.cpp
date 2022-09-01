class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
     //calculate the pair products for both nums1 and nums2 and store thier frequency in a hashmap.   
        int cnt = 0;
        unordered_map<long long, int> product1;
        unordered_map<long long, int> product2;
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = i + 1; j < nums1.size(); j++) {
                product1[nums1[i] * 1LL * nums1[j]] += 1;
            }
        }
        for (int i = 0; i < nums2.size(); i++) {
            for (int j = i + 1; j < nums2.size(); j++) {
                product2[nums2[i] * 1LL * nums2[j]] += 1;
            }
        }
        for (int i = 0; i < nums1.size(); i++) {
            long long pro = nums1[i] * 1LL * nums1[i];
            if (product2.find(pro) != product2.end()) {
                cnt += product2[pro]; 
            }
        }
        for (int i = 0; i < nums2.size(); i++) {
            long long pro = nums2[i] * 1LL * nums2[i];
            if (product1.find(pro) != product1.end()) {
                cnt += product1[pro]; 
            }
        }
        return cnt;
    }
};