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
        if(!head->next)return nullptr;
        ListNode* nth = head;
        while(nth && n){
            n--;
            nth = nth->next;
        }

            if (!nth)
            return head->next;

        ListNode* slow=head;
        while(nth && nth->next){
            nth=nth->next;
            slow=slow->next;
        }

        
        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;
        

        return head;
    }
};
