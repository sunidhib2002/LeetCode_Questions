class Solution {
public:

    int findJudge(int n, vector<vector<int>>& trust) { 
        vector<int> inDegree(n + 1, 0);
        vector<int> outDegree(n + 1, 0);
        
        for (int i = 0; i < trust.size(); i++) {
            int node1 = trust[i][0];
            int node2 = trust[i][1];
            inDegree[node2]++;
            outDegree[node1]++;
        }
        
        for (int i = 1; i <= n; i++) {
            if (outDegree[i] == 0 && inDegree[i] == n - 1) {
                return i;
            }
        }
    
        return -1;
    }
};