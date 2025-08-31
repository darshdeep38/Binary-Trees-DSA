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
    int findBottomLeftValue(TreeNode* root) {
        queue <TreeNode*> q;
        q.push(root);

        int bottomLeft = root-> val;
        while(!q.empty()){
            int levelSize = q.size();           //  Captures how many nodes are in the current level.
           bottomLeft = q.front()->val ;       // The first node in this level is the leftmost.


            for( int i = 0 ; i< levelSize ; i++){
                TreeNode* current = q.front();                 // Traverse each node in the level
                q.pop();

            if( current->left) q.push(current->left);          // Left is pushed first to maintain left-to-right order at each level.
            if(current -> right ) q.push(current->right);



            }
        }

        return bottomLeft;

    }
};
