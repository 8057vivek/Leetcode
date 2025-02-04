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
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> result;
        if (root == nullptr) {
            return result;
        }

        std::queue<TreeNode*> Q1;
        Q1.push(root);

        while (!Q1.empty()) {
            int levelSize = Q1.size();
            std::vector<int> currentLevel;

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* curr = Q1.front();
                Q1.pop();
                currentLevel.push_back(curr->val);

                if (curr->left) {
                    Q1.push(curr->left);
                }
                if (curr->right) {
                    Q1.push(curr->right);
                }
            }

            result.push_back(currentLevel);
        }

        return result;
    }
};