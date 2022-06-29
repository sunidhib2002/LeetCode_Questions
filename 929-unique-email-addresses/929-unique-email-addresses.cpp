class Solution {
public:
    int GetIndex(string email) {
        for (int i = 0; i < email.length(); i++) {
            if (email[i] == '@') {
                return i;
            }
        }
        return -1;
    }
    
    string appendDomainName(string email, int index) {
        string domainName = "";
        for (int i = index; i < email.length(); i++) {
            domainName += email[i];
        }
        return domainName;
    }
    
    string GetRecieverEmail(string email) {
        string str = "";
        int index = GetIndex(email);
        for (int i = 0; i < index; i++) {
            if (email[i] == '.') {
                continue;
            }
            if (email[i] == '+') {
                break;
            }
            str += email[i];
        }
        
        return str + appendDomainName(email, index);
    }
    
    int numUniqueEmails(vector<string>& emails) {
        set<string> answer;
        for (int i = 0; i < emails.size(); i++) {
            answer.insert(GetRecieverEmail(emails[i]));
        }
        return answer.size();
    }
};