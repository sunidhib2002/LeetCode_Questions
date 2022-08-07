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
    ListNode* sortList(ListNode* head) {
        vector<int> nums;
        ListNode *curr = head;
        while (curr != NULL) {
            nums.push_back(curr -> val);
            curr = curr -> next;
        }
        sort(nums.begin(), nums.end());
        ListNode* node = NULL;
        ListNode *curr2 = NULL;
        
        for (int i = 0; i < nums.size(); i++) {
            if (node == NULL) {
                node = new ListNode(nums[i]);
                curr2 = node; 
            } else {
                curr2 -> next = new ListNode(nums[i]);
                curr2 = curr2 -> next;
            }
        }
        
        return node;
    }
};