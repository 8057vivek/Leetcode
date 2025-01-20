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
    TreeNode * insert(vector<int>&nums,int l,int r){

        if (l > r) return nullptr;
        
        int mid = (l + r) / 2;
        TreeNode* node = new TreeNode();
        node->val = nums[mid];
        node->left = insert(nums, l, mid - 1);
        node->right = insert(nums, mid + 1, r);
        
        return node;

    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // TreeNode * root = new TreeNode();
        int n = nums.size();
        int left = 0;
        int right = n-1;
        return insert(nums,left,right);
    }
};