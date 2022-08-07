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
        if (head == NULL) {
            return head;
        }
        
        if (head -> next == NULL) {
            return head;
        }
        
        ListNode *curr = head;
        
        // if (head != NULL && head -> next != NULL) {
        //     if (head -> val == head -> next -> val) {
        //         while (head != NULL && head -> next != NULL && head -> val == head -> next -> val) {
        //             head = head -> next;
        //         }
        //         if (head != NULL) {
        //             head = head -> next;
        //         }
        //     } 
        // }
        
        while (curr != NULL && curr -> next != NULL && curr -> next -> next != NULL) {
            if (curr == head && curr -> val == curr -> next -> val) {
                // cout<<"hello"<<endl;
                while (curr != NULL && curr -> next != NULL && curr -> val == curr -> next -> val) {
                    curr = curr -> next;
                }
                if (curr != NULL) {
                    head = curr -> next;
                    curr = head;
                }
            } else if (curr -> next -> val == curr -> next -> next -> val) {
                ListNode *start = curr;
                curr = curr -> next;
                while (curr != NULL && curr -> next != NULL && curr -> val == curr -> next -> val) {
                    curr = curr -> next;
                }
                start -> next = curr -> next;
                curr = start;
            } else {
                curr = curr -> next;
            }
        }
        
        if (head != NULL && head -> next != NULL) {
            if (head -> val == head -> next -> val) {
                while (head != NULL && head -> next != NULL && head -> val == head -> next -> val) {
                    head = head -> next;
                }
                if (head != NULL) {
                    head = head -> next;
                }
            } 
        }
        
        
        return head;  
    }
};