//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void findPrimeSignature(int n, vector<int> &vec) {
        if (n % 2 == 0) {
            int cnt = 0;
            while (n % 2 == 0) {
                n /= 2;
                cnt++;
            }
            vec.push_back(cnt);
        }
        for (int i = 3; i * i <= n; i += 2) {
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
    }
    
    vector<int> orderedPrime(int n){
        vector<int> signature;
        findPrimeSignature(n, signature);
        sort(signature.begin(), signature.end());
        int total = 1;
        for (int i = 0; i < signature.size(); i++) {
            total *= (signature[i] + 1);
        }
        
        signature.push_back(total);
        return signature;
        // code here
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<int> ans = ob.orderedPrime(n);
        for(int i = 0;i < ans.size()-1;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
        cout<<ans[ans.size()-1]<<"\n";
    }
    return 0;
}
// } Driver Code Ends