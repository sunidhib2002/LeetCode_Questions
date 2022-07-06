// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    
    // bool Find(stack<int> s, int target) {
    //     while (!s.empty()) {
    //         if (target == s.top()) {
    //             return true;
    //         } 
    //         s.pop();
    //     }
    //     return false;
    // }
    
    bool dfs(int node, vector<int> adj[], vector<int> &visited, unordered_map<int, int> &m) {

        visited[node] = 1;
        //s.push(node);
        m[node];
        vector<int> neighbors = adj[node];
        for (int i = 0; i < neighbors.size(); i++) {
            if (visited[neighbors[i]] == 1 && m.find(neighbors[i]) != m.end()) {
                return true;
            } else if (visited[neighbors[i]] == 0) {
                if (dfs(neighbors[i], adj, visited, m)) {
                    return true;
                }
            }
        }
        
        m.erase(node);
        //s.pop();
        return false;
    }
    
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> visited(V, 0);
        //stack<int> s;
        unordered_map<int, int> m;
        for (int i = 0; i < V; i++) {
            if (visited[i] == 0) {
                if (dfs(i, adj, visited, m)) {
                    return true;
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends