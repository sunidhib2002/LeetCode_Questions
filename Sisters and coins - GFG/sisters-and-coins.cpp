//{ Driver Code Starts

#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution{
public: 

    bool SubsetSum(vector<int> set, int n, int sum, vector<vector<int>> &dp)
    {
        if (sum == 0)
            return true;
        if (n == 0)
            return false;
        
        if (dp[n - 1][sum] != -1) {
            return dp[n - 1][sum];
        }
            
        if (set[n - 1] > sum)
            return dp[n - 1][sum] = SubsetSum(set, n - 1, sum, dp);
      
        return dp[n - 1][sum] = SubsetSum(set, n - 1, sum, dp) || SubsetSum(set, n - 1, sum - set[n - 1], dp);
    }
    
    int sisterCoin(int arr[], int n, int m){
        // Code Here
        int sum = 0;
        vector<int> nums;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            nums.push_back(arr[i]);
        }
        nums.push_back(m);
        sum += m;
        // cout<<sum<<endl;
        if (sum % 2 == 1) {
            return 0;
        } else {
            int target = (sum / 2);
            int t = nums.size();
            vector<vector<int>> dp(t + 1, vector<int>(sum + 1, -1));
            if (SubsetSum(nums, t, target, dp)) {
                return 1;
            }
        }
        return 0;
    }
};


//{ Driver Code Starts.

int main()
{
    Solution ob;
	int t;
	cin >> t;
	while(t--){
	    int n, m;
	    cin >> n >> m;
	    int a[n];
	    for(int i = 0; i < n; ++i){
	        cin >> a[i];
	    }
	    cout << ob.sisterCoin(a, n, m) << endl;
	    
	}
	return 0;
}
// } Driver Code Ends