class Solution {
public:
    bool isPath(int source, int destination, unordered_map<int, vector<int>> &adj) {
        vector<int> ngb = adj[source];
        for (int i = 0; i < ngb.size(); i++) {
            if (ngb[i] == destination) {
                return true;
            }
        }
        return false;
    }
    
    int findJudge(int n, vector<vector<int>>& trust) {    
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < trust.size(); i++) {
            int node1 = trust[i][0];
            int node2 = trust[i][1];
            adj[node1].push_back(node2);
        }
        
        vector<int> possible_town_judges;
        for (int i = 1; i <= n; i++) {
            if (adj.find(i) == adj.end()) {
                possible_town_judges.push_back(i);
            }
        }
        
        int town_judge = -1;
        for (int j = 0; j < possible_town_judges.size(); j++) {
            int val = possible_town_judges[j];
            town_judge = val;
            for (int i = 1; i <= n; i++) {
                if (i != val && isPath(i, val, adj) == false) {
                    town_judge = -1;
                    break;
                }
            }
        }
        
        return town_judge;
    }
};