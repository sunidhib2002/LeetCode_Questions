//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  int wineSelling(vector<int>& a){
      int buy = 0;
      int sell = 0;
      int n = a.size();
      int cnt = 0;
      for (int i = 0; i < n; i++) {
          if (a[i] > 0) {
              buy = i;
              break;
          }
      }
      for (int i = 0; i < n; i++) {
          if (a[i] < 0) {
              sell = i;
              break;
          }
      }
      while (buy < n && sell < n) {
          int val = min(abs(a[sell]), a[buy]);
          a[buy] -= val;
          a[sell] -= (-1) * val;
          cnt += val * abs(buy - sell);
          if (a[buy] == 0) {
              buy++;
              while (buy < n && a[buy] <= 0) {
                  buy++;
              }
          }
          if (a[sell] == 0) {
              sell++;
              while (sell < n && a[sell] >= 0) {
                  sell++;
              }
          }
      }
      return cnt;   
      //Code here.
  }
};



//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        Solution ob;
        int ans = ob.wineSelling(a);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends