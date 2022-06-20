class Solution {
public:
    vector<int> ConvertString2vec(string s) {
        vector<int> bin;
        for (int i = 0; i < s.length(); i++) {
            bin.push_back(s[i] - '0');
        }
        return bin;
    }
    
    vector<int> GetZeroCount(vector<int> &bin) {
        vector<int> ans;
        int count = 0;
        for (int i = 0; i < bin.size(); i++) {
            if (bin[i] == 0) {
                count++;
            }
            ans.push_back(count);
        }
        return ans;
    }
     
    int longestSubsequence(string s, int k) {
        vector<int> bin = ConvertString2vec(s);
        vector<int> previousZeros = GetZeroCount(bin);
        
        int left = 0;
        int right = 0;
        int zeroUsed = 0;
        string num = "";
        int mx = 0;
        while (left <= right && right < s.length()) {
            num += s[right];
            if (bin[right] == 0) {
                zeroUsed++;
            }
            if (stoi(num, nullptr, 2) <= k) {
                int allprevZeros = previousZeros[right];
                int len = num.length();
                int offset = allprevZeros - zeroUsed;
                if (offset > 0) {
                    mx = max(mx, len + offset);
                } else {
                   mx = max(mx, len); 
                }
            } else {
                while (stoi(num, nullptr, 2) > k) {
                    if (bin[left] == 0) {
                        zeroUsed--;
                    }
                    num.erase(0, 1);
                    left++;
                }
            }
            right++;
        }
    
        return mx;
    }
};