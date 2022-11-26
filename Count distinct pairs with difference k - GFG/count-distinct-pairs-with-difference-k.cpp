//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int TotalPairs(vector<int>nums, int k){
	    unordered_map<int, int> track;
	    for (int i = 0; i < nums.size(); i++) {
	        track[nums[i]] += 1; 
	    }
	    if (k == 0) {
	        int cnt = 0;
	        for (auto pr : track) {
	            if (pr.second - 1 > 0) {
	                cnt++;
	            }
	        }
	        return cnt;
	    }
	    int cnt = 0;
	    for (auto pr : track) {
	        if (track.find(pr.first + k) != track.end()) {
	            cnt += 1;
	        }    
	    }
	    
	    return cnt; 
	    // Code here
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
		cin >> n >> k;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.TotalPairs(nums, k);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends