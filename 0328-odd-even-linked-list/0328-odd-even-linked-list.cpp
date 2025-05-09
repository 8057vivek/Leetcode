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
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }

        ListNode * curr = head;

        vector<ListNode*> oddNodes;
        vector<ListNode*> evenNodes;
        int index = 1;

        while(curr){
            if(index%2==1){
                oddNodes.push_back(curr);
            }else{
                evenNodes.push_back(curr);
            }
            curr = curr->next;
            index++;
        }

        for(int i=0;i<oddNodes.size()-1;i++){
            oddNodes[i]->next = oddNodes[i+1];
        }

        for(int i=0;i<evenNodes.size()-1;i++){
            evenNodes[i]->next = evenNodes[i+1];
        }


        oddNodes.back()->next = evenNodes.empty()?nullptr:evenNodes[0];

        if (!evenNodes.empty())
            evenNodes.back()->next = nullptr;

        return oddNodes[0];

    }
};