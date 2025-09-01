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
    vector<vector<int>> result;
    if(!root) return result;


    queue <TreeNode* > q;
    q.push(root);

    while(!q.empty()){
        vector<int> level;         // To store values of this level
    int levelSize = q.size();      // Number of nodes at current level
    for( int i = 0 ; i< levelSize ; i++){
        TreeNode * node = q.front();
        q.pop();
        level.push_back(node->val);     // Store node's value

        if(node->left) q.push(node->left);  // Enqueue left child
        if(node->right) q.push(node->right); // Enqueue right child

    }
    result.push_back(level);       // Add this level to result

    }
    return result;
        
    }
};
