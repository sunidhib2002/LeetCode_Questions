class Solution {
public:
    string convertStackToString(stack<char> &s) {
        string ans = "";
        while (!s.empty()) {
            ans += s.top();
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    void print(stack<char> ch) {
        while (!ch.empty()) {
            cout<<ch.top()<<" ";
            ch.pop();
        }
        cout<<endl;
    }
    
    string removeDuplicates(string s) {
        stack<char> ch;
        ch.push(s[0]);
        int i = 1;
        while (i < s.length()) {
            // print(ch);
            if (ch.empty()) {
                ch.push(s[i]);
            } else if (!ch.empty() && ch.top() != s[i]) {
                ch.push(s[i]);
            } else {
                while (!ch.empty() && ch.top() == s[i]) {
                    ch.pop();
                }
            }
            i++;
        }
        return convertStackToString(ch);
    }
};