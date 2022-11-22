//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int getLeastFactor(int n) {
        while (n % 2 == 0) {
            return 2;
        }    
        for (int i = 3; i * i <= n; i++) {
            if (n % i == 0) {
                return i;
            }
        }
        if (n > 2) {
            return n;
        }
        return -1;
    }
    
    void print(vector<int> vec) {
        for(int i = 0; i < vec.size(); i++) {
            cout<<vec[i]<<" ";
        } 
        cout<<endl;
    }
    
    vector<int> leastPrimeFactor(int n) {
        vector<int> ans;
        ans.push_back(0);
        ans.push_back(1);
        // print(ans);
        for (int i = 2; i <= n; i++) {
            // /cout<<i<<endl;
            if (i % 2 == 0) {
                ans.push_back(2);
            } else {
                ans.push_back(getLeastFactor(i));
            }
            // print(ans);
        }
        // print(ans);
        return ans;
        // code here
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        vector<int>ans = ob.leastPrimeFactor(n);
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;  
    }
    return 0;
}

// } Driver Code Ends