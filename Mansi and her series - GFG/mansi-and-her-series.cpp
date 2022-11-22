//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    bool isPrime(int n) {
        if (n < 2) {
            return false;
        }    
        if (n == 2 || n == 3) {
            return true;
        }
        if (n % 2 == 0 || n % 3 == 0) {
            return false;
        }
        for (int i = 5; i * i <= n; i+= 6) {
            if (n % i == 0 || n % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }
    
    int nthTerm(int n){
        int i;
        int ans = 0;
        int m = n;
        for (i = 2; m != 0; i++) {
            if (isPrime(i)) {
                m--;
                ans = i;
            }
        }
    
        int a = (ans * n) + n;
        return a;
        // code here
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n;
        cin >> n;
        Solution ob;
        cout<<ob.nthTerm(n)<<endl;
    }
    return 0;
}

// } Driver Code Ends