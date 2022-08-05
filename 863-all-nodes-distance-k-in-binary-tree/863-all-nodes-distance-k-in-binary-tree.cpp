/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void Traversal(TreeNode *root, unordered_map<int, TreeNode*> &parentTracker, unordered_map<TreeNode*, bool> &visited) {
        if (root != NULL) {
            queue<TreeNode *> q;
            q.push(root);
            while (!q.empty()) {
                TreeNode *node = q.front();
                q.pop();
                visited[node] = false;
                if (node -> left != NULL) {
                    q.push(node -> left);
                    parentTracker[node -> left -> val] = node;
                } 
                if (node -> right != NULL) {
                    q.push(node -> right);
                    parentTracker[node -> right -> val] = node;
                }
            }
        }
    }
    
    void LevelOrder(TreeNode *target, unordered_map<int, TreeNode*> parentTracker, int dist, vector<int> &ans, unordered_map<TreeNode*, bool> visited, int k) {
        queue<TreeNode *> q;
        q.push(target);
        visited[target] = true;
        while (!q.empty()) {
            if (dist == k) {
                break;
            }
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode *node = q.front();
                q.pop();
                //cout<<dist<<" "<<node -> val<<endl;
                if (node -> left != NULL && visited[node -> left] == false) {
                    //cout<<node -> left -> val<<endl;
                    q.push(node -> left);
                    visited[node -> left] = true;
                } 
                if (node -> right != NULL && visited[node -> right] == false) {
                    //cout<<node -> right -> val<<endl;
                    q.push(node -> right);
                    visited[node -> right] = true;
                }
                if (parentTracker.find(node -> val) != parentTracker.end() && parentTracker[node -> val] != NULL && visited[parentTracker[node -> val]] == false) {
                    //cout<<parentTracker[node -> val] -> val<<endl;
                    q.push(parentTracker[node -> val]);
                    visited[parentTracker[node -> val]] = true;
                }
            }
            dist++;
        }
        
        while (!q.empty()) {
            ans.push_back(q.front() -> val);
            q.pop();
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        unordered_map<TreeNode*, bool> visited;
        unordered_map<int, TreeNode*> parentTracker;
        Traversal(root, parentTracker, visited);
        int dist = 0;
        LevelOrder(target, parentTracker, dist, ans, visited, k);
        return ans;
    }
};