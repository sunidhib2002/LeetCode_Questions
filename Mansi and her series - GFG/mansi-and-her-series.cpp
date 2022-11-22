//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
  bool isPrime(int n){if(n<=1)return false;if(n<=3)return true;if(n%2==0 || n%3==0 )return false;for(int i=5;i*i<=n;i=i+6){if(n%i==0 || n%(i+2)==0)return false;}return true;}

    int nthTerm(int n){
       int count=1;
	int ans=0;
	for(int i=2;count<=n;i++){
		if(isPrime(i)){
			count++;
			ans=i;
		}


	}
	return (ans+1)*n;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n;
        cin >> n;
        Solution ob;
        cout<<ob.nthTerm(n)<<endl;
    }
    return 0;
}

// } Driver Code Ends