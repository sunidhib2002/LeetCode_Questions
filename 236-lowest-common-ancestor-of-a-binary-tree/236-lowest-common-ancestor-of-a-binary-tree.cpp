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
    void root2NodePath(TreeNode *root, TreeNode *node, vector<int> &path, int &flag) {
        if (root != NULL) {
            path.push_back(root -> val);
            if (root == node) {
                flag = 1;
                return;
            } else {
                root2NodePath(root -> left, node, path, flag);
                if (flag == 1) {
                    return;
                } else {
                    if (root -> val != path[path.size() - 1]) {
                        path.pop_back();
                    }
                }
                root2NodePath(root -> right, node, path, flag);
                if (flag == 1) {
                    return;
                } else {
                    if (root -> val != path[path.size() - 1]) {
                        path.pop_back();
                    }
                }
            }
        }
    }
    
    TreeNode *findNode(TreeNode *root, int commonNode) {
        if (root != NULL) {
            if (root -> val == commonNode) {
                return root;
            } else {
                TreeNode *left = findNode(root -> left, commonNode);
                TreeNode *right = findNode(root -> right, commonNode);
                if (left != NULL) {
                    return left;
                } 
                if (right != NULL) {
                    return right; 
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
        vector<int> path2;
        int flag = 0;
        root2NodePath(root, p, path1, flag);
        flag = 0;
        root2NodePath(root, q, path2, flag);
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
        // cout<<commonNode<<endl;
        return findNode(root, commonNode);
    }
};