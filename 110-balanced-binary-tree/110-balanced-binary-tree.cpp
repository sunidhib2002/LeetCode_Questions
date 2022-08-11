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
    int GetHeight(TreeNode *root, vector<int> &diff) {
        if (root == NULL) {
            return 0;
        }
        
        int left = GetHeight(root -> left, diff);
        int right = GetHeight(root -> right, diff);
        diff.push_back(abs(left - right));
        
        return 1 + max(left, right);
    }
    
    void print(vector<int> diff) {
        for (int i = 0; i < diff.size(); i++) {
            cout<<diff[i]<<" ";
        }
        cout<<endl;
    }
    
    bool isBalanced(TreeNode* root) {
        vector<int> diff;
        int height = GetHeight(root, diff);
        
        for (int i = 0; i < diff.size(); i++) {
            if (diff[i] > 1) {
                return false;
            }
        }
        //print(diff);
        return true;
    }
};