/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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

bool dfs(ListNode* head, TreeNode* root) {
        // If list is completely matched
        if (!head) return true;

        // If tree ends or value doesn't match
        if (!root || root->val != head->val) return false;

        // Move to next list node and both left and right child
        return dfs(head->next, root->left) || dfs(head->next, root->right);
    }

public:
    bool isSubPath(ListNode* head, TreeNode* root) {  //This is the main function that checks every node in the tree as a potential starting point.


        if(!root) return false;
        //Try to match the linked list starting from the current root node using the dfs() function.
        //If the full list matches, return true.
        if(dfs(head , root)) return true;  

  return isSubPath(head, root->left) || isSubPath(head , root->right);
//If not matched at the current node, we try the left and right children of the current node.
//This way, we search every node in the binary tree as a potential starting point.

    }
};
