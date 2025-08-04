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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* dummyNode = new ListNode(-1);
        ListNode* res = dummyNode;
        ListNode* temp1 = head;
        ListNode* temp2 = head->next;
        while (temp1 != NULL && temp2 != NULL) {
            res->next = temp2;
            temp1->next = temp2->next;
            temp2->next = temp1;
            res = temp1;
            temp1 = temp1->next;
            if (temp1 != NULL) {
                temp2 = temp1->next;
            }
        }
        return dummyNode->next;
    }
};