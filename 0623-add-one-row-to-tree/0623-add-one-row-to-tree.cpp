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
    TreeNode* addRow(TreeNode* root, int val, int currentDepth, int depth) {
        if (root == nullptr) return nullptr;

        if (currentDepth == depth - 1) {
            // Create new nodes
            TreeNode* newLeft = new TreeNode(val);
            TreeNode* newRight = new TreeNode(val);

            // Attach original left and right to new nodes
            newLeft->left = root->left;
            newRight->right = root->right;

            // Connect new nodes to current root
            root->left = newLeft;
            root->right = newRight;
        } else {
            // Recurse to the next level
            addRow(root->left, val, currentDepth + 1, depth);
            addRow(root->right, val, currentDepth + 1, depth);
        }

        return root;
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        // Special case: insert at root
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        return addRow(root, val, 1, depth);
    }
};
