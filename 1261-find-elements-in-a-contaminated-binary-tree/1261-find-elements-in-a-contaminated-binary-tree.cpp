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
class FindElements {
public:
    void create(TreeNode *root, int val) {
        if (root != NULL) {
            root -> val = val;
            if (root -> left != NULL) {
                create(root -> left, val * 2 + 1);
            } 
            if (root -> right != NULL) {
                create(root -> right, val * 2 + 2);
            }
        }    
    }
    
    void print(TreeNode *root) {
        if (root != NULL) {
            cout<<root -> val<<endl;
            print(root -> left);
            print(root -> right);
        }
    }
    
    TreeNode *node;
    
    FindElements(TreeNode* root) {
        create(root, 0); 
        // print(root);
        node = root;
    }
    
    bool search(TreeNode *node, int target) {
        if (node != NULL) {
            if (node -> val == target) {
                return true;
            } 
            return search(node -> left, target) || search(node -> right, target);
        }
        return false;
    }
    
    bool find(int target) {
        return search(node, target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */