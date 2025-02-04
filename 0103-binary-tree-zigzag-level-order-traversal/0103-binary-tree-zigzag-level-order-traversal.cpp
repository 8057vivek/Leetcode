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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }

        queue<TreeNode*> Q1;
        Q1.push(root);
        int levelNo =0;
        while (!Q1.empty()) {
            int levelSize = Q1.size();
             vector<int> currentLevel;
             

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
            if(levelNo%2!=0){
                reverse(currentLevel.begin(), currentLevel.end());
                result.push_back(currentLevel);
            }else{
            result.push_back(currentLevel);
            }
            levelNo++;
        }

        return result;
    }
    
};