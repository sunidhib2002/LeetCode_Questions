//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    struct activity {
        int begin;
        int finish;
    };
    
    bool static cmp(activity a, activity b) {
        return (a.finish < b.finish);
    }
    
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        activity arr[n];
        for (int i = 0; i < n; i++) {
            arr[i].begin = start[i];
            arr[i].finish = end[i];
        }
        sort(arr, arr + n, cmp);
        int j = 0;
        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i].begin > arr[j].finish) {
                j = i;
                cnt++;
            }
        }
        return cnt;
        // Your code here
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}

// } Driver Code Ends