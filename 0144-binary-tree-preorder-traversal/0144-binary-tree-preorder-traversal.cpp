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
 vector<int> preorderTraversal(TreeNode* root) {
        vector<int> vec1;
        recursion(root, vec1);
        return vec1;
    }

private:
    void preorderHelper(TreeNode* root, vector<int>& vec1) {
        if (root == nullptr) {
            return;
        }
        vec1.push_back(root->val);         // Visit the root node
        preorderHelper(root->left, vec1);  // Traverse the left subtree
        preorderHelper(root->right, vec1); // Traverse the right subtree
    }

    void recursion(TreeNode * root, vector<int>& vec){
        if(root==nullptr){
            return;
        }
        stack<TreeNode *> s1;
        s1.push(root);
        while(!s1.empty()){
            TreeNode * curr = s1.top();
            vec.push_back(curr->val);
            s1.pop();

            if(curr->right){
                s1.push(curr->right);
            }
            if(curr->left){
                s1.push(curr->left);
            }
        }
    }
};