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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> indices;
        for (int i = 0; i < inorder.size(); i++) {
            indices[inorder[i]] = i;
        }

        int pre_idx = 0;
        function<TreeNode*(int, int)> dfs = [&](int l, int r) -> TreeNode* {
            if (l > r) {
                return nullptr;
            }
            int val = preorder[pre_idx++];
            TreeNode* node = new TreeNode(val);
            int mid_idx = indices[val];
            node->left = dfs(l, mid_idx-1);
            node->right = dfs(mid_idx+1, r);

            return node;
        };

        return dfs(0, preorder.size()-1);
    }
};
