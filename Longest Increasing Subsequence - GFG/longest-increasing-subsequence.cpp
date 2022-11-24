//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    
    int LIS(int n, int a[], int i, int prev_idx, vector<vector<int>> &dp) {
        if (i >= n) {
            return 0;
        }    
        if (dp[i][prev_idx + 1] != -1) {
            return dp[i][prev_idx + 1];
        }
        int notTake = 0 + LIS(n, a, i + 1, prev_idx, dp);
        int take = INT_MIN;
        if (prev_idx == -1 || a[i] > a[prev_idx]) {
            take = 1 + LIS(n, a, i + 1, i, dp);
        }
     
        return dp[i][prev_idx + 1] = max(take, notTake);
    }
    //Function to find length of longest increasing subsequence.
    int getMax(int a[], int n) {
        int mx = -1;
        for (int i = 0; i < n; i++) {
            mx = max(mx, a[i]);
        }
        return mx;
    }
    
    int longestSubsequence(int n, int a[])
    {
        int mx = getMax(a, n);
        // memset(dp, -1, sizeof(dp));
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return LIS(n, a, 0, -1, dp);
       // your code here
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends