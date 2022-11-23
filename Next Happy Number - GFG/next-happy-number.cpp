//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int findSum(int n, unordered_map<int, int> &visited) {
        if (n == 1) {
            return 1;
        }
        
        if (visited.find(n) != visited.end()) {
            return -1;
        }
        
        visited[n] = 1;
        int num = 0;
        while (n > 0) {
            int rem = n % 10;
            num += rem * rem;
            n /= 10;
        }
        
        return findSum(num, visited);
    }
    
    int nextHappy(int N){
        int temp = N + 1;
        while (true) {
            unordered_map<int, int> visited;
            if (findSum(temp, visited) == 1) {
                return temp;
            }
            temp++;
        }
        return 0;
        // code here
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends