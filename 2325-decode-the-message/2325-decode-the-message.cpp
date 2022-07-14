class Solution {
public:
    string decodeMessage(string key, string message) {
        string ans = "";
        unordered_map<char, char> Mapping;
        int ascii = 97;
        
        for (int i = 0; i < key.length(); i++) {
            if (key[i] != ' ' && Mapping.find(key[i]) == Mapping.end()) {
                Mapping[key[i]] = char(ascii);
                ascii++;    
            }
        }
        
        for (int i = 0; i < message.length(); i++) {
            if (message[i] == ' ') {
                ans += ' ';
            } else {
                ans += Mapping[message[i]];
            }
        }
        
        return ans;
    }
};