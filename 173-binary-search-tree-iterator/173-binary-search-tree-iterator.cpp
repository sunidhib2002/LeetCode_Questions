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
class BSTIterator {
public:
    vector<int> Inorder;
    int smallestNum;
    int i = 0;
    void Traversal(TreeNode *root) {
        if (root != NULL) {
            Traversal(root -> left);
            Inorder.push_back(root -> val);
            Traversal(root -> right);
        }
    }
    
    BSTIterator(TreeNode* root) {
        Traversal(root);
        smallestNum = Inorder[0] - 1;
        root = new TreeNode(smallestNum);
    }
    
    int next() {
        if (i < Inorder.size()) {
            int val = Inorder[i];
            i++;
            return val;
        }
        return -1;
    }
    
    bool hasNext() {
        if (i < Inorder.size()) {
            return true;
        }
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */