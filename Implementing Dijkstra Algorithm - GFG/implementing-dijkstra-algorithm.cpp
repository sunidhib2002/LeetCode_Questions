// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> answer(V, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, S});
        answer[S] = 0;
        while (!pq.empty()) {
            int prev = pq.top().second;
            int dist = pq.top().first;
            pq.pop();
            
            vector<vector<int>> neighbors = adj[prev];
            for (int i = 0; i < neighbors.size(); i++) {
                int nextNode = neighbors[i][0];
                int nextDist = neighbors[i][1];
                if (answer[nextNode] > answer[prev] + nextDist) {
                    answer[nextNode] = answer[prev] + nextDist;
                    pq.push({answer[nextNode], nextNode});
                }
            }
        }
        
        return answer;
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends