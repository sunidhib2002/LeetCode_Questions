//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        vector<char> vec1;
        vector<char> vec2;
        for (int i = 0; i < n; i++) {
            if (str[i] >= 'a' && str[i] <= 'z') {
                vec1.push_back(str[i]);
            } else {
                vec2.push_back(str[i]);
            }
        }
        sort(vec1.begin(), vec1.end());
        sort(vec2.begin(), vec2.end());
        string s = "";
        int j = 0;
        int k = 0;
        for (int i = 0; i < n; i++) {
            if (str[i] >= 'a' && str[i] <= 'z') {
                s += vec1[j++];
            } else {
                s += vec2[k++];
            }
        }
        return s;
        // your code here
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends