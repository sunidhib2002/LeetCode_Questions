//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
	public:
		int countWays(int n, int m)
	{
	    int mod = 1000000007;
	    int count[n + 1];
	    count[0] = 0;
	    for (int i = 1; i <= n; i++) {
	        if (i > m) {
	            count[i] = ((count[i - 1] % mod) + (count[i - m] % mod)) % mod;
	        } else if (i == 1 || i < m) {
	            count[i] = 1;
	        } else {
	            count[i] = 2;
	        }
	    }
	    
	    return (count[n] % mod);
	    // Code here.
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.countWays(n, m);
		cout << ans <<"\n";
	}  
	return 0;
}
// } Driver Code Ends