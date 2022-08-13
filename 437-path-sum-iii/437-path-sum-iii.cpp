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
    void Traversal(TreeNode *root, long long targetSum, int &cnt, bool prev) {
        if (root != NULL) {
            // cout<<root -> val<<" "<<targetSum<<" "<<cnt<<endl;
            if (targetSum == (root -> val)) {
                cnt++;
            }
            Traversal(root -> left, targetSum - (root -> val), cnt, true);
            Traversal(root -> right, targetSum - (root -> val), cnt, true);
            if (prev == false) {
                Traversal(root -> left, targetSum, cnt, false);
                Traversal(root -> right, targetSum, cnt, false);
            }
        }
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        int cnt = 0;
        Traversal(root, targetSum, cnt, false);
        return cnt;
    }
};