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
    int goodNodes(TreeNode* root) {
        int cnt = 0;
        recurse(root, cnt, -101);
        return cnt;
    }

    void recurse(TreeNode* node, int& cnt, int max_val) {
        if (node == nullptr) {
            return;
        }

        if (node->val >= max_val) {
            cnt++;
        }
        
        max_val = max(node->val, max_val);
        recurse(node->left, cnt, max_val);
        recurse(node->right, cnt, max_val);
    }
};
