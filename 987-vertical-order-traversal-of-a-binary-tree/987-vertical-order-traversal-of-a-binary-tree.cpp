/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> SetValues(vector<int> vec, vector<int> s) {
        vector<int> ans = vec;
        for (auto it = s.begin(); it != s.end(); it++) {
            ans.push_back(*it);
        }
        return ans;
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<int>> tracker;
        map<pair<int,int>, vector<int>> m;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        vector<vector<int>> ans;
        int cnt = 0;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode *node = q.front().first;
                int level = q.front().second;
                q.pop();
                if (node -> left != NULL) {
                    q.push({node -> left, level - 1});
                } 
                if (node -> right != NULL) {
                    q.push({node -> right, level + 1});
                }
                m[{cnt, level}].push_back(node -> val);
                // tracker[level].push_back(node -> val);
            }
            cnt++;
        }
        
        for (auto pr : m) {
            sort(pr.second.begin(), pr.second.end());
            tracker[pr.first.second] = SetValues(tracker[pr.first.second], pr.second);
        }
        
        for (auto pr : tracker) {
            ans.push_back(pr.second);
        }
        
        return ans;
    }
};