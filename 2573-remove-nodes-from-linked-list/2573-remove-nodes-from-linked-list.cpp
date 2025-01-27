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
    ListNode* removeNodes(ListNode* head) {
        stack<int> st;
        ListNode * curr = new ListNode();
        curr = head;
        while(curr!=nullptr){
            st.push(curr->val);
            curr = curr->next;
        }
        ListNode * head2 = nullptr;

        int temp = INT_MIN;
        while(!st.empty()){
            if(st.top()>=temp){
            temp = st.top();
            ListNode * newNode = new ListNode(temp);
            newNode->next = head2;
            head2 = newNode;
            }
            st.pop();
        }

        return head2;
    }
};