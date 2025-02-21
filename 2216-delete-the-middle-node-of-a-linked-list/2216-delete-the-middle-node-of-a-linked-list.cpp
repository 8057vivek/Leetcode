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
    ListNode* deleteMiddle(ListNode* head) {

        if(head==nullptr || head->next==nullptr){
            return nullptr;
        }
        ListNode * curr = head;

        int count = 0;
        while(curr!=nullptr){
            count++;
            curr = curr->next;
        }
        
        ListNode * temp = head;

        int n = count/2;

        for (int i = 0; i < n - 1; i++) {
            temp = temp->next;
        }


        temp->next = temp->next->next;

        return head;

    }
};