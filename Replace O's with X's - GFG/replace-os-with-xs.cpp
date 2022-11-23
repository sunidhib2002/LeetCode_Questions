//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void dfs(int row, int col, vector<vector<char>> &mat, int n, int m, vector<vector<int>> &visited) {
        if (row < 0 || row >= n || col < 0 || col >= m) {
            return;
        }
        
        if (visited[row][col] == 1) {
            return;
        }
        
        visited[row][col] = 1;
        
        if (mat[row][col] == 'O') {
            mat[row][col] = '*';
        }
        
        if (mat[row][col] == 'X') {
            return;
        }
        
        dfs(row + 1, col, mat, n, m, visited);
        dfs(row, col + 1, mat, n, m, visited);
        dfs(row - 1, col, mat, n, m, visited);
        dfs(row, col - 1, mat, n, m, visited);
        
    }
    
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // first row
        for (int i = 0; i < m; i++) {
            if (mat[0][i] == 'O') {
                // cout<<"first row "<<i<<endl;
                vector<vector<int>> visited(n, vector<int>(m, 0));
                dfs(0, i, mat, n, m, visited);
            }
        }
        
        for (int i = 0; i < m; i++) {
            if (mat[n - 1][i] == 'O') {
                // cout<<"last row "<<i<<endl;
                vector<vector<int>> visited(n, vector<int>(m, 0));
                dfs(n - 1, i, mat, n, m, visited);
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (mat[i][0] == 'O') {
                // cout<<"first col "<<i<<endl;
                vector<vector<int>> visited(n, vector<int>(m, 0));
                dfs(i, 0, mat, n, m, visited);
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (mat[i][m - 1] == 'O') {
                // cout<<"last col "<<i<<endl;
                vector<vector<int>> visited(n, vector<int>(m, 0));
                dfs(i, m - 1, mat, n, m, visited);
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 'O') {
                    mat[i][j] = 'X';
                }
            }
        } 
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == '*') {
                    mat[i][j] = 'O';
                }
            }
        } 
        
        return mat;
        // code here
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends