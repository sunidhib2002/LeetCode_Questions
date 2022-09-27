/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode(-1);
        ListNode *curr = head;
        
        while (curr != NULL && curr -> next != NULL && curr -> next -> next != NULL) {
            if (curr == head && curr -> val == curr -> next -> val) {
                while (curr != NULL && curr -> next != NULL && curr -> val == curr -> next -> val) {
                    curr = curr -> next;
                }
                head = curr -> next;
                curr = head;
            } else if (curr -> next -> val == curr -> next -> next -> val) {
                ListNode *temp = curr;
                while (curr != NULL && curr -> next != NULL && curr -> next -> next != NULL && curr -> next -> val == curr -> next -> next -> val) {
                    curr = curr -> next;
                }
                if (curr -> next == NULL) {
                    temp -> next = NULL;   
                } else {
                    temp -> next = curr -> next -> next;
                }
                curr = temp;
            } else {
                curr = curr -> next;
            }
        }
        if (head == NULL || (head != NULL && head -> next == NULL)) {
            return head;
        } else if (head != NULL && head -> next != NULL && head -> next -> next == NULL) {
            if (head -> val == head -> next -> val) {
                head = NULL;
            }  
        }
        
        return head; 
    }
};