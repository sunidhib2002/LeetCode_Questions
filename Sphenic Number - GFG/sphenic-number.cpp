//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
	public:
	void FindFactors(int n, vector<int> &vec) {
	    
	    if (n % 2 == 0) {
	        int cnt = 0;
	        while (n % 2 == 0) {
	            n /= 2;
	            cnt++;
	        }
	        vec.push_back(cnt);
	    }    
	    
	    for (int i = 3; i <= sqrt(n); i++) {
	        if (n % i == 0) {
	            int cnt = 0;
	            while (n % i == 0) {
	                n /= i;
	                cnt++;
	            }
	            vec.push_back(cnt);
	        }
	    }
	    
	    if (n > 2) {
	        vec.push_back(1);
	    }
	    
	   // return cnt;
	}
	
	int isSphenicNo(int N){
	    vector<int> vec;
	    FindFactors(N, vec);
	    if (vec.size() == 3) {
	        for (int i = 0; i < vec.size(); i++) {
	            if (vec[i] != 1) {
	                return false;
	            }
	        }
	        return true;
	    }
	   // cout<<count_factors<<endl;
	   // if (count_factors == 3) {
	   //     return true;
	   // }
	    return false;
	    // Code here
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.isSphenicNo(N);
		cout << ans <<"\n";
	}  
	return 0;
}
// } Driver Code Ends