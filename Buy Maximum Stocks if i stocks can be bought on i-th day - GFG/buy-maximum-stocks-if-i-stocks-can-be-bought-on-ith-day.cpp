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
        int cnt = 0;
        sort(stock.begin(), stock.end());
        for (int i = 0; i < stock.size(); i++) {
            // cout<<stock[i].first<<endl;
            int val = k / stock[i].first;
            // cout<<"val "<<val<<endl;
            if (val >= stock[i].second) {
                cnt += stock[i].second;
                k -= (stock[i].first * stock[i].second);
            } else {
                cnt += val;
                k -= (stock[i].first * val);
            }
            // cout<<k<<" "<<cnt<<endl;
        }
        return cnt;
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