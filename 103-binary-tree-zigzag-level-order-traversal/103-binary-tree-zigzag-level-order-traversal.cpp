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
    void levelOrder(TreeNode *root, vector<vector<int>> &ans, int level) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            vector<int> vec;
            for (int i = 0; i < n; i++) {
                TreeNode *node = q.front();
                q.pop();
                if (node -> left != NULL) {
                    q.push(node -> left);
                } 
                if (node -> right != NULL) {
                    q.push(node -> right);
                }    
                vec.push_back(node -> val);
            }
            if (level % 2 == 1) {
                reverse(vec.begin(), vec.end());
            }
            ans.push_back(vec);
            level += 1;
        }
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) {
            return ans;
        }
        levelOrder(root, ans, 0);
        return ans;
    }
};