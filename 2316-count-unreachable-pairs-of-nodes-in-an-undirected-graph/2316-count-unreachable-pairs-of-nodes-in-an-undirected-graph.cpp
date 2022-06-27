class Solution {
public:
    void dfs(int node, vector<int> &visited, unordered_map<int, vector<int>> &adjList, long long &cnt) {
        visited[node] = 1;
        cnt += 1;
        vector<int> ngb = adjList[node];
        for (int i = 0; i < ngb.size(); i++) {
            if (visited[ngb[i]] == 0) {
                dfs(ngb[i], visited, adjList, cnt);
            }
        }
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        // if (edges.size() == 0) {
        //     long long int pro1 = n * n;
        //     long long int pro2 = (n * (n + 1)) / 2;
        //     long long int ans = pro1 - pro2;
        //     return ans;
        // }
        unordered_map<int, vector<int>> adjList;
        
        for (int i = 0; i < n; i++) {
            adjList[i];
        }
        for (int i = 0; i < edges.size(); i++) {
            int node1 = edges[i][0];
            int node2 = edges[i][1];
            adjList[node1].push_back(node2);
            adjList[node2].push_back(node1);
        }
    
        vector<long long> unReachable;
        vector<int> visited(n, 0);
        
        for (int i = 0; i < n; i++) {
            if  (visited[i] == 0) {
                long long cnt = 0;
                dfs(i, visited, adjList, cnt);
                unReachable.push_back(cnt);
            }
        }
        
        long long ans = 0;
        long long prefixSum = 0;
        for (int i = 0; i < unReachable.size(); i++) {
            long long int pro1 = (unReachable[i] * 1LL * (n - unReachable[i]));
            long long int pro2 = prefixSum * 1LL * unReachable[i];
            ans += pro1 - pro2;
            prefixSum += unReachable[i];
        }
        
        return ans;
    }
};