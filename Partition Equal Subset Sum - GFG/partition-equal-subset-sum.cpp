//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool SubsetSum(int arr[], int N, int target, vector<vector<int>> &dp) {
        if (target == 0) {
            return true;
        }
        if (N == 0) {
            return false;
        }
        
        if (dp[N][target] != -1) {
            return dp[N][target];
        }
        
        if (arr[N - 1] > target) {
            return dp[N][target] = SubsetSum(arr, N - 1, target, dp);
        }
        
        return dp[N][target] = SubsetSum(arr, N - 1, target, dp) || SubsetSum(arr, N - 1, target - arr[N - 1], dp);
    }
    
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for (int i = 0; i < N; i++) {
            sum += arr[i];
        }
        if (sum % 2 == 1) {
            return 0;
        } else  {
            int target = sum / 2;
            vector<vector<int>> dp(N + 1, vector<int>(target + 1, -1));
            if (SubsetSum(arr, N, target, dp)) {
                return 1;
            }
        }
        return 0;
        // code here
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends