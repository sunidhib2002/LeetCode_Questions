class Solution {
public:
    int m = 1000000007;
    int GetSum(map<int, int> &tracker) {
        int ans = 0;
        for (auto pr : tracker) {
            ans += pr.second;
            ans = ans % m;
        }
        return ans % m;
    }
    
    int peopleAwareOfSecret(int n, int delay, int forget) {
        //current day <= forget + m[i] and current day + m[i] >= delay
        int day = 1;
        map<int, int> tracker;
        tracker[1] = 1;
        while (day < n + 1) {
            for (auto d : tracker) {
                if (day == forget + d.first) {
                    tracker.erase(d.first);
                } else if (day >= delay + d.first) {
                    tracker[day] = (tracker[day] + d.second) % m;
                }
            }
            day++;
        }
        
        return GetSum(tracker) % m;
    }
};