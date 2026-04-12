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
    int diameterOfBinaryTree(TreeNode* root) {
        int longest = 0;

        function<int(TreeNode*)> diameter_at_node = [&](TreeNode* node) -> int {
            if (node == nullptr) {
                return 0;
            }

            int ldepth = diameter_at_node(node->left);
            int rdepth = diameter_at_node(node->right);

            longest = max(longest, ldepth + rdepth);

            return 1 + max(ldepth, rdepth);
        };

        (void)diameter_at_node(root);

        return longest;
    }
};
