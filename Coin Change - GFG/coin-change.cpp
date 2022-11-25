//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int countCoins(int coins[], int n, int sum, int score, vector<vector<long long int>> &dp) {
        if (score == sum) {
            return 1;
        } 
        
        if (n == 0) {
            return 0;
        }
        
        if (dp[n][score] != -1) {
            return dp[n][score];
        }
        
        if (score + coins[n - 1] > sum) {
            return dp[n][score] = countCoins(coins, n - 1, sum, score, dp);
        }
        return dp[n][score] = countCoins(coins, n, sum, score + coins[n - 1], dp) + countCoins(coins, n - 1, sum, score, dp);
    }
    
    long long int count(int coins[], int N, int sum) {
        vector<vector<long long int>> dp(N + 1, vector<long long int>(1001, -1));
        return countCoins(coins, N, sum, 0, dp);
        // code here.
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends