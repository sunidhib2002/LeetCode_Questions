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
    void LevelOrderTraversal(TreeNode *root, int &mxSum, int &level) {
        queue<TreeNode *> q;
        q.push(root);
        int lvl = 1;
        while (!q.empty()) {
            int n = q.size();
            int sum = 0;
            for (int i = 0; i < n; i++) {
                TreeNode *node = q.front();
                q.pop();
                if (node -> left != NULL) {
                    q.push(node -> left);
                }
                if (node -> right != NULL) {
                    q.push(node -> right);
                }
                sum += node -> val;
            }
            if (mxSum < sum) {
                mxSum = sum;
                level = lvl;
            }
            lvl += 1;
        } 
    }
    
    int maxLevelSum(TreeNode* root) {
        int mxSum = INT_MIN;
        int level = 0;
        LevelOrderTraversal(root, mxSum, level);
        return level;
    }
};