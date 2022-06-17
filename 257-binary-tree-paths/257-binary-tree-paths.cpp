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
    void DFS(TreeNode *root, vector<vector<int>> &ans, vector<int> path) {
        if (root != NULL && root -> left == NULL && root -> right == NULL) {
            path.push_back(root -> val);
            ans.push_back(path);
            path.pop_back();
        } else if (root != NULL) {
            path.push_back(root -> val);
            DFS(root -> left, ans, path);
            DFS(root -> right, ans, path);
            path.pop_back();
        }
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> answer;
        vector<vector<int>> ans;
        vector<int> path;
        DFS(root, ans, path);
        for (int i = 0; i < ans.size(); i++) {
            string paths = "";
            for (int j = 0; j < ans[i].size(); j++) {
                if (j + 1 == ans[i].size()) {
                    paths += to_string(ans[i][j]);
                } else {
                    paths += to_string(ans[i][j]) + "->";
                }
            }
            answer.push_back(paths);
        }
        return answer;
    }
};