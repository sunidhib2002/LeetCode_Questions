//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        unordered_map<int,int> freq;
        for (int i = 0; i < a.length(); i++) {
            freq[a[i]]++;
        }
        for (int i = 0; i < b.length(); i++) {
            if (freq.find(b[i]) == freq.end()) {
                return false;
            } else {
                freq[b[i]]--;
                if (freq[b[i]] < 0) {
                    return false;
                }
            }
        } 
        
        for (auto pr : freq) {
            if (pr.second != 0) {
                return false;
            }
        }
        // Your code here
        return true;
        
    }

};

//{ Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}

// } Driver Code Ends