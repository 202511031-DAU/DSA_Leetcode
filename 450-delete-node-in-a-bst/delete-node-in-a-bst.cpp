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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 * };
 */

class Solution {
public:

    TreeNode* findMin(TreeNode* root) {

        while(root->left != NULL) {
            root = root->left;
        }

        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {

        if(root == NULL)
            return NULL;

        // Search for node
        if(key < root->val) {

            root->left =
                deleteNode(root->left, key);
        }

        else if(key > root->val) {

            root->right =
                deleteNode(root->right, key);
        }

        else {

            // Case 1: No child
            if(root->left == NULL &&
               root->right == NULL) {

                delete root;
                return NULL;
            }

            // Case 2: Only right child
            if(root->left == NULL) {

                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            // Case 2: Only left child
            if(root->right == NULL) {

                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Case 3: Two children

            TreeNode* successor =
                findMin(root->right);

            root->val = successor->val;

            root->right =
                deleteNode(root->right,
                           successor->val);
        }

        return root;
    }
};