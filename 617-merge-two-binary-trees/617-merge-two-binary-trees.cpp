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
    TreeNode *merge(TreeNode *root1, TreeNode *root2, TreeNode *root3) {
        if (root1 != NULL || root2 != NULL) {
            if (root3 == NULL) {
                if (root1 != NULL && root2 != NULL) {
                    root3 = new TreeNode(root1 -> val + root2 -> val);
                } else if (root1 != NULL && root2 == NULL) {
                    root3 = new TreeNode(root1 -> val);
                } else if (root2 != NULL && root1 == NULL) {
                    root3 = new TreeNode(root2 -> val);
                } else {
                    return NULL;
                }
                if (root3 != NULL) {
                    if (root1 == NULL) {
                        root3 -> left = merge(NULL, root2 -> left, root3 -> left);
                        root3 -> right = merge(NULL, root2 -> right, root3 -> right);
                    } else if (root2 == NULL) {
                        root3 -> left = merge(root1 -> left, NULL, root3 -> left);
                        root3 -> right = merge(root1 -> right, NULL, root3 -> right);
                    } else {
                        root3 -> left = merge(root1 -> left, root2 -> left, root3 -> left);
                        root3 -> right = merge(root1 -> right, root2 -> right, root3 -> right);    
                    }
                }
            }
        }    
        return root3;
    }
    
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        TreeNode *root3 = NULL;
        return merge(root1, root2, root3);
    }
};