class Solution {

private:
int dfs(TreeNode* node , int currentSum){
if (!node) return 0 ;

currentSum = currentSum * 10 + node ->val;

if(!node->left && !node->right){  //  when leaf node is encountered
    return currentSum ;
}

// Recursive call to left and right children
return dfs(node->left , currentSum) + dfs(node->right , currentSum);

    }
public:
    int sumNumbers(TreeNode* root) {
         return dfs(root, 0);
    }
};
