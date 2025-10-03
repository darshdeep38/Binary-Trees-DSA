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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        // Special case: if depth is 1, create a new root
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        queue<TreeNode*> q;
        q.push(root);
        int currentDepth = 1;

        while (!q.empty()) {
            int size = q.size();

            if (currentDepth == depth - 1) {
                for (int i = 0; i < size; ++i) {
                    TreeNode* node = q.front(); q.pop();

                    // Ensure node is not nullptr
                    if (!node) continue;

                    TreeNode* originalLeft = node->left;
                    TreeNode* originalRight = node->right;

                    // Allocate new nodes safely
                    TreeNode* newLeft = new TreeNode(val);
                    TreeNode* newRight = new TreeNode(val);

                    // Reassign children
                    newLeft->left = originalLeft;
                    newRight->right = originalRight;

                    node->left = newLeft;
                    node->right = newRight;
                }
                break;  // Done inserting
            }

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front(); q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            currentDepth++;
        }

        return root;
    }
};

