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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int>>> mp;
        queue<pair<TreeNode*, pair<int, int>>> q; // {node, {row, col}}
        vector<vector<int>> res;

        if(root==nullptr){
            return res;
        }

        q.push({root,{0,0}});
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            TreeNode * curr = it.first;
            int row = it.second.first;
            int col = it.second.second;

            mp[col][row].push_back(curr->val);

            if(curr->left!=nullptr){
                q.push({curr->left, {row+1, col-1}});
            }
            if(curr->right!=nullptr){
                q.push({curr->right, {row+1, col+1}});
            }

            
        }

        for(auto& colPair : mp){
            vector<int> colVals;
            for(auto& rowPair: colPair.second){
                sort(rowPair.second.begin(), rowPair.second.end());
                colVals.insert(colVals.end(), rowPair.second.begin(), rowPair.second.end());
            }
            res.push_back(colVals);
        }

        return res;
    }
};