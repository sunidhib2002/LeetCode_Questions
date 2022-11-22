//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
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
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }
    
    void FindFreq(int n, unordered_map<int, int> &freq) {
        while (n > 0) {
            int rem = n % 10;
            freq[rem]++;
            n /= 10;
        }
    }
    
    int maxDigit(int L, int R)  {
        vector<int> primes;
        for (int i = L; i <= R; i++) {
            if (isPrime(i)) {
                primes.push_back(i);
            }
        }
        if (primes.size() == 0) {
            return -1;
        }
        unordered_map<int, int> freq;
        for (int i = 0; i < primes.size(); i++) {
            FindFreq(primes[i], freq);
        }
        int mx = 0;
        int mx_count = 0;
        for (auto pr : freq) {
            if (pr.second > mx_count) {
                mx_count = pr.second;
                mx = pr.first;
            } else if (pr.second == mx_count) {
                mx = max(pr.first, mx);
            }
        }
        
        return mx;
        // code here
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int L, R;
        cin >> L >> R;
        Solution ob;
        cout<<ob.maxDigit(L,R)<<endl;
    }
    return 0;
}

// } Driver Code Ends