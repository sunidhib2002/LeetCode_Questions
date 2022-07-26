/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void Root2Node(TreeNode *root, TreeNode *node, vector<int> &path) {
        if (root != NULL) {
            path.push_back(root -> val);
            if (root == node) {
                return;
            } else {
                if (root -> val > node -> val) {
                    Root2Node(root -> left, node, path);    
                } else {
                    Root2Node(root -> right, node, path);    
                }    
            }
        }
    }
    
    TreeNode *findNode(TreeNode *root, int commonNode) {
        if (root != NULL) {
            if (root -> val == commonNode) {
                return root;
            } else {
                if (root -> val > commonNode) {
                    return findNode(root -> left, commonNode);
                } else {
                    return findNode(root -> right, commonNode);
                }
            }
        } 
        return NULL;
    }
    
    void print(vector<int> path) {
        for (int i = 0; i < path.size(); i++) {
            cout<<path[i]<<" ";
        }
        cout<<endl;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<int> path1;
        Root2Node(root, p, path1);
        vector<int> path2;
        Root2Node(root, q, path2);
        int commonNode = 0;
        // print(path1);
        // print(path2);
        if (path1.size() <= path2.size()) {
            for (int i = 0; i < path1.size(); i++) {
                if (i == path1.size() - 1 && path1[i] == path2[i]) {
                    commonNode = path1[i];
                }
                if (path1[i] != path2[i]) {
                    if (i - 1 >= 0) {
                        commonNode = path1[i - 1];
                    } else {
                        commonNode = path1[0];
                    }
                    break;
                }
            } 
            
        } else {
           for (int i = 0; i < path2.size(); i++) {
                if (i == path2.size() - 1 && path1[i] == path2[i]) {
                    commonNode = path1[i];
                }
               if (path1[i] != path2[i]) {
                    if (i - 1 >= 0) {
                        commonNode = path2[i - 1];
                    } else {
                        commonNode = path1[0];
                    }
                    break;
                }
            }
        }
        //cout<<commonNode<<endl;
        return findNode(root, commonNode);
    }
};