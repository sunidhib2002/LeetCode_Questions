//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        long long ans = 0;
        if (n == 1) {
            return 0;
        }
        for (int i = 0; i < n; i++) {
            pq.push(arr[i]);
        }
        while (!pq.empty()) {
            long long num1 = pq.top();
            pq.pop();
            long long num2 = pq.top();
            pq.pop();
            ans += (num1 + num2);
            if (pq.empty()) {
                break;
            }
            pq.push(num1 + num2);
        }
        return ans;
        // Your code here
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends