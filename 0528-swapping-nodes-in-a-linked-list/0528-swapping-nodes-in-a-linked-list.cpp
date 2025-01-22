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

    ListNode* swapNodes(ListNode* head, int k) {
        
        int first = head->val;
        int count = 1;
        ListNode * current = new ListNode();
        current = head;
        while(current->next!=nullptr){
            count++;
            current = current->next;
            if(count==k){
                first = current->val;
            }
        }
        ListNode * current1 = new ListNode();
        current1 = head;

        int limit = count-k+1;
        int last = 0;
        while(limit>1){
            current1 = current1->next;
            limit--;
        }
        last = current1->val;
        current1->val = first;

        ListNode * current2 = new ListNode();
        current2 = head;
        int i = 1;
        while(i<k){
            i++;
            current2 = current2->next;
            
        }
        current2->val = last;

        return head;

    }
};