//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        int left = 0;
        int right = 0;
        int mn = INT_MAX;
        int sum = 0;
        while (left <= right && right < n) {
            sum += arr[right];
            if  (sum > x) {
                mn = min(mn, right - left + 1);
                while (sum > x) {
                    sum -= arr[left];
                    left++;
                    if (sum > x) {
                        mn = min(mn, right - left + 1);    
                    }
                }
            }
            right++;
        }
        return mn;
        // Your code goes here   
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}
// } Driver Code Ends