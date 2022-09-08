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
    void preorder(TreeNode *root, string &answer) {
        if (root != NULL) {
            // cout<<root -> val<<endl;
            answer += to_string(root -> val);
            if (root -> left != NULL) {
                answer += "(";
                preorder(root -> left, answer);
                answer += ")";
            } 
            if (root -> right != NULL) {
                if (root -> left == NULL) {
                    answer += "()";
                }
                answer += "(";
                preorder(root -> right, answer);
                answer += ")";
            }
        }    
    }
    
    string tree2str(TreeNode* root) {
        string answer = "";
        preorder(root, answer);
        return answer;
    }
};