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
    ListNode* oddEvenList(ListNode* head) {
        
        if (head == NULL) {
            return NULL;
        } 
        
        if (head -> next == NULL) {
            return head;
        } 
        
        ListNode *curr = head;
        int pos = 1;
        ListNode *newHead = NULL;
        ListNode *curr2 = NULL;
        
        while (curr != NULL) {
            if (pos % 2 == 1) {
                if (newHead == NULL) {
                    newHead = new ListNode(curr -> val);
                    curr2 = newHead;
                } else {
                    curr2 -> next = new ListNode(curr -> val);
                    curr2 = curr2 -> next;
                }
            }
            curr = curr -> next;
            pos++;
        }
        curr = head;
        pos = 1;
        while (curr != NULL) {
            if (pos % 2 == 0) {
                curr2 -> next = new ListNode(curr -> val);
                curr2 = curr2 -> next;
            }
            curr = curr -> next;
            pos++;
        }
        return newHead;
    }
};