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
        ListNode * curr = new ListNode();
        curr = head;
        int count =1;
        while(curr->next!=nullptr){
            curr= curr->next;
             count++;
        }
        if(count==n){
            head = head->next;
            return head;
        }
        ListNode * curr2 = new ListNode();
        curr2 = head;
        int limit = count-n;
        while(limit>1 && curr2->next!=nullptr){
            limit--;
            curr2 = curr2->next;
        }
        if(curr2 != nullptr && curr2->next != nullptr){
            curr2->next = curr2->next->next;
        }
        
        
        return head;
    }
};