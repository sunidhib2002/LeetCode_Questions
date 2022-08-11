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
    void Traversal(vector<int> &Inorder, TreeNode *root) {
        if (root != NULL) {
            Traversal(Inorder, root -> left);
            Inorder.push_back(root -> val);
            Traversal(Inorder, root -> right);
        }
    }
    
    bool IsStrictlyIncreasing(vector<int> inorder) {
        for (int i = 1; i < inorder.size(); i++) {
            if (inorder[i - 1] == inorder[i]) {
                return false;
            }
        }
        return true;
    }
    
    bool isValidBST(TreeNode* root) {
        vector<int> Inorder;
        Traversal(Inorder, root);
        vector<int> ans = Inorder;
        if (!IsStrictlyIncreasing(Inorder)) {
            return false;
        }
        sort(ans.begin(), ans.end());
        if (ans == Inorder) {
            return true;
        } else {
            return false;
        }
    }
};