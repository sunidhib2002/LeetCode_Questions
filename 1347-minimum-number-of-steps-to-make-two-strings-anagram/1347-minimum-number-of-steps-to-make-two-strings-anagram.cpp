class Solution {
public:
    unordered_map<char, int> createMap(string s) {
        unordered_map<char, int> m;
        for (int i = 0; i < s.length(); i++) {
            m[s[i]] += 1;
        }
        return m;
    }
    
    int minSteps(string s, string t) {
        unordered_map<char, int> sfreq = createMap(t);
        unordered_map<char, int> tfreq = createMap(s);
        int extraInS = 0;
        int extraInT = 0;
        int pos = 0;
        int neg = 0;
        int step = 0;
        
        for (auto pr : sfreq) {
            if (tfreq.find(pr.first) == tfreq.end()) {
                extraInS += pr.second;
            } else {
                if (tfreq[pr.first] > pr.second) {
                    pos += abs(tfreq[pr.first] - pr.second);
                } else {
                    neg += abs(pr.second - tfreq[pr.first]);
                }
            }
        }
        for (auto pr : tfreq) {
            if (sfreq.find(pr.first) == sfreq.end()) {
                extraInT += pr.second;
            }
        }
    
        step = min(extraInS, extraInT);
        int left = abs(extraInS - extraInT);
        step += min(neg, pos);
        step += min(left, abs(neg - pos));
        
        return step;
    }
};