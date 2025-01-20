/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // bool isfound(TreeNode* root, int val){
    //     if(val==root->val){
    //         return true;
    //     }

    //     if(val<root->val){
    //         isfound(root->left,val);
    //     }else{
    //         isfound(root->right,val);
    //     }

    //     return false;
    // }
    TreeNode* searchBST(TreeNode* root, int value) {

        if (root == NULL || value == root->val) {
        return root;
        }

        if(value<root->val){
            return searchBST(root->left,value);
        }
        else{
            return searchBST(root->right,value);
        }

        return NULL;
    }
};