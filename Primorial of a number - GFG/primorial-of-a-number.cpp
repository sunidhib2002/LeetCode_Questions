//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution {

public:
    void precompute()
    {
        // Code Here
    }
    
    long long GetPrimes(long long n) {
        // vector<int> prime;
        int limit = n;
        vector<bool> valid(limit, 0);
        for (int i = 2; i * i <= limit; i++) {
            if (valid[i] == 0) {
                for (int j = 2 * i; j <= limit; j += i) {
                    valid[j] = 1;
                }
            }
        }
        long long pro = 1;
        for (int i = 2; i <= limit; i++) {
            if (valid[i] == 0) {
                // prime.push_back(i);    
                pro = (pro * i) %1000000007;
            }
        }
        return pro;
    }
    
    long long primorial(long long n){
        // Code here
        // long long ans = 1;
        // vector<int> prime = GetPrimes(n);
        // for (int i = 0; i < prime.size(); i++) {
        //     // cout<<prime[i]<<" ";
        //     ans *= prime[i];
        // }
        // cout<<endl;
        return GetPrimes(n);
    }
};

//{ Driver Code Starts.

int main()
{
    Solution ob;
    ob.precompute();
    int t; cin >> t;
    while(t--)
    {
        long long n;
        cin>>n;
        cout << ob.primorial(n) << endl;
    }
    return 0;
} 
// } Driver Code Ends