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
private:
    int sum = 0;

public:
    TreeNode* bstToGst(TreeNode* root) {
        if (root != nullptr) {
            bstToGst(root->right);        // Traverse right subtree
            sum += root->val;             // Update cumulative sum
            root->val = sum;              // Update node's value
            bstToGst(root->left);         // Traverse left subtree
        }
        return root;
    }
};
