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
        vector<int> res;
        recurse(root, res, 0);
        return res;
    }

    void recurse(TreeNode* node, vector<int>& res, int level) {
        if (node == nullptr) {
            return;
        }

        if (res.size() <= level) {
            res.push_back(node->val);
        }

        recurse(node->right, res, level+1);
        recurse(node->left, res, level+1);
    }
};
