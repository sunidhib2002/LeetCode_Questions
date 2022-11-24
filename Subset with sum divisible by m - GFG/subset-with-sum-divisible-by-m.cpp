//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
        int findSubset(vector<int> &nums, int m, int i, int score) {
            if(i == nums.size()){
                if(score && score % m == 0){
                    return true ;
                }
                return false ;
            }
            
            return findSubset(nums, m, i + 1, score + nums[i]) || findSubset(nums, m, i + 1, score);
        }
        
		int DivisibleByM(vector<int>nums, int m){
		    // Code here
		    return findSubset(nums, m, 0, 0);
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		int ans  = ob.DivisibleByM(nums, m);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends