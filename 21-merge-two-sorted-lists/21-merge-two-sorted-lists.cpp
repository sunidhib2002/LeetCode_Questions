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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *list3 = NULL;
        ListNode *curr1 = list1;
        ListNode *curr2 = list2;
        ListNode *curr3 = list3;
        while (curr1 != NULL && curr2 != NULL) {
            if (curr1 -> val <= curr2 -> val) {
                if (list3 == NULL) {
                    list3 = new ListNode(curr1 -> val);
                    curr3 = list3;
                } else {
                    curr3 -> next = new ListNode(curr1 -> val);
                    curr3 = curr3 -> next;
                }
                curr1 = curr1 -> next;
            } else if (curr1 -> val > curr2 -> val) {
                if (list3 == NULL) {
                    list3 = new ListNode(curr2 -> val);
                    curr3 = list3;
                } else {
                    curr3 -> next = new ListNode(curr2 -> val);
                    curr3 = curr3 -> next;
                }
                curr2 = curr2 -> next;
            }
        }
        
        while (curr1 != NULL) {
            if (list3 == NULL) {
                list3 = new ListNode(curr1 -> val);
                curr3 = list3;
            } else {
                curr3 -> next = new ListNode(curr1 -> val);
                curr3 = curr3 -> next;
            }
            curr1 = curr1 -> next;
        }
        
        while (curr2 != NULL) {
            if (list3 == NULL) {
                list3 = new ListNode(curr2 -> val);
                curr3 = list3;
            } else {
                curr3 -> next = new ListNode(curr2 -> val);
                curr3 = curr3 -> next;
            }
            curr2 = curr2 -> next;
        }
        
        return list3;
    }
};