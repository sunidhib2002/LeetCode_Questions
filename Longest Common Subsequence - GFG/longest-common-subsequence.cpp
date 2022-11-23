//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    int LCS(int x, int y, string s1, string s2, vector<vector<int>> &dp) {
        if (x == 0 || y == 0) {
            return 0;
        }
        
        if (dp[x][y] != -1) {
            return dp[x][y];
        }
        
        if (s1[x - 1] == s2[y - 1]) {
            return dp[x][y] = 1 + LCS(x - 1, y - 1, s1, s2, dp); 
        } else {
            return dp[x][y] = max(LCS(x - 1, y, s1, s2, dp), LCS(x, y - 1, s1, s2, dp));    
        }
    }
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        vector<vector<int>> dp(x + 1, vector<int>(y + 1, -1));
        return LCS(x, y, s1, s2, dp);
        // your code here
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends