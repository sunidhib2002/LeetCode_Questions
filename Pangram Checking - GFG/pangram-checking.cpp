//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to check if a string is Pangram or not.
    bool checkPangram (string &str) {
        unordered_map<char, int> freq;
        for (char ch = 'a'; ch <= 'z'; ch++) {
            freq[ch] = 0;
        }
        
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        // cout<<str<<endl;
        for (int i = 0; i < str.length(); i++) {
            if (freq.find(str[i]) != freq.end()) {
                freq[str[i]]++;
            }
        }
        
        for (auto pr : freq) {
            if (pr.second == 0) {
                return false;    
            }
        }
        
        return true;
        // your code here
    }

};

//{ Driver Code Starts.

// Driver Program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--){
        string str;
        getline(cin, str);
        Solution obj;
        if (obj.checkPangram(str) == true)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return(0);
}

// } Driver Code Ends