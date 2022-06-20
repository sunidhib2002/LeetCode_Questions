/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node *merge(Node *curr, Node * NextNode) {
        Node *curr2 = curr;
        Node *tail = NULL;
        Node *temp = curr -> child;
        while (temp != NULL) {
            if (temp -> child != NULL) {
                temp = merge(temp, temp -> next);
            }
            curr2 -> next = temp;
            temp -> prev = curr2;
            if (temp -> next == NULL) {
                tail = temp;
            }
            temp = temp -> next;
            curr2 = curr2 -> next;
        }
        
        tail -> next = NextNode;
        if (NextNode != NULL) {
            NextNode -> prev = tail;
        } 
        curr -> child = NULL;
        return curr;
    }
    
    Node* flatten(Node* head) {
        Node *curr = head;
        while (curr != NULL) {
            if (curr -> child != NULL) {
                Node *NextNode = curr -> next;
                curr = merge(curr, NextNode);
                curr = NextNode;
            } else {
                curr = curr -> next;    
            }
        }
        return head;
    }
};