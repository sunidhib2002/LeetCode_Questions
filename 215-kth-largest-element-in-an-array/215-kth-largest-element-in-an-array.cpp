class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
        }
        
        int val = 0;
        while (k > 0) {
            val = pq.top();
            pq.pop();
            k--;
        }
        
        return val;
    }
};