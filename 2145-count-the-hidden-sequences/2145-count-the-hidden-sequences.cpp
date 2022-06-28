class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long sum = 0;
        long long mx = sum;
        long long mn = sum;
        
        for (int i = 0; i < differences.size(); i++) {
            sum += differences[i];
            mx = max(mx, sum);
            mn = min(mn, sum);
        }
        
        long long ub = upper - mx;
        long long lb = lower - mn;
        if (ub - lb + 1 > 0) {
            return (ub - lb + 1);
        }
        return 0;
    }
};