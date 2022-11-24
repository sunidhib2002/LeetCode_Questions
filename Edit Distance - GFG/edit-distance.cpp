//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int edit(string s, string t, int x, int y, vector<vector<int>> &dp) {
        if (x == 0) {
            return y;
        }
        if (y == 0) {
            return x;
        }
        if (dp[x][y] != -1) {
            return dp[x][y];
        }
        
        if (s[x - 1] == t[y - 1]) {
            return dp[x][y] = edit(s, t, x - 1, y - 1, dp);
        } else {
            return dp[x][y] = 1 + min(edit(s, t, x - 1, y - 1, dp), min(edit(s, t, x, y - 1, dp), edit(s, t, x - 1, y, dp)));
        }
    }
    
    int editDistance(string s, string t) {
        // Code here
        vector<vector<int>> dp(s.length() + 1, vector<int> (t.length() + 1, -1));
        return edit(s, t, s.length(), t.length(), dp);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends