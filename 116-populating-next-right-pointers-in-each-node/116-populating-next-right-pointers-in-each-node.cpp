/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void LevelOrderTraversal(Node *root) {
        if (root != NULL) {
            queue<Node *> q;
            q.push(root);
            
            while (!q.empty()) {
                int n = q.size();
                queue<Node *> newQ;
                for (int i = 0; i < n; i++) {
                    Node *node = q.front();
                    q.pop();
                    if (q.empty()) {
                        node -> next = NULL;
                    } else {
                        node -> next = q.front();
                    }
                    if (node -> left != NULL) {
                        newQ.push(node -> left);
                    }
                    if (node -> right != NULL) {
                        newQ.push(node -> right);
                    }
                }
                q = newQ;
            }
        }
    }
    
    Node* connect(Node* root) {
        LevelOrderTraversal(root);
        return root;
    }
};