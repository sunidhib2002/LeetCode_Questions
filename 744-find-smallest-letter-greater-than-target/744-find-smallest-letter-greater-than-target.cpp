class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0;
        int right = letters.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid - 1 >= 0 && letters[mid - 1] <= target && target < letters[mid]) {
                return letters[mid];
            } 
            if (mid + 1 < letters.size() && letters[mid] <= target && target < letters[mid + 1]) {
                return letters[mid + 1];
            }
            if (letters[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return letters[0];
    }
};