//Better Approach
//Time Complexity: O(n+m)
//Space Complexity: O(n+m)
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
        vector<int> ans;
        while(list1 && list2){
            if(list1->val<=list2->val){
                ans.push_back(list1->val);
                list1=list1->next;
            }else{
                ans.push_back(list2->val);
                list2=list2->next;
            }
        }

        while(list1){
            ans.push_back(list1->val);
            list1=list1->next;
        }
        while(list2){
            ans.push_back(list2->val);
            list2=list2->next;
        }
        ListNode* dummy=new ListNode(0);
        ListNode* temp=dummy;

        for(int i=0;i<ans.size();i++){
            ListNode* newnode=new ListNode(ans[i]);
            temp->next=newnode;
            temp=newnode;
        }

        return dummy->next;
    }
};




//Optimal
// TC = O(n + m) where n and m are the lengths of the two lists
// SC = O(1) if we don't consider the output list
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
        ListNode* dummy=new ListNode(0);
        ListNode* temp=dummy;


        while(list1 && list2){
            if(list1->val<=list2->val){
                temp->next=list1;
                list1=list1->next;
            }else{
                temp->next=list2;
                list2=list2->next;
            }
            temp=temp->next;
        }


        while(list1){
            temp->next=list1;
            list1=list1->next;
            temp=temp->next;
        }
        while(list2){
            temp->next=list2;
            list2=list2->next;
            temp=temp->next;
        }


        return dummy->next;
    }
};