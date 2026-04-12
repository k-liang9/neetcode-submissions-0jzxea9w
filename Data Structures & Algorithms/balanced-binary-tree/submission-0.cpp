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
    bool isBalanced(TreeNode* root) {
        function<int(TreeNode*)> dfs = [&](TreeNode* node) -> int {
            if (node == nullptr) {
                return 0;
            }
            
            int lheight = dfs(node->left);
            int rheight = dfs(node->right);

            if (lheight == -1 || rheight == -1) {
                return -1;
            }

            if (abs(lheight - rheight) > 1) {
                return -1;
            } else {
                return 1 + max(lheight, rheight);
            }
        };

        return dfs(root) != -1;
    }
};
