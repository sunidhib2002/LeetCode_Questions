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
    TreeNode *GetNode(TreeNode *root, int start) {
        if (root != NULL) {
            if (root -> val == start) {
                return root;
            }
            TreeNode *left = GetNode(root -> left, start);
            TreeNode *right = GetNode(root -> right, start);
            if (left != NULL) {
                return left;
            } else if (right != NULL) {
                return right;
            } else {
                return NULL;
            }
        }
        return NULL;
    }
    
    void Traversal(TreeNode* root, unordered_map<int, TreeNode *> &parentTracker) {
        if (root != NULL) {
            queue<TreeNode *> q;
            q.push(root);
            
            while (!q.empty()) {
                int n = q.size();
                for (int i = 0; i < n; i++) {
                    TreeNode *node = q.front();
                    q.pop();
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
    }
    
    void findTime(TreeNode *target, unordered_map<int, TreeNode *> &parentTracker, int &dist, unordered_map<TreeNode *, bool> &visited, TreeNode *root) {
        if (target != NULL) {
            queue<pair<TreeNode *, int>> q;
            q.push({target, 0});
            visited[target] = true;
            while (!q.empty()) {
                int n = q.size();
                for (int i = 0; i < n; i++) {
                    TreeNode *node = q.front().first;
                    int d = q.front().second;
                    visited[node] = true;
                    q.pop();
                    if (node -> left == NULL && node -> right == NULL) {
                        dist = max(dist, d);
                    }
                    if (node == root) {
                        dist = max(dist, d);
                    }
                    if (visited[node -> left] == false && node -> left != NULL) {
                        q.push({node -> left, d + 1});
                    } 
                    if (visited[node -> right] == false && node -> right != NULL) {
                        q.push({node -> right, d + 1});
                    }
                    if (parentTracker.find(node -> val) != parentTracker.end() && visited[parentTracker[node -> val]] == false) {
                        q.push({parentTracker[node -> val], d + 1});
                    }
                }
            }
            
        }
    }
    
    int amountOfTime(TreeNode* root, int start) {
        TreeNode *target = GetNode(root, start);
        unordered_map<int, TreeNode*> parentTracker;
        Traversal(root, parentTracker);
        int dist = INT_MIN;
        unordered_map<TreeNode *, bool> visited;
        findTime(target, parentTracker, dist, visited, root);
        return dist;
    }
};