// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an ndirected graph.
    bool dfs(int node, vector<int> adj[], vector<int> &visited, int parent) {
        visited[node] = 1;
        vector<int> neighbors = adj[node];
        for (int i = 0; i < neighbors.size(); i++) {
            if (neighbors[i] != parent && visited[neighbors[i]] == 1) {
                return true;
            } else if (neighbors[i] != parent && visited[neighbors[i]] == 0) {
                if (dfs(neighbors[i], adj, visited, node)) {
                    return true;
                } 
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> visited(V, 0);
        for (int i = 0; i < V; i++) {
            if (visited[i] == 0) {
                bool ans = dfs(i, adj, visited, -1);
                if (ans) {
                    return ans;
                }
            }
        }
        // Code here
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends