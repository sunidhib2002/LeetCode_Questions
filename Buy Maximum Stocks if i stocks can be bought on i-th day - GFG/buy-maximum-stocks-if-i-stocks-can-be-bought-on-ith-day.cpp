//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]){
        //Write your code here
        vector<pair<int, int>> stock;
        for (int i = 0; i < n; i++) {
            stock.push_back({price[i], i + 1});
        }
        sort(stock.begin(), stock.end());
        int total = 0;
        for (int i = 0; i < stock.size(); i++) {
            int val = k / stock[i].first;
            if (val > stock[i].second) {
                total += stock[i].second;
                k -= (stock[i].first * stock[i].second);
            } else {
                total += val;
                k -= (stock[i].first * val);
            }
        }
        return total;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends