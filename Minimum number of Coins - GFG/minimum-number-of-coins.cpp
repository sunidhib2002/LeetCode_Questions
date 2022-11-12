//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int N)
    {
        vector<int> coins = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
        int i = 0;
        vector<int> ans;
        while (N > 0) {
            if (coins[i] > N) {
                i++;
            }  else {
                int cnt = N / coins[i];
                while (cnt > 0) {
                    ans.push_back(coins[i]);
                    cnt -= 1;
                }
                N %= coins[i];
            }
        }
        return ans;
        // code here
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends