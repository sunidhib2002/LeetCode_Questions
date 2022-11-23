//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int countCoins(int coins[], int m, int v, vector<vector<int>> &dp) {
	    if (v == 0) {
	        return 0;
	    }
	    
	    if (m == 0) {
	        return 1e5;
	    }
	    
	    if (dp[m][v] != -1) {
	        return dp[m][v];
	    }
	    
	    if (coins[m - 1] > v) {
	        return dp[m][v] =countCoins(coins, m - 1, v, dp);
	    }
	    
	    return dp[m][v] = min(countCoins(coins, m - 1, v, dp), 1 + countCoins(coins, m, v - coins[m- 1], dp));
	}
	
// 	int solve(int coins[], int n, int v,  vector<vector<int>>& dp) 
//     {
//         if(!v) return 0;
//         if(!n) return 1e5;
//         // if(!n || !v) return 0; // wrong
//         if(dp[n][v] != 1e5) return dp[n][v];

//         // int include = 1e5, exclude = 1e5;
//         // if(v >= coins[n-1]) include = 1 + solve(coins, n, v-coins[n-1]);
//         // else exclude = solve(coins, n-1, v);
//         // return min(include, exclude);
        
//         if(v >= coins[n-1]) return dp[n][v] = min(1 + solve(coins, n, v-coins[n-1], dp), solve(coins, n-1, v, dp)); // + return
//         else				return dp[n][v] = solve(coins, n-1, v, dp);
//     }
	
	int minCoins(int coins[], int M, int V) 
	{ 
	    vector<vector<int>> dp(M + 1, vector<int>(V + 1, -1));
	    int cnt = countCoins(coins, M, V, dp);
	    if (cnt == 1e5) {
	        return -1;
	    } else {
	        return cnt;
	    }
	    // Your code goes here
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends