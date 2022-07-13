class Solution {
public:
    int mn(vector<int> ans) {
        int a = INT_MIN;
        for (int i = 1; i < ans.size(); i++) {
            a = max(a, ans[i]);
        }
        return a;
    }
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> ans(n + 1, INT_MAX);
        
        unordered_map<int, vector<pair<int, int>>> adj;
        for (int i = 0; i < times.size(); i++) {
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        
        // for (auto pr : adj) {
        //     cout<<pr.first<<" : ";
        //     for (int i = 0; i < pr.second.size(); i++) {
        //         cout<<pr.second[i].first<<" "<<pr.second[i].second<<endl;
        //     }
        //     cout<<endl;
        // }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        ans[k] = 0;
        while (!pq.empty()) {
            int dist = pq.top().first;
            int prev = pq.top().second;
            pq.pop();
            
            vector<pair<int, int>> neighbors = adj[prev];
            for (int i = 0; i < neighbors.size(); i++) {
                int next = neighbors[i].first;
                int nextDist = neighbors[i].second;
                if (ans[next] > ans[prev] + nextDist) {
                    ans[next] = ans[prev] + nextDist;
                    pq.push({ans[next], next}); 
                }
            }
        }
        
        // for (int i = 0; i < ans.size(); i++) {
        //     cout<<ans[i]<<" ";
        // }
        // cout<<endl;
        
        if (mn(ans) == INT_MAX) {
            return -1;
        }
        return mn(ans);
    }
};