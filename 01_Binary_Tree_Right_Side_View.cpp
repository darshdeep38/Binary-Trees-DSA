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
    vector<int> rightSideView(TreeNode* root) {

        vector<int> result;
        if(! root) return result;

        queue<TreeNode*> q;
        q.push(root);


        while(! q.empty()){            // we iterate over each level 
            int levelSize = q.size();   // number of nodes at current level 
            for( int i =  0 ; i< levelSize; i++ ){
                TreeNode* node = q.front();
                q.pop();

                if( i == levelSize -1 ){
                    result.push_back(node->val);                 // If it's the last node in this level, add to result

                }

                if( node-> left) q.push(node->left);              //  Eg :- The queue has 1. We dequeue 1 and enqueue 2 and 3 , and so on.
                if(node->right) q.push(node -> right);



            }
        }
        return result;
        
    }
};
