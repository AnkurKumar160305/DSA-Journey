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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt=0;
        ListNode* temp=head;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }

        if(cnt==n){
            ListNode* v=head;
            head=head->next;
            delete v;
            return head;
        }

        temp=head;
        for(int i=0;i<cnt-n-1;i++){
            temp=temp->next;
        }

        ListNode* toDelete=temp->next;
        temp->next=temp->next->next;

        delete toDelete;
        return head;

    }
};

//Optimal Approach: Two Pointer Approach
//Time Complexity: O(N)
//Space Complexity: O(1)
// We create a gap of n nodes between fast and slow.
// That way, when fast reaches the end, slow is exactly n nodes behind it → right before the target node.
// We add 1 extra step because we want slow to stop at the node before the one we delete.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* slow=dummy; 
        ListNode* fast=dummy; 
        for(int i=0;i<=n;i++){
            fast=fast->next;
        }
        while(fast){
            fast=fast->next;
            slow=slow->next;
        }
        ListNode* toDelete=slow->next;
        slow->next=slow->next->next;
        delete toDelete;
        return dummy->next;

    }
};