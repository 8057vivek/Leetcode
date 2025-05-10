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
        int length = 0;
        ListNode * pointer = head;

        while(pointer){
            length++;
            pointer = pointer->next;
        } 

        if(length==n){ // head/first node to be deleted
            return head->next;
        }

        pointer = head;
        for(int i=1;i<length-n;i++){
            pointer = pointer->next;
        }
        pointer->next = pointer->next->next;

        return head;
    }
};