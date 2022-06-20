class Solution {
public:
    string greatestLetter(string s) {
        set<char> upperCase;
        for (int i = 0; i < s.length(); i++) {
            if (isupper(s[i])) {
                upperCase.insert(s[i]);
            }
        }
        char ans = '?';
        for (int i = 0; i < s.length(); i++) {
            if (islower(s[i])) {
                char ch = char(s[i] - 32);
                if (upperCase.find(ch) != upperCase.end()) {
                    if (ans < ch) {
                        ans = ch;
                    }
                }
            }
        }
        string answer = "";
        if (ans == '?') {
            return answer;
        }
        answer += ans;
        return answer;
    }
};