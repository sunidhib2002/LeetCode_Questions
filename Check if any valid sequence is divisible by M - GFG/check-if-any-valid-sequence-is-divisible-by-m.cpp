//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


bool validSequence(int arr[], int n, int M);

int main()
{
	int t,n,M;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>M;
        
        if(validSequence(arr, n, M))
            cout << 1 << endl;
        else
            cout << 0 << endl;
        
	    
	}
	return 0;
}


// } Driver Code Ends

bool checkValid(int arr[], int n, int m, int score, int i, int dp[][1000]) {
    if (i >= n) {
        if (score % m == 0) {
            return true;
        }
        return false;
    }
    
    if (dp[i][score] != -1) {
        return dp[i][score];
    }
    
    return dp[i][score] = checkValid(arr, n, m, score + arr[i], i + 1, dp) || checkValid(arr, n, m, score - arr[i], i + 1, dp);
}

int getSum(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

bool validSequence(int arr[], int n, int M)
{
    // int sum = getSum(arr, n);
    // vector<vector<int>> dp(1000, vector<int>(n + 1, -1));
    int dp[n + 1][1000];
    memset(dp, -1, sizeof(dp));
    return checkValid(arr, n, M, 0, 0, dp);
    // Complete the function

}