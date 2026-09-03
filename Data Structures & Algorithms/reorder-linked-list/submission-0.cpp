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
    ListNode* reverse (ListNode* head){
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    void merge(ListNode *l1, ListNode *l2){
        if(!l1 || !l2)return;

        ListNode *curr = l1;
        l1=l1->next;
        bool flag=0;
        while(l1 && l2){
            if(flag){
                curr->next=l1;
                l1 = l1->next;
                curr=curr->next;
                flag=!flag;
            }
            else {
                curr->next=l2;
                l2 = l2->next;
                curr=curr->next;
                flag=!flag;
            }
        }
        curr->next = l1 ? l1 : l2;
    }

    void reorderList(ListNode* head) {
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* second = slow->next;
        slow->next = nullptr;
        second = reverse(second);
        merge(head,second);
    }
};
