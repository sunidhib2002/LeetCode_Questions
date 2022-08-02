class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        sort(grades.begin(), grades.end());
        int cnt = 0;
        int n = grades.size();
        int i = 1;
        while (n > 0) {
            n -= i;
            i++;
            cnt++;
        }
        if (n == 0) {
            return cnt;
        }
        if (n < 0) {
            cnt -= 1;
            return cnt;
        }
        return cnt;
    }
};