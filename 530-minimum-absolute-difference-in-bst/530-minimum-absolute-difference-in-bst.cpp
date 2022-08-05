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
    void Traversal(vector<int> &diff, TreeNode *root) {
        if (root != NULL) {
            Traversal(diff, root -> left);
            diff.push_back(root -> val);
            Traversal(diff, root -> right);
        }
    }
    
    int getMinimumDifference(TreeNode* root) {
        int mn = INT_MAX;
        vector<int> diff;
        Traversal(diff, root);
        for (int i = 1; i < diff.size(); i++) {
            mn = min(mn, diff[i] - diff[i - 1]);
        }
        return mn;
    }
};