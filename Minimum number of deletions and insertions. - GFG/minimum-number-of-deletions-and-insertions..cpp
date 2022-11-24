//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int LCS(string str1, string str2, int x, int y, vector<vector<int>> &dp) {
	    if (x == 0 || y == 0) {
	        return 0;
	    }
	    
	    if (dp[x][y] != -1) {
	        return dp[x][y];
	    }
	    
	    if (str1[x - 1] == str2[y - 1]) {
	        return dp[x][y] = 1 + LCS(str1, str2, x - 1, y - 1, dp);
	    }
	    return dp[x][y] = max(LCS(str1, str2, x - 1, y, dp), LCS(str1, str2, x, y - 1, dp));
	}
	
	int minOperations(string str1, string str2) 
	{ 
	    vector<vector<int>> dp(str1.length() + 1, vector<int>(str2.length() + 1, -1));
	    int lcs = LCS(str1, str2, str1.length(), str2.length(), dp);
	    int diff1 = abs(str1.length() - lcs);
	    int diff2 = abs(str2.length() - lcs);
	    return (diff1 + diff2);
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
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends