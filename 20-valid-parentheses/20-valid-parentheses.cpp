class Solution {
public:
    void print(stack<char> s) {
        while (!s.empty()) {
            cout<<s.top()<<" ";
            s.pop();
        }
        cout<<endl;
    }
    
    bool isValid(string s) {
        if (s[0] == '}' || s[0] == ']' || s[0] == ')') {
            return false;
        }
        stack<char> brackets;
        for (int i = 0; i < s.length(); i++) {
            // cout<<i<<" "<<s[i]<<endl;
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                brackets.push(s[i]);
            } else if (!brackets.empty()) {
                if (s[i] == ')') {
                    if (brackets.top() == '(') {
                        brackets.pop();
                    } else {
                        return false;
                    }
                } else if (s[i] == '}') {
                    if (brackets.top() == '{') {
                        brackets.pop();
                    } else {
                        return false;
                    }
                } else if (s[i] == ']') {
                    if (brackets.top() == '[') {
                        brackets.pop();
                    } else {
                        return false;
                    }
                }
            } else {
                // cout<<"Hello"<<endl;
                if (s[i] == '}' || s[i] == ']' || s[i] == ')') {
                    return false;
                }
            }
        }
        
        return brackets.empty();
    }
};