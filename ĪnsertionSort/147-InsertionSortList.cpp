//Optimized version of the code
// TC = O(n²) worst case, O(n) best case
// SC = O(1)
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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy=new ListNode(0);

        while(head){
            ListNode* next=head->next;
            ListNode* temp=dummy;

            while(temp->next && temp->next->val<head->val){
                temp=temp->next;
            }
            head->next=temp->next;
            temp->next=head;
            head=next;
        }

        return dummy->next;
    }
};