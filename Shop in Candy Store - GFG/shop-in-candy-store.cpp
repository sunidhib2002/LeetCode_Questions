//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        sort(candies, candies + N);
        int left = 0;
        int right = N - 1;
        int mn = 0;
        int mx = 0;
        while (left <= right) {
            mn += candies[left++];
            right -= K;
        }
        left = 0;
        right = N - 1;
        while (left <= right) {
            mx += candies[right--];
            left += K;
        }
        vector<int> ans;
        ans.push_back(mn);
        ans.push_back(mx);
        return ans;
        // Write Your Code here
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends