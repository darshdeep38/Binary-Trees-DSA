class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long, int> prefixSumCount;
        prefixSumCount[0] = 1;  // Base case: one way to have a sum of 0

        return dfs(root, 0, targetSum, prefixSumCount);
    }

private:
    int dfs(TreeNode* node, long currentSum, int targetSum, unordered_map<long, int>& prefixSumCount) {
        if (!node) return 0;

        currentSum += node->val;
        int numPathsToCurr = prefixSumCount[currentSum - targetSum];

        // Update the map with the currentSum so that the child nodes can use it
        prefixSumCount[currentSum]++;

        int result = numPathsToCurr
                   + dfs(node->left, currentSum, targetSum, prefixSumCount)
                   + dfs(node->right, currentSum, targetSum, prefixSumCount);

        // Backtrack: remove currentSum from the map so it won't affect other branches
        prefixSumCount[currentSum]--;

        return result;
    }
};
