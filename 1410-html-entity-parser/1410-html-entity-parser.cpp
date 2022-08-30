class Solution {
public:

    string entityParser(string text) {
        unordered_map<string, string> parser;
        parser["&quot;"] = "\"";
        parser["&apos;"] = "'";
        parser["&amp;"] = "&";
        parser["&gt;"] = ">";
        parser["&lt;"] = "<";
        parser["&frasl;"] = "/";
        
        int start = 0;
        string newS = "";
        int i = 0;
        
        while (i < text.length()) {
            // cout<<i<<" "<<text[i]<<endl;
            int flag = 0;
            string s = "";
            if (i + 1 < text.size() && text[i] == '&' && text[i + 1] == '&') {
                newS += text[i];
            } else if (text[i] == '&') {
                start = i;
                s += text[i];
                i += 1;
                if (i == text.size()) {
                    newS += s;
                    break;
                }
                while (i + 1 < text.size() && text[i] != ';') {
                    if (text[i] == '&') {
                        i--;
                        flag = 1;
                        break;
                    }
                    s += text[i];
                    i += 1;
                }
                if (flag == 0) {
                    s += ';';    
                }
                // cout<<"index "<<i<<" "<<s<<endl;
                if (parser.find(s) != parser.end()) {
                    newS += parser[s];
                } else {
                    newS += s;
                }
            } else {
                newS += text[i];
            } 
            i++;
        }
        return newS;
    }
};