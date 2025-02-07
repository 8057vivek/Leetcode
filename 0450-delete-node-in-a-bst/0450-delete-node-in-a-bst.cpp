class Solution {
public:
    TreeNode* findMinNode(TreeNode* root) {
        while (root->left != nullptr) {
            root = root->left;
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int value) {
        if (root == nullptr) {
            return nullptr;
        }

        // If the value to be deleted is smaller, it lies in the left subtree
        if (value < root->val) {
            root->left = deleteNode(root->left, value);
        }
        // If the value to be deleted is greater, it lies in the right subtree
        else if (value > root->val) {
            root->right = deleteNode(root->right, value);
        }
        // Node to be deleted is found
        else {
            // Case 1: Node has no children (leaf node)
            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                return nullptr;
            }
            // Case 2: Node has only one child (right child exists)
            else if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            // Case 3: Node has only one child (left child exists)
            else if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            // Case 4: Node has two children
            else {
                TreeNode* temp = findMinNode(root->right); // Get inorder successor
                root->val = temp->val; // Copy the inorder successor's value
                root->right = deleteNode(root->right, temp->val); // Delete the inorder successor
            }
        }
        return root;
    }
};
