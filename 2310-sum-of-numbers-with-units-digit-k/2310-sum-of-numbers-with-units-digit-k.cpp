class Solution {
public:
    int minimumNumbers(int num, int k) {
        if (num == 0) {
            return 0;
        } else if (num < k) {
            return -1;
        } else if (num == k) {
            return 1;
        } else {
            map<int, int> UnitDigitsForK;
            for (int i = 1; i <= 10; i++) {
                UnitDigitsForK[i] = ((i * k) % 10);
            }
            int unit = num % 10;
            for (auto pr : UnitDigitsForK) {
                if (pr.second == unit) {
                    if (pr.first * k <= num) {
                        return pr.first;    
                    } 
                }
            }
            return -1;
        }
    }
};