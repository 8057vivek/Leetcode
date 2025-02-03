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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vec1;
        recursion(root,vec1);
        return vec1;

    }
    void helper(TreeNode * root, vector<int>& vec1){
        if(root==nullptr){
            return;
        }
        helper(root->left,vec1);
        vec1.push_back(root->val);
        helper(root->right, vec1);
    }
    void recursion(TreeNode * root, vector<int>& vec){
        if(root==nullptr){
            return;
        }
        stack<TreeNode * > st;
        while(!st.empty() || root){
            if(root){
                st.push(root);
                root=root->left;
            }else{
                TreeNode * curr = st.top();
                st.pop();
                vec.push_back(curr->val);
                root = curr->right;
            }
        }
    }
    
};