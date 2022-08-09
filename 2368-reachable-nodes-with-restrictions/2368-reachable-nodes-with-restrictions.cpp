class Solution {
public:
    bool NotRestricted(vector<int> &vec, int target) {
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i] == target) {
                return false;
            }
        }
        return true;
    }
    
    void BFS(int node, unordered_map<int, vector<int>> &adjList, vector<int> visited, int &cnt) {
        visited[node] = 1;
        queue<int> q;
        q.push(node);
        while (!q.empty()) {
            int val = q.front();
            q.pop();
            vector<int> neighbors = adjList[val];
            for (int i = 0; i < neighbors.size(); i++) {
                if (visited[neighbors[i]] == 0) {
                    q.push(neighbors[i]);
                    visited[neighbors[i]] = 1;
                    cnt++;    
                }
            }
        }
    }
    
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        int cnt = 0;
        unordered_map<int, vector<int>> adjList;
        unordered_map<int, int> Restricted; 
        for (int i = 0; i < restricted.size(); i++) {
            Restricted[restricted[i]]++;
        }
        for (int i = 0; i < edges.size(); i++) {
            int node1 = edges[i][0];
            int node2 = edges[i][1];
            if (Restricted.find(node1) == Restricted.end() && Restricted.find(node2) == Restricted.end()) {
                adjList[node1].push_back(node2);
                adjList[node2].push_back(node1);
            }
        }
        
        // for (auto pr : adjList) {
        //     cout<<pr.first<<" : ";
        //     for (int i = 0; i < pr.second.size(); i++) {
        //         cout<<pr.second[i]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        vector<int> visited(n, 0);
        BFS(0, adjList, visited, cnt);
        
        return (cnt + 1);
    }
};