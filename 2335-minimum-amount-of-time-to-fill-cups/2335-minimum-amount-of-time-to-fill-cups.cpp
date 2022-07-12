class Solution {
public:
    int fillCups(vector<int>& amount) {
        int cnt = 0;
        priority_queue<int> pq;
        
        for (int i = 0; i < amount.size(); i++) {
            if (amount[i] != 0) {
                pq.push(amount[i]);   
            }
        }
        
        while (pq.size() > 1) {
            cnt += 1;
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            if (first - 1 != 0) {
                pq.push(first - 1);    
            }
            if (second - 1 != 0) {
                pq.push(second - 1);    
            }
        }
        
        if (pq.size() == 1) {
            cnt += pq.top();
        }
        
        return cnt;
    }
};