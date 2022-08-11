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
    void Traversal(int level, map<int, int> &nodes, TreeNode *root) {
        if (root != NULL) {
            if (nodes.find(level) == nodes.end()) {
                nodes[level] = root -> val;
            } 
            Traversal(level + 1, nodes, root -> right);
            Traversal(level + 1, nodes, root -> left);
        }
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        map<int, int> nodes;
        Traversal(0, nodes, root);
        for (auto pr : nodes) {
            ans.push_back(pr.second);
        }
        return ans;
    }
};