class Solution {
public:
    void dfs(unordered_map<int, vector<int>> &adj, vector<int> &visited, int node) {
        visited[node] = 1;
        vector<int> neighbor = adj[node];
        for (int i = 0; i < neighbor.size(); i++) {
            if (visited[neighbor[i]] == 0) {
                dfs(adj, visited, neighbor[i]);
            }
        }
    }
    
    int GetNeededCables(unordered_map<int, vector<int>> &adj, int n) {
        int cnt = 0;
        vector<int> visited(n, 0);
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                dfs(adj, visited, i);
                cnt++;
            }
        }
        return cnt;
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) {
            return -1;
        }
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < connections.size(); i++) {
            int node1 = connections[i][0];
            int node2 = connections[i][1];
            adj[node1].push_back(node2);
            adj[node2].push_back(node1);
        }
        
        int cableNeeded = GetNeededCables(adj, n) - 1;
        int total = connections.size();
        return cableNeeded;
    }
};