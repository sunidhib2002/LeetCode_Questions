//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    vector<pair<int, int>> pr;
	    for (int i = 0; i < nums.size(); i++) {
	        pr.push_back({nums[i], i});
	    }
	    sort(pr.begin(), pr.end());
	    int cnt = 0;
	    for (int i = 0; i < nums.size(); i++) {
	        if (i == pr[i].second) {
	            continue;
	        } else {
	            cnt++;
	            swap(pr[i], pr[pr[i].second]);
	            i--;
	        }
	    }
	   // cnt /= 2;
	    return cnt;
	    // Code here
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends