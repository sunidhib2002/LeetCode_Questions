class Solution {
public:
    void Filter(vector<int> index, vector<vector<int>>& restaurants, int maxPrice, int maxDistance, priority_queue<pair<int, int>> &ans) {
        for (int i = 0; i < index.size(); i++) {
            // cout<<index[i]<<endl;
            if (restaurants[index[i]][3] <= maxPrice && restaurants[index[i]][4] <= maxDistance) {
                ans.push({restaurants[index[i]][1], restaurants[index[i]][0]});
            }
        }
    }
    
    vector<int> convert2Vec(priority_queue<pair<int, int>> pq) {
        vector<int> answer;
        while (!pq.empty()) {
            answer.push_back(pq.top().second);
            pq.pop();
        }
        return answer;
    }
    
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<int> index;
        priority_queue<pair<int, int>> pq;
        if (veganFriendly == 1) {
            for (int i = 0; i < restaurants.size(); i++) {
                if (restaurants[i][2] == 1) {
                    index.push_back(i);
                }
            }
            Filter(index, restaurants, maxPrice, maxDistance, pq);
        } else {
            for (int i = 0; i < restaurants.size(); i++) {
                index.push_back(i);
            }
            Filter(index, restaurants, maxPrice, maxDistance, pq);
        }
        return convert2Vec(pq);
    }
};