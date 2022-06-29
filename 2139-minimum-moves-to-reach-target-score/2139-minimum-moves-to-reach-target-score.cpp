class Solution {
public:
 
    int minMoves(int target, int maxDoubles) {
        int cnt = 0;
        if (maxDoubles == 0) {
            return (target - 1);
        }
        while (target > 1) {
            if (target % 2 == 0 && maxDoubles > 0) {
                target = target / 2;
                cnt++;
                maxDoubles -= 1;
            } else {
                target -= 1;
                cnt += 1;
            }
        }
        return cnt;
    }
};