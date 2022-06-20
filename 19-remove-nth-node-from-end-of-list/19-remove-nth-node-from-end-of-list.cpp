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
    int Length(ListNode *head) {
        int len = 0;
        ListNode* curr = head;
        while (curr != NULL) {
            len++;
            curr = curr -> next;
        }
        return len;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       if (head -> next == NULL && n == 1) {
            return NULL;
        }
        
        int len = Length(head);
        int offset = len - n;
        
        if (offset == 0) {
            return head -> next;
        }
        ListNode *curr = head;
        while (offset - 1 != 0 && curr != NULL) {
            curr = curr -> next;
            offset--;
        }
        if (curr -> next != NULL) {
            curr -> next = curr -> next -> next;
        } else {
            curr -> next = NULL;
        }
        return head;
    }
};