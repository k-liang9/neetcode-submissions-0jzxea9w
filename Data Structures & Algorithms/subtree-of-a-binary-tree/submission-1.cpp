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
    bool recurse(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr && subRoot == nullptr) {
            return true;
        } else if ((root == nullptr && subRoot != nullptr) || (root != nullptr && subRoot == nullptr)) {
            return false;
        }

        if (root->val == subRoot->val) {
            return recurse(root->left, subRoot->left) && recurse(root->right, subRoot->right);
        } else {
            return false;
        }
    }

    void find_possible_roots(TreeNode* root, TreeNode* subRoot, vector<TreeNode*>& candidates) {
        if (root == nullptr) {
            return;
        }

        if (root->val == subRoot->val) {
            candidates.push_back(root);
        }

        find_possible_roots(root->left, subRoot, candidates);
        find_possible_roots(root->right, subRoot, candidates);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        vector<TreeNode*> candidates;
        find_possible_roots(root, subRoot, candidates);
        for (TreeNode* cand_root : candidates) {
            if (recurse(cand_root, subRoot)) {
                return true;
            }
        }
        return false;
    }
};
